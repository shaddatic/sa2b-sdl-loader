/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/util/cnkmdl.h'
*
*   Description:
*     Utility header defining Chunk model offset structures, constants, and macros
*   for direct use or simply for reference.
*/
#ifndef H_UTIL_CNKMDL
#define H_UTIL_CNKMDL

/************************/
/*  External Includes   */
/************************/
/****** Ninja ***********************************************************************/
#include <samt/ninja/njcommon.h> /* ninja common                                    */
#include <samt/ninja/njchunk.h>  /* ninja chunk                                     */

EXTERN_START

/************************/
/*  Constants           */
/************************/
/************************************************************************************/
/*
*   Chunk Type Limits
*/
/****** Max Offset ******************************************************************/
#define CNK_NULLOFF_MAX    (NJD_CN        ) /* max null type                        */
#define CNK_BITSOFF_MAX    (NJD_CB_DP     ) /* max bits type                        */
#define CNK_TINYOFF_MAX    (NJD_CT_TID2   ) /* max bits type                        */
#define CNK_MATOFF_MAX     (NJD_CM_DAS2   ) /* max material type                    */
#define CNK_VERTOFF_MAX    (NJD_CV_NF_D8  ) /* max vertex type                      */
#define CNK_VOLOFF_MAX     (NJD_CO_ST     ) /* max volume type                      */
#define CNK_STRIPOFF_MAX   (NJD_CS_UVH2   ) /* max strip type                       */

/************************************************************************************/
/*
*   PList Offset Sizes
*/
/****** Null Offset *****************************************************************/
#define CNK_NULLOFF_SIZE        (1) /* step count of offset                         */

/****** Bits Offset *****************************************************************/
#define CNK_BITSOFF_SIZE        (1) /* step count of offset                         */

/****** Tiny Offset *****************************************************************/
#define CNK_TINYOFF_SIZE        (2) /* step count of offset                         */

/****** Material Offset *************************************************************/
#define CNK_MATOFF_SIZE_HEAD    (2) /* step count of header                         */
#define CNK_MATOFF_SIZE_ADD     (2) /* additional step count after reading 'size'   */
#define CNK_MATOFF_SIZE_MAT     (2) /* step count of material color                 */
#define CNK_MATOFF_SIZE_1       (CNK_MATOFF_SIZE_HEAD+(CNK_MATOFF_SIZE_MAT*1)) /* D/A/S     */
#define CNK_MATOFF_SIZE_2       (CNK_MATOFF_SIZE_HEAD+(CNK_MATOFF_SIZE_MAT*2)) /* DA/DS/AS  */
#define CNK_MATOFF_SIZE_3       (CNK_MATOFF_SIZE_HEAD+(CNK_MATOFF_SIZE_MAT*3)) /* DAS       */

/****** Volume Offset ***************************************************************/
#define CNK_VOLOFF_SIZE_HEAD    (3) /* step count of header                         */
#define CNK_VOLOFF_SIZE_ADD     (2) /* additional step count after reading 'size'   */

/****** Strip Offset ****************************************************************/
#define CNK_STRIPOFF_SIZE_HEAD  (3) /* step count of header                         */
#define CNK_STRIPOFF_SIZE_ADD   (2) /* additional step count after reading 'size'   */

/************************************************************************************/
/*
*   VList Offset Sizes
*/
/****** Vertex Offset Size **********************************************************/
#define CNK_VERTOFF_SIZE_HEAD   (2) /* size of header                               */

/************************************************************************************/
/*
*   Blend Chunk Constants
*/
/****** Blend Mode ******************************************************************/
#define CNK_BLEND_ZERO          (0) /* blend zero                                   */
#define CNK_BLEND_ONE           (1) /* blend one                                    */
#define CNK_BLEND_OC            (2) /* blend other color                            */
#define CNK_BLEND_IOC           (3) /* blend inverse other color                    */
#define CNK_BLEND_SA            (4) /* blend source alpha                           */
#define CNK_BLEND_ISA           (5) /* blend inverse source alpha                   */
#define CNK_BLEND_DA            (6) /* blend destination alpha                      */
#define CNK_BLEND_IDA           (7) /* blend inverse destination alpha              */

