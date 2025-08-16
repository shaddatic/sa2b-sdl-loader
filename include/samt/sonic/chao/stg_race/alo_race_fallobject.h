/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/sonic/chao/stg_race/alo_race_fallobject.h'
*
*   Description:
*       Contains functions for the Race fall object.
*/
#ifndef _SA2B_CHAO_RACE_FALLOBJECT_H_
#define _SA2B_CHAO_RACE_FALLOBJECT_H_

/************************/
/*  Abstract Types      */
/************************/
typedef struct task     task;

/************************/
/*  Includes            */
/************************/
#include <samt/ninja/njcommon.h>

/************************/
/*  Functions           */
/************************/
EXTERN_START
void    CreateFallObject(NJS_POINT3* pPos);

/** Task functions **/
void    FallObjectExecutor(task* tp);

EXTERN_END

/************************/
/*  Function Ptrs       */
/************************/
#ifdef  SAMT_INCL_FUNCPTRS
/** Function ptrs **/
#   define CreateFallObject_p       FUNC_PTR(void, __cdecl, (NJS_POINT3*), 0x0053B0A0)
#   define FallObjectExecutor_p     FUNC_PTR(void, __cdecl, (task*)      , 0x0053AE10)

#endif/*SAMT_INCL_FUNCPTRS*/

#endif/*_SA2B_CHAO_RACE_FALLOBJECT_H_*/
