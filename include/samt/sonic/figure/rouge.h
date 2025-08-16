/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/sonic/figure/rouge.h'
*
*   ~~ Under Construction ~~
*   Contains functions, structs, and data for Rouge
*/
#ifndef _SA2B_FIGURE_ROUGE_H_
#define _SA2B_FIGURE_ROUGE_H_

/************************/
/*  Includes            */
/************************/
#include <samt/sonic/figure/knuckles.h>

/************************/
/*  Data                */
/************************/
#define mtx_RougeBootL      DATA_REF(NJS_MATRIX, 0x01A51BBC)
#define mtx_RougeBootR      DATA_REF(NJS_MATRIX, 0x01A51C1C)

/************************/
/*  Functions           */
/************************/
EXTERN_START
void    RougeMotionCallBack(NJS_CNK_OBJECT* cnkobj);

EXTERN_END

/************************/
/*  Function Ptrs       */
/************************/
#ifdef SAMT_INCL_FUNCPTRS
/** Function ptrs **/
#   define RougeMotionCallBack_p        FUNC_PTR(void, __cdecl, (NJS_CNK_OBJECT*), 0x007304D0)

#endif /* SAMT_INCL_FUNCPTRS */

#endif /* _SA2B_FIGURE_ROUGE_H_ */