/************************************************************************************/
/*
*   Tiny Chunk Constants
*/
/****** UV Flip Mode ****************************************************************/
#define CNK_FLIP_NONE           (0) /* no uv flip                                   */
#define CNK_FLIP_V              (1) /* flip v                                       */
#define CNK_FLIP_U              (2) /* flip u                                       */
#define CNK_FLIP_UV             (3) /* flip u and v                                 */

/****** UV Clamp Mode ***************************************************************/
#define CNK_CLAMP_NONE          (0) /* no uv clamp                                  */
#define CNK_CLAMP_V             (1) /* clamp v                                      */
#define CNK_CLAMP_U             (2) /* clamp u                                      */
#define CNK_CLAMP_UV            (3) /* clamp u and v                                */

/****** Texture Filter Mode *********************************************************/
#define CNK_FILTER_POINTSAMPLE  (0) /* point sampling                               */
#define CNK_FILTER_BILINEAR     (1) /* bilinear filter                              */
#define CNK_FILTER_TRILINEAR_A  (2) /* trilinear filter a                           */
#define CNK_FILTER_TRILINEAR_B  (3) /* trilinear filter b                           */

/************************************************************************************/
/*
*   Vertex Chunk Constants
*/
/****** Weight Multiply *************************************************************/
#define CNK_WEIGHT_MUL          (1.f/255.f) /* weight multiply value                */

/****** Vertex Weight Status ********************************************************/
#define CNK_WEIGHT_START        (0) /* weighted vertex start                        */
#define CNK_WEIGHT_MIDDLE       (1) /* weighted vertex continue                     */
#define CNK_WEIGHT_END          (2) /* weighted vertex stop                         */

/****** 32bit Normal Multiply *******************************************************/
#define CNK_VNX_MUL             (1.f/512.f) /* vnx multiply value                   */

/************************************************************************************/
/*
*   Strip Chunk Constants
*/
/****** Strip Flags *****************************************************************/
#define CNK_FST_IL              (NJD_FST_IL >>NJD_FST_SHIFT)
#define CNK_FST_IS              (NJD_FST_IS >>NJD_FST_SHIFT)
#define CNK_FST_IA              (NJD_FST_IA >>NJD_FST_SHIFT)
#define CNK_FST_UA              (NJD_FST_UA >>NJD_FST_SHIFT)
#define CNK_FST_DB              (NJD_FST_DB >>NJD_FST_SHIFT)
#define CNK_FST_FL              (NJD_FST_FL >>NJD_FST_SHIFT)
#define CNK_FST_ENV             (NJD_FST_ENV>>NJD_FST_SHIFT)
#define CNK_FST_NAT             (NJD_FST_NAT>>NJD_FST_SHIFT)

/****** UV Multiply *****************************************************************/
#define CNK_UVN_MUL             (1.f/256.f)  /* uv multiply value                   */
#define CNK_UVH_MUL             (1.f/1024.f) /* hd uv multiply value                */

/****** PVN Multiply ****************************************************************/
#define CNK_PVN_MUL             (1.f/32767.f) /* plist vertex normal multiply value */

/************************************************************************************/
/*
*   Chunk Return Value
*/
/****** Return (Model/VList) ********************************************************/
#define CNK_RETN_OK             ( 0) /* all ok                                      */
#define CNK_RETN_CLIP           (-1) /* clipped                                     */

/************************/
/*  Structures          */
/************************/
/************************************************************************************/
/*
*   Null Structures
*/
/****** Header + Structure **********************************************************/
typedef struct
{
    Uint8  head;                /* chunk type                                       */

    Uint8  nul;                 /* nothing                                [padding] */
}
CNK_NULL_HEAD;

/************************************************************************************/
/*
*   Bits Structures
*/
/****** Header **********************************************************************/
typedef struct
{
    Uint8  head;                /* chunk type                                       */

    Uint8  d;                   /* data                                             */
}
CNK_BITS_HEAD;

/****** Structures ******************************************************************/
typedef struct
{
    Uint8       : 2;
    Uint8 src   : 3;            /* source blend mode                                */
    Uint8 dst   : 3;            /* destination blend mode                           */
}
CNK_BITS_BLENDALPHA;

typedef struct
{
    Uint8        : 4;
    Uint8 adjust : 4;           /* mipmap 'd' adjust                                */
}
CNK_BITS_DADJUST;

typedef struct
{
    Uint8       : 3;
    Uint8 exp   : 5;            /* specular exponent                         [0~16] */
}
CNK_BITS_EXPONENT;

