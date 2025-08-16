/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/sonic/c_colli/ccl_info.h'
*
*   Description:
*       Definition for the CCL_INFO struct type.
*/
#ifndef _SA2B_CCOLLI_INFO_H_
#define _SA2B_CCOLLI_INFO_H_

/************************/
/*  Includes            */
/************************/
#include <samt/ninja/njcommon.h>

/************************/
/*  Structures          */
/************************/
typedef struct
{
    int8_t     kind;
    uint8_t    form;
    int8_t     push;
    int8_t     damage;
    uint32_t   attr;
    NJS_POINT3 center;
    f32        a;
    f32        b;
    f32        c;
    f32        d;
    int32_t    angx;
    int32_t    angy;
    int32_t    angz;
}
CCL_INFO;

#endif/*_SA2B_CCOLLI_INFO_H_*/
