/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/sonic/chao/watermanager.h'
*
*   Description:
*       Contains structures and functions for SA2's Chao World
*   water effects. No symbols for this.
*/
#ifndef _SA2B_CHAO_WATERMANAGER_H_
#define _SA2B_CHAO_WATERMANAGER_H_

/************************/
/*  Includes            */
/************************/
#include <samt/ninja/ninja.h>

#include <samt/util/anyobj.h>

/************************/
/*  Abstract Types      */
/************************/
typedef struct task     task;

/************************/
/*  Structures          */
/************************/
/** Cnk variant **/
typedef struct // ANYWK
{
    NJS_CNK_OBJECT* pOrigObj;
    NJS_CNK_OBJECT* pCopyObj;
    f32             offsetU;
    f32             offsetV;
    f32             addU;
    f32             addV;
}
UV_SCROLL_INFO;

typedef struct
{
    ANY_OBJECT*     pObj;
    NJS_TEXLIST*    pTexList;
    int32_t         texid_min;
    int32_t         texid_max;
    f32             texid_startoff;
    f32             texid_curr;
    f32             texid_speed;
    b32             enabled;
    f32             addU;
    f32             addV;
}
WATER_ENTRY;

/************************/
/*  Functions           */
/************************/
EXTERN_START
/** Uses Ginja water entry pointers to create 
    animated water for the Chao gardens. 
    Must end with a NULL'd entry **/
void    CreateWaterManager( WATER_ENTRY* pEntryList );

/** Task functions **/
void    WaterManagerExecutor(   task* tp );
void    WaterManagerDisplayer(  task* tp );
void    WaterManagerDestructor( task* tp );

/** Same as above, but only used for races.
    Cnk water entry argument was optimized out **/
void    CreateCnkWaterManager( void );

/** Task functions **/
void    CnkWaterManagerExecutor(   task* tp );
void    CnkWaterManagerDisplayer(  task* tp );
void    CnkWaterManagerDestructor( task* tp );

EXTERN_END

/************************/
/*  Function Ptrs       */
/************************/
#ifdef SAMT_INCL_FUNCPTRS
/** Function ptrs **/
#   define CreateWaterManager_p             FUNC_PTR(void, __cdecl, (WATER_ENTRY*), 0x0056B040)
#   define WaterManagerExecutor_p           FUNC_PTR(void, __cdecl, (task*)       , 0x0056AF60)
#   define WaterManagerDisplayer_p          FUNC_PTR(void, __cdecl, (task*)       , 0x0056AF90)
#   define WaterManagerDestructor_p         FUNC_PTR(void, __cdecl, (task*)       , 0x0056AFF0)
#   define CreateCnkWaterManager_p          FUNC_PTR(void, __cdecl, (void)        , 0x0056B320)
#   define CnkWaterManagerExecutor_p        FUNC_PTR(void, __cdecl, (task*)       , 0x0056B1B0)
#   define CnkWaterManagerDisplayer_p       FUNC_PTR(void, __cdecl, (task*)       , 0x0056B290)
#   define CnkWaterManagerDestructor_p      FUNC_PTR(void, __cdecl, (task*)       , 0x0056B2D0)

#endif/*SAMT_INCL_FUNCPTRS*/

#endif/*_SA2B_CHAO_WATERMANAGER_H_*/
