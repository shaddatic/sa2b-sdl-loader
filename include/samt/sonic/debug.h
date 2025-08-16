/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/sonic/debug.h'
*
*   Description:
*       Contains data and functions related to the game's debug
*   features.
*/
#ifndef _SA2B_DEBUG_H_
#define _SA2B_DEBUG_H_

/************************/
/*  Functions           */
/************************/
#define ShowOverscanGrid            DATA_REF(bool32_t, 0x0174BA6C)

/************************/
/*  Functions           */
/************************/
EXTERN_START
int32_t  ___OutputDebugString( const char* str, ... );

EXTERN_END

/************************/
/*  Macros              */
/************************/
#define OutputFormat(...)               ___OutputDebugString(__VA_ARGS__)
#define OutputString(_s)                ___OutputDebugString((_s))
#define OutputInt(_i)                   ___OutputDebugString("%i", (_i))
#define OutputFloat(_f)                 ___OutputDebugString("%f", (_f))
#define OutputCharacter(_c)             ___OutputDebugString("%c", (_c))
#define OutputPointer(_p)               ___OutputDebugString("%p", (_p))

#define OutputPoint3(_p3)               ___OutputDebugString("%f, %f, %f", (_p3).x, (_p3).y, (_p3).z)
#define OutputAngle3(_a3)               ___OutputDebugString("%i, %i, %i", (_a3).x, (_a3).y, (_a3).z)

/************************/
/*  Function Ptrs       */
/************************/
#ifdef  SAMT_INCL_FUNCPTRS
/** Function ptrs **/
#   define ___OutputDebugString_p      FUNC_PTR(int32_t, __cdecl, (const char*, ...), 0x00426740)

#endif/*SAMT_INCL_FUNCPTRS*/

#endif/*_SA2B_DEBUG_H_*/