typedef struct
{
    Uint8 list;                 /* cache/draw polygon list                  [0~255] */
}
CNK_BITS_POLYLIST;

/************************************************************************************/
/*
*   Material Structures
*/
/****** Header + Structure **********************************************************/
typedef struct
{
    Uint8  head;                /* chunk type        [diff & 1, ambi & 2, spec & 4] */

    Uint8       : 2;
    Uint8  src  : 3;            /* source blend mode                                */
    Uint8  dst  : 3;            /* destination blend mode                           */
    Uint16 size;                /* chunk size        (in s16 steps, from this byte) */

    NJS_BGRA d[];               /* data          [ambi: 'a' = nul, spec: 'a' = exp] */
}
CNK_MATERIAL_HEAD;

/************************************************************************************/
/*
*   Tiny Structures
*/
/****** Header + Structure **********************************************************/
typedef struct
{
    Uint8  head;                /* chunk type                                       */

    Uint8  mipmap : 4;          /* mipmap adjust                                    */
    Uint8  clamp  : 2;          /* uv clamp mode                                    */
    Uint8  flip   : 2;          /* uv flip mode                                     */

    Uint16 texid   : 13;        /* texture id                                       */
    Uint16 ssample : 1;         /* super sample flag                                */
    Uint16 filter  : 2;         /* texture filter mode                              */
}
CNK_TINY_HEAD;

/************************************************************************************/
/*
*   VList Structures
*/
/****** Header **********************************************************************/
typedef struct
{
    Uint8  head;                /* chunk type                                       */

    Uint8  wstat  : 2;          /* weight status                  [ninja flag only] */
    Uint8         : 4;
    Uint8  cshape : 1;          /* compact shape flag                 [ninja2 flag] */
    Uint8  vcalc  : 1;          /* vertex calculation continue    [ninja flag only] */
    Uint16 size;                /* chunk size        [in s16 steps, from this byte] */
    Uint16 indexoffset;         /* vertex buffer offset                             */
    Uint16 nbindeces;           /* vertex count                                     */

    Sint32 d[];                 /* data array                            [variable] */
}
CNK_VERTEX_HEAD;

/****** Sub-Structures **************************************************************/
typedef struct
{
    Uint16 r : 5;               /* red component                             [0~31] */
    Uint16 g : 6;               /* green component                           [0~63] */
    Uint16 b : 5;               /* blue component                            [0~31] */
}
CNK_565;

typedef struct
{
    Uint16 a : 4;               /* alpha component                           [0~15] */
    Uint16 r : 4;               /* red component                             [0~15] */
    Uint16 g : 4;               /* green component                           [0~15] */
    Uint16 b : 4;               /* blue component                            [0~15] */
}
CNK_4444;

typedef struct
{
    Sint32   :  2;              /* padding                                          */
    Sint32 x : 10;              /* x normal                              [-512~511] */
    Sint32 y : 10;              /* y normal                              [-512~511] */
    Sint32 z : 10;              /* z normal                              [-512~511] */
}
CNK_VNX;

