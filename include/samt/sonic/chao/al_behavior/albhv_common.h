/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/sonic/chao/al_behavior/albhv_common.h'
*
*   Description:
*       Contains functions related to the Chao common
*   behaviors.
*/
#ifndef _SA2B_CHAO_ALBVH_COMMON_H_
#define _SA2B_CHAO_ALBVH_COMMON_H_

/************************/
/*  Includes            */
/************************/
#include <samt/sonic/chao/al_behavior.h>

/************************/
/*  Functions           */
/************************/
EXTERN_START
int32_t ALBHV_Turn(       task* tp );
int32_t ALBHV_TurnRandom( task* tp );
int32_t ALBHV_GoToLockOn( task* tp );

EXTERN_END

/************************/
/*  Function Ptrs       */
/************************/
#ifdef  SAMT_INCL_FUNCPTRS
/** Behavior ptrs **/
#   define ALBHV_Turn_p             BHVFUNC_PTR(0x0056B740)
#   define ALBHV_TurnRandom_p       BHVFUNC_PTR(0x0056B960)
#   define ALBHV_GoToLockOn_p       BHVFUNC_PTR(0x0056BA80)

#endif/*SAMT_INCL_FUNCPTRS*/

#endif/*_SA2B_CHAO_ALBVH_COMMON_H_*/
