/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/sonic/chao/stg_race/alo_race_box.h'
*
*   Description:
*       Contains functions for the Race Box object.
*/
#ifndef _SA2B_CHAO_RACE_BOX_H_
#define _SA2B_CHAO_RACE_BOX_H_

/************************/
/*  Abstract Types      */
/************************/
typedef struct task     task;

/************************/
/*  Functions           */
/************************/
EXTERN_START
/** Task functions **/
void    ALR_BoxExecutor(task* tp);

EXTERN_END

/************************/
/*  Function Ptrs       */
/************************/
#ifdef  SAMT_INCL_FUNCPTRS
/** Function ptrs **/
#   define ALR_BoxExecutor_p        FUNC_PTR(void, __cdecl, (task*), 0x0056A110)

#endif/*SAMT_INCL_FUNCPTRS*/

#endif/*_SA2B_CHAO_RACE_BOX_H_*/
