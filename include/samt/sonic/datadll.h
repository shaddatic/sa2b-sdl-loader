/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/sonic/datadll.h'
*
*   Description:
*       Contains a function and macro for interfacing with
*   Data.dll.
*/
#ifndef _SA2B_DATADLL_H_
#define _SA2B_DATADLL_H_

/************************/
/*  Functions           */
/************************/
EXTERN_START
/** Get process address from the Data_DLL.dll HMODULE **/
void*   GetDataDllProcAddr( const char* lpProcName );

EXTERN_END

/************************/
/*  Macro               */
/************************/
#define GetDataDllAddr(type, name)  ((type*)GetDataDllProcAddr(name))

/************************/
/*  Function Ptrs       */
/************************/
#ifdef SAMT_INCL_FUNCPTRS
/** Function ptrs **/
#   define GetDataDllProcAddr_p        FUNC_PTR(void*, __cdecl, (const char*), 0x0077DEF0)

#endif/*SAMT_INCL_FUNCPTRS*/

#endif/*_SA2B_DATADLL_H_*/
