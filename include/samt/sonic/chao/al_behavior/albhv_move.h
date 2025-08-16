/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/sonic/chao/al_behavior/albhv_move.h'
*
*   Description:
*       Contains functions related to the Chao move behaviors.
*/
#ifndef _SA2B_CHAO_ALBVH_MOVE_H_
#define _SA2B_CHAO_ALBVH_MOVE_H_

/************************/
/*  Includes            */
/************************/
#include <samt/sonic/chao/al_behavior.h>

/************************/
/*  Functions           */
/************************/
EXTERN_START
int32_t ALBHV_Climb(        task* tp );
int32_t ALBHV_Glide(        task* tp );
int32_t ALBHV_NoticePlayer( task* tp );

EXTERN_END

/************************/
/*  Function Ptrs       */
/************************/
#ifdef  SAMT_INCL_FUNCPTRS
/** Behavior ptrs **/
#   define ALBHV_Climb_p            BHVFUNC_PTR(0x00562EB0)
#   define ALBHV_Glide_p            BHVFUNC_PTR(0x005630C0)
#   define ALBHV_NoticePlayer_p     BHVFUNC_PTR(0x005634D0)

#endif/*SAMT_INCL_FUNCPTRS*/

#endif/*_SA2B_CHAO_ALBVH_MOVE_H_*/
