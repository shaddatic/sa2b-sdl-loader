/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/sonic/chao/al_behavior/albhv_dakko.h'
*
*   Description:
*       Contains functions related to the Chao dakko (hug)
*   behaviors.
*/
#ifndef _SA2B_CHAO_ALBVH_DAKKO_H_
#define _SA2B_CHAO_ALBVH_DAKKO_H_

/************************/
/*  Includes            */
/************************/
#include <samt/sonic/chao/al_behavior.h>

/************************/
/*  Functions           */
/************************/
EXTERN_START
int32_t ALBHV_DakkoNormal(  task* tp );
int32_t ALBHV_DakkoDislike( task* tp );
int32_t ALBHV_DakkoLike(    task* tp );
int32_t ALBHV_DakkoTron(    task* tp );
int32_t ALBHV_Dakko(        task* tp );

EXTERN_END

/************************/
/*  Function Ptrs       */
/************************/
#ifdef  SAMT_INCL_FUNCPTRS
/** Behavior ptrs **/
#   define ALBHV_DakkoNormal_p      BHVFUNC_PTR(0x005662B0)
#   define ALBHV_DakkoDislike_p     BHVFUNC_PTR(0x00566300)
#   define ALBHV_DakkoLike_p        BHVFUNC_PTR(0x005660A0)
#   define ALBHV_DakkoTron_p        BHVFUNC_PTR(0x00566580)
#   define ALBHV_Dakko_p            BHVFUNC_PTR(0x00566670)

#endif/*SAMT_INCL_FUNCPTRS*/

#endif/*_SA2B_CHAO_ALBVH_DAKKO_H_*/