/****** Structures ******************************************************************/
typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    Float      one;             /* 1.f                                    [padding] */
}
CNK_VERTEX_SH;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    Float      one;             /* 1.f                                    [padding] */
    NJS_VECTOR nrm;             /* normal                                           */
    Float      zro;             /* 0.f                                    [padding] */
}
CNK_VERTEX_VN_SH;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
}
CNK_VERTEX;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    NJS_BGRA   col;             /* vertex color                                     */
}
CNK_VERTEX_D8;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    NJS_VECTOR nrm;             /* normal                                           */
}
CNK_VERTEX_VN;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    Uint32     usf;             /* user flag                                        */
}
CNK_VERTEX_UF;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    Uint16     i;               /* vertex buffer index                              */
    Uint16     w;               /* weight value                             [0~255] */
}
CNK_VERTEX_NF;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    CNK_565    col;             /* diffuse color                                    */
    CNK_565    spc;             /* specular color                                   */
}
CNK_VERTEX_S5;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    CNK_4444   col;             /* diffuse color                                    */
    CNK_565    spc;             /* specular color                                   */
}
CNK_VERTEX_S4;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    Uint16     col;             /* diffuse intensity                      [0~65535] */
    Uint16     spc;             /* specular intensity                     [0~65535] */
}
CNK_VERTEX_IN;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    NJS_VECTOR nrm;             /* normal                                           */
    NJS_BGRA   col;             /* diffuse color                                    */
}
CNK_VERTEX_VN_D8;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    NJS_VECTOR nrm;             /* normal                                           */
    Uint32     usf;             /* user flag                                        */
}
CNK_VERTEX_VN_UF;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    NJS_VECTOR nrm;             /* normal                                           */
    Uint16     i;               /* vertex buffer index                              */
    Uint16     w;               /* weight value                             [0~255] */
}
CNK_VERTEX_VN_NF;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    NJS_VECTOR nrm;             /* normal                                           */
    CNK_565    col;             /* diffuse color                                    */
    CNK_565    spc;             /* specular color                                   */
}
CNK_VERTEX_VN_S5;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    NJS_VECTOR nrm;             /* normal                                           */
    CNK_4444   col;             /* diffuse color                                    */
    CNK_565    spc;             /* specular color                                   */
}
CNK_VERTEX_VN_S4;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    NJS_VECTOR nrm;             /* normal                                           */
    Uint16     col;             /* diffuse intensity                      [0~65535] */
    Uint16     spc;             /* specular intensity                     [0~65535] */
}
CNK_VERTEX_VN_IN;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    CNK_VNX    nrm;             /* 32bit normal                                     */
}
CNK_VERTEX_VNX;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    CNK_VNX    nrm;             /* 32bit normal                                     */
    NJS_BGRA   col;             /* diffuse color                                    */
}
CNK_VERTEX_VNX_D8;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    CNK_VNX    nrm;             /* 32bit normal                                     */
    Uint32     usf;             /* user flag                                        */
}
CNK_VERTEX_VNX_UF;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    NJS_BGRA   col;             /* diffuse color                                    */
    NJS_BGRA   spc;             /* specular color                      [A: padding] */
}
CNK_VERTEX_D8_S8;

typedef struct
{
    NJS_POINT3 pos;             /* position                                         */
    Uint16     i;               /* vertex buffer index                              */
    Uint16     w;               /* weight value                             [0~255] */
    NJS_BGRA   col;             /* diffuse color                                    */
}
CNK_VERTEX_NF_D8;

/************************************************************************************/
/*
*   User Flag Structures
* 
*   Notes:
*     - User Flags appear each POLYGON, and NOT each INDEX. This means you must
*       SKIP the first two indexes when parsing strips, as a whole polygon hasn't
*       been created until the 3rd index.
*/
/****** User Flag Offsets ***********************************************************/
typedef struct
{
    Sint16 flag[];              /* user flag                             [variable] */
}
CNK_UFO;

/************************************************************************************/
/*
*   Volume Structures
*/
/****** Header **********************************************************************/
typedef struct
{
    Uint8  head;                /* chunk type                                       */

    Uint8  flag;                /* strip flags                                      */
    Uint16 size;                /* chunk size        (in s16 steps, from next byte) */
    Uint16 nbpoly  : 14;        /* poly/strip count                                 */
    Uint16 ufo     : 2;         /* user flag offset                                 */

    Sint16 d[];                 /* data array                            (variable) */
}
CNK_VOLUME_HEAD;

/****** Volume Poly *****************************************************************/
typedef struct
{
    Uint16      i0;             /* vertex buffer index 0                            */
    Uint16      i1;             /* vertex buffer index 1                            */
    Uint16      i2;             /* vertex buffer index 2                            */
//  CNK_UFO     ufo;            /* user flag offset                                 */
}
CNK_VO_P3;

typedef struct
{
    Uint16      i0;             /* vertex buffer index 0                            */
    Uint16      i1;             /* vertex buffer index 1                            */
    Uint16      i2;             /* vertex buffer index 2                            */
    Uint16      i3;             /* vertex buffer index 3                            */
//  CNK_UFO     ufo;            /* user flag offset                                 */
}
CNK_VO_P4;

typedef struct
{
    Uint16      i;              /* vertex buffer index                              */
//  CNK_UFO     ufo;            /* user flag offset, per polygon                    */
}
CNK_VO_ST;

/****** Volume Data *****************************************************************/
typedef struct
{
    CNK_VO_P3       d[];        /* strip data                            (variable) */
}
CNK_VOLUME_P3;

