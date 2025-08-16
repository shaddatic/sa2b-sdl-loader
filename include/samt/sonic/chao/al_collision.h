/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/sonic/chao/al_collision.h'
*
*   Description:
*       Contains functions related to basic Chao object
*   collisions.
*/
#ifndef _SA2B_CHAO_COLLISION_H_
#define _SA2B_CHAO_COLLISION_H_

/************************/
/*  Abstract Types      */
/************************/
typedef struct task     task;

/************************/
/*  Functions           */
/************************/
EXTERN_START
void    AL_DetectCollisionStandard(task* tp);

EXTERN_END

/************************/
/*  Function Ptrs       */
/************************/
#ifdef  SAMT_INCL_FUNCPTRS
/** User-Function ptrs **/
#   define AL_DetectCollisionStandard_p     ((void*)0x0053E020)

#endif/*SAMT_INCL_FUNCPTRS*/

#endif/*_SA2B_CHAO_COLLISION_H_*/
