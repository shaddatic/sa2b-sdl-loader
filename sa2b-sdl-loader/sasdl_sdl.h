/*
*   Sonic Adventure SDL - '/sasdl_sdl.h'
*
*   Description:
*     SDL sub-module header.
*/
#ifndef H_SASDL_SDL
#define H_SASDL_SDL

EXTERN_START

/********************************/
/*  Opaque Types                */
/********************************/
/****** DLL Handle ******************************************************************************/
typedef struct mt_dllhandle             mt_dllhandle; /* windows hmodule                        */

/********************************/
/*  Enums                       */
/********************************/
/****** SDL Init ********************************************************************************/
typedef enum
{
    SASDL_INIT_OK,                  /* init successful                                          */

    SASDL_INIT_ALRLOADED,           /* error, sdl already loaded by another mod                 */
    SASDL_INIT_NODLL,               /* error, sdl couldn't be loaded                            */
}
SASDL_INIT;

/********************************/
/*  Enums                       */
/********************************/
/****** SDL Init ********************************************************************************/
EXTERN mt_dllhandle* SdlLibraryP;   /* sdl library handle                                       */

/********************************/
/*  Prototypes                  */
/********************************/
/****** Init ************************************************************************************/
/*
*   Description:
*     Load and mount the SDL2 library from the 'lib' directory.
*
*   Returns:
*     'OK' on success; or a different error code on failure.
*/
SASDL_INIT SASDL_SimpleDirectMediaLayerInit( void );

EXTERN_END

#endif/*H_SASDL_SDL*/