typedef struct
{
    CNK_VO_P4       d[];        /* strip data                            (variable) */
}
CNK_VOLUME_P4;

typedef struct
{
    Sint16          len;        /* strip length            (< 0 == reverse winding) */
    CNK_VO_ST       d[];        /* strip data                            (variable) */
}
CNK_VOLUME_ST;

/************************************************************************************/
/*
*   Strip Structures
*/
/****** Header **********************************************************************/
typedef struct
{
    Uint8  head;                /* chunk type                                       */

    Uint8  flag;                /* strip flags                                      */
    Uint16 size;                /* chunk size        (in s16 steps, from next byte) */
    Uint16 nbstrip  : 14;       /* strip count                                      */
    Uint16 ufo      : 2;        /* user flag offset                                 */

    Sint16 d[];                 /* data array                            (variable) */
}
CNK_STRIP_HEAD;

/****** Sub-Struct ******************************************************************/
typedef struct
{
    Sint16          i;          /* vertex buffer index                              */
//  CNK_UFO         ufo;        /* user flag offset, per polygon                    */
}
CNK_ST;

typedef struct
{
    Uint16          i;          /* vertex buffer index                              */
    Sint16          u;          /* u coordinate                   (0~256 or 0~1024) */
    Sint16          v;          /* v coordinate                   (0~256 or 0~1024) */
//  CNK_UFO         ufo;        /* user flag offset, per polygon                    */
}
CNK_ST_UV;

typedef struct
{
    Uint16          i;          /* vertex buffer index                              */
    Sint16          vnx;        /* x vertex normal                        (0~32767) */
    Sint16          vny;        /* y vertex normal                        (0~32767) */
    Sint16          vnz;        /* z vertex normal                        (0~32767) */
//  CNK_UFO         ufo;        /* user flag offset, per polygon                    */
}
CNK_ST_VN;

typedef struct
{
    Uint16          i;          /* vertex buffer index                              */
    Sint16          u;          /* u coordinate                   (0~256 or 0~1024) */
    Sint16          v;          /* v coordinate                   (0~256 or 0~1024) */
    Sint16          vnx;        /* x vertex normal                        (0~32767) */
    Sint16          vny;        /* y vertex normal                        (0~32767) */
    Sint16          vnz;        /* z vertex normal                        (0~32767) */
//  CNK_UFO         ufo;        /* user flag offset, per polygon                    */
}
CNK_ST_UV_VN;

typedef struct
{
    Uint16          i;          /* vertex buffer index                              */
    NJS_BGRA        col;        /* vertex color                                     */
//  CNK_UFO         ufo;        /* user flag offset, per polygon                    */
}
CNK_ST_D8;

typedef struct
{
    Uint16          i;          /* vertex buffer index                              */
    Sint16          u;          /* u coordinate                   (0~256 or 0~1024) */
    Sint16          v;          /* v coordinate                   (0~256 or 0~1024) */
    NJS_BGRA        col;        /* vertex color                                     */
//  CNK_UFO         ufo;        /* user flag offset, per polygon                    */
}
CNK_ST_UV_D8;

/****** Chunk Struct ****************************************************************/
typedef struct
{
    Sint16          len;        /* strip length            (< 0 == reverse winding) */
    CNK_ST          d[];        /* strip data                            (variable) */
}
CNK_STRIP;

typedef struct
{
    Sint16          len;        /* strip length            (< 0 == reverse winding) */
    CNK_ST_UV       d[];        /* strip data                            (variable) */
}
CNK_STRIP_UV;

typedef struct
{
    Sint16          len;        /* strip length            (< 0 == reverse winding) */
    CNK_ST_VN       d[];        /* strip data                            (variable) */
}
CNK_STRIP_VN;

typedef struct
{
    Sint16          len;        /* strip length            (< 0 == reverse winding) */
    CNK_ST_UV_VN    d[];        /* strip data                            (variable) */
}
CNK_STRIP_UV_VN;

typedef struct
{
    Sint16          len;        /* strip length            (< 0 == reverse winding) */
    CNK_ST_D8       d[];        /* strip data                            (variable) */
}
CNK_STRIP_D8;

typedef struct
{
    Sint16          len;        /* strip length            (< 0 == reverse winding) */
    CNK_ST_UV_D8    d[];        /* strip data                            (variable) */
}
CNK_STRIP_UV_D8;

