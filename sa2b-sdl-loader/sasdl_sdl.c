/********************************/
/*  Includes                    */
/********************************/
/****** Samt ************************************************************************************/
#include <samt/core.h>              /* core                                                     */
#include <samt/dll.h>               /* dll                                                      */
#include <samt/msgbox.h>            /* message box                                              */

/****** Sasdl ***********************************************************************************/
#include <sasdl_core.h>             /* core                                                     */

/****** Self ************************************************************************************/
#include <sasdl_sdl.h>              /* self                                                     */

/********************************/
/*  Data                        */
/********************************/
/****** Sdl Functions ***************************************************************************/
mt_dllhandle* SdlLibraryP;

/****** Sdl Functions ***************************************************************************/
static int (SDLCALL* ___Init)(int);
static void(SDLCALL* ___Quit)(void);
static int (SDLCALL* ___PollEvent)(SDL_Event*);

/********************************/
/*  Source                      */
/********************************/
/****** Sdl Export ******************************************************************************/
int SDLCALL
SDL_Init(Uint32 flags)
{
    return ___Init(flags);
}

void SDLCALL
SDL_Quit(void)
{
    ___Quit();
}

int SDLCALL
SDL_PollEvent(SDL_Event* event)
{
    return ___PollEvent(event);
}

/****** Init ************************************************************************************/
SASDL_INIT
SASDL_SimpleDirectMediaLayerInit(void)
{
    if ( mtDllGetMountedHandle("SDL2") )
    {
        mtMsgError(
            "SASDL : SDL2 Library Already Loaded",
            
            "The SDL2 library has been loaded by another unknown mod.\n\n"

            "To avoid a broken state, SASDL will now stop its Init process."
        );
        return SASDL_INIT_ALRLOADED;
    }

    mt_dllhandle* const p_sdlhdl = mtDllMount2(mtGetModPath(), "lib/SDL2.dll");

    if ( !p_sdlhdl )
    {
        mtMsgError(
            "SASDL : SDL2 Library Failed To Load",

            "SASDL was unable to load the SDL2 library at \"sasdl/lib/SDL2.dll\"; this is an unrecoverable error.\n\n"

            "The Init process will now stop."
        );
        return SASDL_INIT_NODLL;
    }

    ___Init      = mtDllGetExport(p_sdlhdl, "SDL_Init");
    ___Quit      = mtDllGetExport(p_sdlhdl, "SDL_Quit");
    ___PollEvent = mtDllGetExport(p_sdlhdl, "SDL_PollEvent");

    SdlLibraryP = p_sdlhdl;

    return 0;
}
