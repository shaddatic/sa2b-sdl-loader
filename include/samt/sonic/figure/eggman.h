/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/sonic/figure/eggman.h'
*
*   ~~ Under Construction ~~
*   ---
*/
#ifndef _SA2B_FIGURE_EGGMAN_H_
#define _SA2B_FIGURE_EGGMAN_H_

/************************/
/*  Includes            */
/************************/
#include <samt/ninja/njcommon.h>

#include <samt/sonic/player.h>

/************************/
/*  Structures          */
/************************/
#define GET_EGGMANWK(_tp)    ((EGGMANWK*)(_tp)->awp)

typedef struct eggmanwk
{
    playerwk     pw;
    int16_t      unktimer;  // Unused timer
    NJS_TEXLIST* pTexList;
    PL_OBJECT*   pObject;
    PL_MOTION*   pMotion;
}
EGGMANWK;

/************************/
/*  Data                */
/************************/
#define EggmanWorkPointer       DATA_REF(EGGMANWK* , 0x01A51D28)

#define mtx_EggmanBase          DATA_REF(NJS_MATRIX, 0x01A51CF8)

/************************/
/*  Functions           */
/************************/
EXTERN_START
void    EggmanMotionCallBack(NJS_CNK_OBJECT* cnkobj);

EXTERN_END

/************************/
/*  Function Ptrs       */
/************************/
#ifdef  SAMT_INCL_FUNCPTRS
/** Function ptrs **/
#   define EggmanMotionCallBack_p           FUNC_PTR(void, __cdecl, (NJS_CNK_OBJECT*), 0x0073EAD0)

#endif/*SAMT_INCL_FUNCPTRS*/

#endif/*_SA2B_FIGURE_EGGMAN_H_*/
