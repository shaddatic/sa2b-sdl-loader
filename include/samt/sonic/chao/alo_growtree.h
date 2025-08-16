/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/sonic/chao/alo_growtree.h'
*
*   Description:
*       Contains enums, structs, data, and functions related to Chao World trees.
*/
#ifndef _SA2B_CHAO_GROWTREE_H_
#define _SA2B_CHAO_GROWTREE_H_

/************************/
/*  Includes            */
/************************/
#include <samt/ninja/ninja.h>

#include <samt/sonic/task/taskwk.h>

/************************/
/*  Abstract Types      */
/************************/
typedef struct task             task;
typedef struct tree_save_info   TREE_SAVE_INFO;

/************************/
/*  Enums               */
/************************/
typedef enum
{
    TREE_NONE,                  /* none tree type                                   */
    TREE_MORIMORI,              /* strong fruit tree                                */
    TREE_PAKUPAKU,              /* tasty fruit tree                                 */
    TREE_HERO,                  /* hero fruit tree                                  */
    TREE_DARK,                  /* dark fruit tree                                  */
    TREE_MARU,                  /* round fruit tree                                 */
    TREE_SANKAKU,               /* triangle fruit tree                              */
    TREE_SIKAKU,                /* square fruit tree                                */
    TREE_LOCAL,                 /* local garden tree                                */
    TREE_END,                   /* nb tree                                          */
}
eTREE_KIND;

typedef enum
{
    TREE_ST_PLANT,
    TREE_ST_SEED,
    TREE_ST_SAPLING,
    TREE_ST_ADULT,
    TREE_ST_DEAD,
    TREE_ST_LOCAL,
}
eTREE_STATE;

enum
{
    MD_PLANT,
    MD_SEED,
    MD_SEED_TO_SAPLING,
    MD_SEED_TO_SAPLING2,
    MD_SAPLING,
    MD_SAPLING_GROW,
    MD_SAPLING_GROW2,
    MD_ADULT,
    MD_DEAD,
    MD_DEAD2,
    MD_FADEOUT,
};

/************************/
/*  Structures          */
/************************/
typedef struct
{
    f32       growth;
    f32       AimGrowth;
    int32_t SwingCounter;
    NJS_POINT3 pos;
    int32_t angx;
    int32_t angy;
}
FRUIT_INFO;

#define GET_TREE_WORK(_tp)      ((TREE_WORK*)_tp->twp)

typedef struct // taskwk
{
    TASKWK;

    uint8_t type;
    uint8_t state;
    f32     growth;
    int32_t life;
    int32_t water;
    uint8_t pos_num;
    FRUIT_INFO fruit[3];
    f32     scale;
    f32     scaleSpd;
    int32_t ThirstyFlag;
    int32_t WaterFlag;
    int32_t LeafRotAng;
    f32     LeafWidth;
    int32_t LeafDispNum;
    Angle FruitRotAng;
    f32     FruitWidth;
    int32_t FruitDisplayNum;
    int32_t SwingFlag;
    int32_t SwingCountFlag;
    f32     SwingDist;
    Angle RollAngle;
    Angle TouchAngle;
    int32_t ChaoSwingPhase;
    int32_t RollPhase;
    int32_t garden;
    TREE_SAVE_INFO* pMySaveInfo;
    NJS_TEXLIST* texlist;
    NJS_CNK_OBJECT* pLocalObject;
    NJS_CNK_OBJECT* pShadowObject;
    NJS_CNK_OBJECT* pCopyObject;
}
TREE_WORK;

/************************/
/*  Data                */
/************************/
#define TreeSetPos              DATA_ARY(NJS_VECTOR, 0x01366B30, [3][10])
#define LeafPhaseList           DATA_ARY(Angle     , 0x012E8AEC, [11])
#define FruitPhaseList          DATA_ARY(Angle     , 0x013291B4, [4])

/*
*     Tree Objects start at 'MORIMORI', so the array should be indexed as: 
*
*       TreeObjectList[twp->kind - 1][$tree_stage]
*/
#define TreeObjectList          DATA_ARY(NJS_CNK_OBJECT*, 0x01329148, [TREE_END][3])

/************************/
/*  Functions           */
/************************/
EXTERN_START
task*   ALO_GrowTreeCreate(NJS_POINT3* pPos, TREE_SAVE_INFO* pInfo);

/** Task functions **/
void    ALO_GrowTreeExecutor(   task* tp );
void    ALO_GrowTreeDisplayer(  task* tp );
void    ALO_GrowTreeDestructor( task* tp );

/** Internal functions **/
void    CalcFruitPos(NJS_POINT3* pPos, TREE_WORK* pTree, int32_t FruitNum);
void    CalcFruitPosSub(NJS_POINT3* pPos, TREE_WORK* pTree, NJS_CNK_OBJECT* pObject, int32_t FruitNum);

EXTERN_END

/************************/
/*  Function Ptrs       */
/************************/
#ifdef  SAMT_INCL_FUNCPTRS
/** Function ptrs **/
#   define ALO_GrowTreeCreate_p         FUNC_PTR(task*, __cdecl, (NJS_POINT3*, TREE_SAVE_INFO*)                     , 0x00548210)
#   define ALO_GrowTreeExecutor_p       FUNC_PTR(void , __cdecl, (task*)                                            , 0x00546810)
#   define ALO_GrowTreeDisplayer_p      FUNC_PTR(void , __cdecl, (task*)                                            , 0x00547E70)
#   define ALO_GrowTreeDestructor_p     FUNC_PTR(void , __cdecl, (task*)                                            , 0x005481E0)
#   define CalcFruitPos_p               FUNC_PTR(void , __cdecl, (NJS_POINT3*, TREE_WORK*, int32_t)                 , 0x00546670)
#   define CalcFruitPosSub_p            FUNC_PTR(void , __cdecl, (NJS_POINT3*, TREE_WORK*, NJS_CNK_OBJECT*, int32_t), 0x00546530)

#endif/*SAMT_INCL_FUNCPTRS*/

#endif/*_SA2B_CHAO_GROWTREE_H_*/
