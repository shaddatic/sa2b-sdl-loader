/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/sonic/figure/knuckles.h'
*
*   ~~ Under Construction ~~
*   Contains functions, structs, and data for Knuckles
*/
#ifndef _SA2B_FIGURE_KNUCKLES_H_
#define _SA2B_FIGURE_KNUCKLES_H_

/************************/
/*  Includes            */
/************************/
#include <samt/ninja/njcommon.h>

#include <samt/sonic/player.h>

/************************/
/*  Structures          */
/************************/
#define GET_KNUCKLESWK(_tp)     ((KNUCKLESWK*)tp->awp)

typedef struct knuckleswk
{
    playerwk pw;

    char field_308[76];
    signed __int16 someAng2;
    signed __int16 someAng0;
    signed __int16 someAng1;
    __int16 chaos0_texid;
    int someAnimationIndex;
    char field_3B0[4];
    float someFlt;
    Angle someHeadAng;
    char field_3C0[36];
    PLAYER_OBJECT* pObjectData0;
    PLAYER_OBJECT* pObjectData1;
    PLAYER_OBJECT* pObjectData2;
    NJS_TEXLIST* TextureList;
    NJS_TEXLIST* EffectTextureList;
    PL_OBJECT* ModelList;
    PL_MOTION* MotionList;
    NJS_MOTION_LINK pMotionLink;
    char field_410[16];
}
KNUCKLESWK;

/************************/
/*  Data                */
/************************/
#define KnucklesWorkPointer     DATA_REF(KNUCKLESWK*, 0x01A51C88)

#define mtx_KnucklesBase        DATA_REF(NJS_MATRIX , 0x01A51BEC)
#define mtx_KnucklesHead        DATA_REF(NJS_MATRIX , 0x01A51CBC)
#define mtx_KnucklesBody        DATA_REF(NJS_MATRIX , 0x01A51B3C)
#define mtx_KnucklesHandL       DATA_REF(NJS_MATRIX , 0x01A51C58)
#define mtx_KnucklesHandR       DATA_REF(NJS_MATRIX , 0x01A51C8C)

/************************/
/*  Functions           */
/************************/
EXTERN_START
void    KnucklesMotionCallBack(NJS_CNK_OBJECT* cnkobj);

EXTERN_END

/************************/
/*  Function Ptrs       */
/************************/
#ifdef SAMT_INCL_FUNCPTRS
/** Function ptrs **/
#   define KnucklesMotionCallBack_p     FUNC_PTR(void, __cdecl, (NJS_CNK_OBJECT*), 0x0072EAA0)

#endif /* SAMT_INCL_FUNCPTRS */

#endif /* _SA2B_FIGURE_KNUCKLES_H_ */
