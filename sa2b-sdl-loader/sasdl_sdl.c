/********************************/
/*  Includes                    */
/********************************/
/****** Samt ************************************************************************************/
#include <samt/core.h>              /* core                                                     */
#include <samt/dlib.h>              /* dynamic lib                                              */
#include <samt/msgbox.h>            /* message box                                              */
#include <samt/string.h>

/****** Sasdl ***********************************************************************************/
#include <sasdl_core.h>             /* core                                                     */

/****** Self ************************************************************************************/
#include <sasdl_sdl.h>              /* self                                                     */

/********************************/
/*  Game Defs                   */
/********************************/
/****** Large Buffer ****************************************************************************/
#define GlobalBuffer                DATA_ARY(byte, 0x01DEFE20, [0x100000])

/********************************/
/*  Data                        */
/********************************/
/****** Sdl Functions ***************************************************************************/
mt_dlib* SdlLibraryP;

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
    if ( mtDlOpen("SDL2", DLIB_NOLOAD) )
    {
        mtMsgError(
            "SASDL : SDL2 Library Already Loaded",
            
            "The SDL2 library has been loaded by another unknown mod.\n\n"

            "To avoid a broken state, SASDL will now stop its Init process."
        );
        return SASDL_INIT_ALRLOADED;
    }

    c7* const    p_buf = GlobalBuffer;
    const isize ln_buf = COUNTOF(GlobalBuffer);

    mtStrFormat(p_buf, ln_buf, "%s/lib/SDL2.dll", mtGetModPath());

    mt_dlib* const p_sdl = mtDlOpen(p_buf, DLIB_NF);

    if ( !p_sdl )
    {
        mtMsgError(
            "SASDL : SDL2 Library Failed To Load",

            "SASDL was unable to load the SDL2 library at \"sasdl/lib/SDL2.dll\"; this is an unrecoverable error.\n\n"

            "The Init process will now stop."
        );
        return SASDL_INIT_NODLL;
    }

    ___Init      = mtDlSymbol(p_sdl, "SDL_Init");
    ___Quit      = mtDlSymbol(p_sdl, "SDL_Quit");
    ___PollEvent = mtDlSymbol(p_sdl, "SDL_PollEvent");

    SdlLibraryP = p_sdl;

    return 0;
}
