/********************************/
/*  Includes                    */
/********************************/
/****** Samt ************************************************************************************/
#include <samt/core.h>              /* core                                                     */
#include <samt/init.h>              /* sysinit                                                  */
#include <samt/modloader.h>         /* modloader                                                */
#include <samt/modinfo.h>           /* modinfo                                                  */
#include <samt/memory.h>            /* mtrealloc                                                */
#include <samt/msgbox.h>            /* message box                                              */
#include <samt/writeop.h>           /* writecall                                                */

/****** Sasdl ***********************************************************************************/
#include <sasdl_core.h>             /* core                                                     */
#include <sasdl_sdl.h>              /* sdl                                                      */
#include <sasdlapi.h>               /* api                                                      */

/********************************/
/*  Forward Def                 */
/********************************/
/****** API Funcs *******************************************************************************/
static void     RegisterEventHandle( SASDL_EVRET(__cdecl* fnHandler)(const SDL_Event*) );
static void*    GetSdlHandle(void);

/********************************/
/*  Types                       */
/********************************/
/****** Init Func *******************************************************************************/
typedef s32 (__cdecl* FN_SDLINIT)(const SASDLAPI*, const c8*, const HelperFunctions*, usize);

/****** Event Func ******************************************************************************/
typedef SASDL_EVRET (__cdecl* FN_SDLEVENT)(const SDL_Event*);

/********************************/
/*  Data                        */
/********************************/
/****** API *************************************************************************************/
const SASDLAPI sasdlapi_core =
{
    .version = 0,

    .modver = { 1,0,0,0 },
    .sdlver = { 2,32,8 },

    .GetHandle = &GetSdlHandle,

    .RegisterEventHandler = &RegisterEventHandle,
};

/****** Event Handler ***************************************************************************/
static size         EventHandlerListNum;
static FN_SDLEVENT* EventHandlerListP;

/********************************/
/*  Source                      */
/********************************/
/****** API *************************************************************************************/
static u32
CallSdlInitFunctions(void)
{
    u32 out_flag = 0;

    const size nb_mod = miGetModCount();

    for (size i = 0; i < nb_mod; ++i)
    {
        const ml_modinfo* p_mi = miGetInfoByIndex(i);

        FN_SDLINIT const fn_init = miGetExport(p_mi, "SASDLAPI_Init");

        if ( fn_init )
        {
            out_flag = fn_init( &sasdlapi_core, p_mi->puPath, mtGetHelperFunctions(), i );
        }
    }

    return out_flag;
}

/****** API Funcs *******************************************************************************/
static void*
GetSdlHandle(void)
{
    return SdlLibraryP;
}

static void
RegisterEventHandle( SASDL_EVRET(__cdecl* fnHandler)(const SDL_Event*) )
{
    const size nb_handler = EventHandlerListNum;

    if ( !(nb_handler % 8) )
    {
        mtRealloc(&EventHandlerListP, FN_SDLEVENT*, nb_handler + 8);
    }

    EventHandlerListP[nb_handler] = fnHandler;

    EventHandlerListNum = nb_handler + 1;
}

/****** SDL Events ******************************************************************************/
static void
SASDL_PollEvents(void)
{
    const size        nb_handler  = EventHandlerListNum;
    FN_SDLEVENT* const p_handlers = EventHandlerListP;

    SDL_Event ev;

    while ( SDL_PollEvent(&ev) )
    {
        for ( size i = 0; i < nb_handler; ++i )
        {
            const SASDL_EVRET ret = p_handlers[i]( &ev );

            if ( ret == SASDL_EVRET_BREAK )
            {
                break;
            }
        }
    }
}

/****** Export Dll ******************************************************************************/
EXPORT_DLL
void
Init(const c8* puPath, const ml_helpfuncs* pHelpFuncs, usize ixMod)
{
    // samt init
    mtSystemInit(puPath, pHelpFuncs, ixMod);

    if ( !miCheckSupport() )
    {
        mtMsgError(
            "SASDL : Mod Loader Version",

            "SASDL requires Mod Loader version 9 or higher to function. Without it, other mods cannot access the API to use the SDL interface.\n\n"

            "The SDL library will not be loaded, and the Init process will now stop."
        );
        return;
    }

    if ( SASDL_SimpleDirectMediaLayerInit() != SASDL_INIT_OK )
    {
        return; // error messages handled internally
    }

    SDL_Init( CallSdlInitFunctions() );

    // event handlers
    WriteCall(0x00433EE9, SASDL_PollEvents);
}

EXPORT_DLL
void
OnExit(u32 code, s32 a1, s32 a2)
{
    SDL_Quit();
}
