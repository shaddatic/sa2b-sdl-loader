/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/sonic/chao/al_behavior/albhv_thirsty.h'
*
*   Description:
*       Contains functions related to the Chao get-to-water behaviors.
*/
#ifndef _SA2B_CHAO_ALBVH_THIRSTY_H_
#define _SA2B_CHAO_ALBVH_THIRSTY_H_

/************************/
/*  Includes            */
/************************/
#include <samt/sonic/chao/al_behavior.h>

/************************/
/*  Functions           */
/************************/
EXTERN_START
int32_t ALBHV_JumpToPond( task* tp );

EXTERN_END

/************************/
/*  Function Ptrs       */
/************************/
#ifdef SAMT_INCL_FUNCPTRS
/** Behavior ptrs **/
#   define ALBHV_JumpToPond_p       BHVFUNC_PTR(0x005A0F40)

#endif/*SAMT_INCL_FUNCPTRS*/

#endif/*_SA2B_CHAO_ALBVH_THIRSTY_H_*/
