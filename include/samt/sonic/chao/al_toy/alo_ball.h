/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/sonic/chao/al_toy/alo_ball.h'
*
*   Description:
*       Contains functions and data related to the ball
*   garden object.
*/
#ifndef _SA2B_CHAO_TOY_BALL_H_
#define _SA2B_CHAO_TOY_BALL_H_

/************************/
/*  Includes            */
/************************/
#include <samt/ninja/njcommon.h>
#include <samt/ninja/njmatrix.h>

/************************/
/*  Abstract Types      */
/************************/
typedef struct task     task;

/************************/
/*  Structures          */
/************************/
#define GET_BALL_WORK(tp) (BALL_WORK*)(tp->awp)

typedef struct 
{
    float inv_radius;
    int32_t HeldAng;
    int32_t RotSpd;
    NJS_POINT3 axis;
    NJS_MATRIX mat;
}
BALL_WORK;

/************************/
/*  Data                */
/************************/
#define BallUsable              DATA_REF(int32_t, 0x01DBE574)
#define ALO_BallTaskPointer     DATA_REF(task*  , 0x01DBE570)

/************************/
/*  Functions           */
/************************/
EXTERN_START
void    ALO_BallCreate( const NJS_POINT3* pPos, const NJS_VECTOR* pVelo );

/** Internal task functions **/
void    ALO_Ball( task* tp );

void    ALO_BallExecutor(   task* tp );
void    ALO_BallDisplayer(  task* tp );
void    ALO_BallDestructor( task* tp ); // Same function as many other ALO objects

EXTERN_END

/************************/
/*  Function Ptrs       */
/************************/
#ifdef  SAMT_INCL_FUNCPTRS
/** Function ptrs **/
#   define ALO_BallCreate_p         FUNC_PTR(void, __cdecl, (const NJS_POINT3*, const NJS_VECTOR*), 0x0055D6B0)
#   define ALO_Ball_p               FUNC_PTR(void, __cdecl, (task*)                               , 0x0055D640)
#   define ALO_BallExecutor_p       FUNC_PTR(void, __cdecl, (task*)                               , 0x0055D310)
#   define ALO_BallDisplayer_p      FUNC_PTR(void, __cdecl, (task*)                               , 0x0055D3B0)
#   define ALO_BallDestructor_p     FUNC_PTR(void, __cdecl, (task*)                               , 0x0057B9B0)

#endif/*SAMT_INCL_FUNCPTRS*/

#endif/*_SA2B_CHAO_TOY_BALL_H_*/
