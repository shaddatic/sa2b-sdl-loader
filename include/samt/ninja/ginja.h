/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/ninja/ginja.h'
*
*   Description:
*     Ginja constants, structs, and functions. It is a modified version of Ninja
*   used for the GameCube.
*/
#ifndef _GINJA_H_
#define _GINJA_H_

/************************/
/*  Includes            */
/************************/
/** System **/
#include <samt/shinobi/sg_xpt.h>

#include <samt/ninja/njmatrix.h>

EXTERN_START

/************************/
/*  Data                */
/************************/
/****** Fog *************************************************************************/
#define _gj_fog_enable_             DATA_REF(Int, 0x025EFFCC)

/************************/
/*  Functions           */
/************************/
/****** Start Vertex ****************************************************************/
void    gjStartVertex3D( const NJS_MATRIX* m, u32 index );

/****** View ************************************************************************/
void    gjSetPerspective( Float screen_ratio, Float near_clip, Float far_clip );

/****** Set State *******************************************************************/
void    gjEnableFog(void);
void    gjDisableFog(void);

/****** Update State ****************************************************************/
void    gjUpdateFog(void);

EXTERN_END

#endif/*_GINJA_H_*/