/************************/
/*  Macros              */
/************************/
/************************************************************************************/
/*
*   Chunk Offset Type
*/
/****** Get Offset Type *************************************************************/
/*
*   Description:
*     Get chunk offset type from raw chunk header pointer.
*
*   Parameters:
*     - pcnk        : chunk header
*
*   Returns:
*     Chunk offset type.
*/
#define CNK_GET_OFFTYPE(pcnk_)      (((Uint8*)(pcnk_))[0])

/************************************************************************************/
/*
*   Get Vertex Data
*/
/****** Vertex Weight ***************************************************************/
/*
*   Description:
*     Convert integer vertex weight value to 0.f~1.f.
*
*   Parameters:
*     - w           : weight value
*
*   Returns:
*     Weight value converted to 0.f~1.f.
*/
#define CNK_GET_WEIGHT(w)           ((Float)(w)*CNK_WEIGHT_MUL)

/****** 32bit Vertex Normal *********************************************************/
/*
*   Description:
*     Convert integer vertex normal value to -1.f~1.f.
*
*   Parameters:
*     - vnx         : normal value
*
*   Returns:
*     32bit Normal value converted to -1.f~1.f.
*/
#define CNK_GET_VNX(vnx)            ((Float)(vnx)*CNK_VNX_MUL)

/************************************************************************************/
/*
*   Get Strip Data
*/
/****** UV Coordinates **************************************************************/
/*
*   Description:
*     Convert integer UV value to 0.f~1.f.
*
*   Parameters:
*     - uv          : uv value
*
*   Returns:
*     UV value converted to 0.f~1.f.
*/
#define CNK_GET_UVN(uv)             ((Float)(uv)*CNK_UVN_MUL)
/*
*   Description:
*     Convert integer HD UV value to 0.f~1.f.
*
*   Parameters:
*     - uv          : uv value
*
*   Returns:
*     UV value converted to 0.f~1.f.
*/
#define CNK_GET_UVH(uv)             ((Float)(uv)*CNK_UVH_MUL)

/****** Plist Vertex Normal *********************************************************/
/*
*   Description:
*     Convert integer vertex normal value to 0.f~1.f.
*
*   Parameters:
*     - vn          : vertex normal value
*
*   Returns:
*     Vertex normal value converted to 0.f~1.f.
*/
#define CNK_GET_PVN(vn)             ((Float)(vn)*CNK_PVN_MUL)

/************************************************************************************/
/*
*   User Flag Offset
*/
/****** Get User Flag Offset ********************************************************/
/*
*   Description:
*     Get user flag offset for Chunk polygon.
*
*   Parameters:
*     - ppl         : current polygon
*
*   Returns:
*     User flag offset pointer.
*/
#define CNK_GET_UFO(ppl_) \
    (CNK_UFO*)((uintptr_t)(ppl_) + ( sizeof(*(ppl_)) ))

/************************************************************************************/
/*
*   Get Next Pointer
*/
/****** Strip ***********************************************************************/
/*
*   Description:
*     Get next strip list.
* 
*   Notes:
*     - There's no counterpart to this macro for polygon lists, as they're stored
*       as one chunk rather than many like strip lists.
*
*   Parameters:
*     - pst         : current strip index
*     - ufo         : user flag offset level
*
*   Returns:
*     Next strip list pointer.
*/
#define CNK_NEXT_STRIP(pst_, len_, ufo_) \
    (void*)((uintptr_t)(pst_) + ( (sizeof((pst_)->len)) + (sizeof((pst_)->d[0]) * (len_)) + (sizeof(Uint16)*(ufo_)*((len_)-2)) ))

/****** Strip/Volume ****************************************************************/
/*
*   Description:
*     Get next polygon in list.
* 
*   Notes:
*     - When parsing strips, the first two indexes don't have user flag offsets.
*       This is because a polygon technically hasn't been formed yet. Because of
*       this, the first two indexes should use a 'ufo' value of '0'.
*
*   Parameters:
*     - ppl         : current polygon
*     - ufo         : user flag offset level
*
*   Returns:
*     Next polygon pointer.
*/
#define CNK_NEXT_POLY(ppl_, ufo_) \
    (void*)((uintptr_t)(ppl_) + ( (sizeof(*(ppl_))) + (sizeof(Uint16)*(ufo_)) ))

EXTERN_END

#endif/*H_UTIL_CNKMDL*/
