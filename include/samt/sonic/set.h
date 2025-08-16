/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/sonic/set.h'
*
*   Contains structs and functions related to stage SETs
*/
#ifndef _SA2B_SET_H_
#define _SA2B_SET_H_

EXTERN_START

/************************/
/*  Abstracted Types    */
/************************/
typedef struct task        task;

/************************/
/*  Typedefs            */
/************************/
typedef void(__cdecl* EDIT_FUNC)(task*);

/************************/
/*  Constants           */
/************************/
#define OBJFLG_ACTIVE       (0x0001)    /* OBJ_EDITENTRY.usID                       */
#define OBJFLG_UNKNOWN02    (0x0002)
#define OBJFLG_BROKEN       (0x0004)
#define OBJFLG_NOREVIVE     (0x0010)
#define OBJFLG_UNKNOWN20    (0x0020)
#define OBJFLG_CONTINUE     (0x4000)
#define OBJFLG_ALIVE        (0x8000)

#define EDTFLG_UNKOWN       (0x8000)    /* OBJ_EDITENTRY.usID, is from the 'u' file */

/************************/
/*  Structures          */
/************************/
typedef union _UNION_STATUS
{
    f32             fRangeOut;
    s32             pObjSleepCondition;
}
UNION_STATUS;

typedef struct _OBJ_EDITENTRY
{
    u16             usID;
    s16             rotx;
    s16             roty;
    s16             rotz;
    f32             xpos;
    f32             ypos;
    f32             zpos;
    f32             xscl;
    f32             yscl;
    f32             zscl;
}
OBJ_EDITENTRY;

typedef struct _OBJ_EDITTABLE
{
    u32             ulCount;        /* number of edit entries in array              */
    u32             padding[7];     /* padding space, unused                        */
    OBJ_EDITENTRY   objEditEntry[]; /* variable sized array of edit entries         */
}
OBJ_EDITTABLE;

typedef struct _OBJ_CONDITION
{
    u8              scCount;
    u8              scUserFlag;
    s16             ssCondition;
    task*           ptask;
    OBJ_EDITENTRY*  pObjEditEntry;
    UNION_STATUS    unionStatus;
}
OBJ_CONDITION;

typedef struct _OBJ_ITEMENTRY
{
    u8              ucInitMode;
    u8              ucLevel;
    s16             ssAttribute;
    f32             fRange;
    EDIT_FUNC       fnExec;
    char*           strObjName;
}
OBJ_ITEMENTRY;

typedef struct _OBJ_ITEMTABLE
{
    s32             slCount;
    OBJ_ITEMENTRY*  pObjItemEntry;
}
OBJ_ITEMTABLE;

/************************/
/*  Data                */
/************************/
#define SetObjectTaskP          DATA_REF(task*, 0x01A5A340)

/************************/
/*  Functions           */
/************************/
/****** Load/Free *******************************************************************/
/*
*   Description:
*     Loads two set files, 'fname_s' and 'fname_u', into a single edit table
*
*   Examples:
*     LoadSetFile("set_b_bigfoot_s.bin", "set_b_bigfoot_u.bin", 512);
*
*   Parameters:
*     - pcFileNameS : set file containing, usually, decorations including '.bin'
*     - pcFileNameU : set file containing, usually, important objects including '.bin'
*     - objnum      : number of objects to allocate for
* 
*   Returns:
*     A newly allocated edit table
*/
OBJ_EDITTABLE* LoadSetFile(const char* pcFileNameS, const char* pcFileNameU, size_t objnum);
/*
*   Description:
*     Loads the two set files from one file name, automatically appending '_s',
*   '_u', & '.bin'. If 'pcFileName' is nullptr, the 
*
*   Parameters:
*     - pcFileName  : set file name excluding '_s'/'_u' postfixes and '.bin'
*     - objnum      : number of objects to allocate for (usually 2048)
*
*   Returns:
*     A newly allocated edit table
*/
OBJ_EDITTABLE* LoadSetFileEx(const char* pcFileName, size_t objnum);

void    FreeSetFile( OBJ_EDITTABLE* pTable );

b32     CreateSetObject( OBJ_ITEMTABLE* pItem, OBJ_EDITTABLE* pTable );
b32     FreeSetObject( void );

/*
*   Description:
*     Set all loaded set objects to alive and not broken
*/
void    ReviveSetObject( void );

/*
*   Description:
*     Check if point is outside the current player's view.
*
*   Notes:
*     - Only works inside of a 'disp' function, otherwise undefined behavior.
*
*   Parameters:
*     - ft          : position
*     - radius      : size
*
*   Returns:
*     'FALSE' if the position *is* on screen; or 'TRUE' if not.
*/
b32     CheckViewV( const NJS_POINT3* ft, f32 radius );

int32_t CheckRangeOut(task* tp);
int32_t CheckRangeOutWithR(task* tp, float fRange);

void    SetBroken(   task* pTask );
void    SetNoRevive( task* pTask );
void    SetContinue( task* pTask );

b32     CheckBroken( task* pTask );

/*
*   Description:
*     Set object flags to 'dead'
*
*   Parameters:
*     - pTask   : task pointer
*/
void    Dead(task* pTask);
/*
*   Description:
*     Set object flags to 'dead' and free task
*
*   Parameters:
*     - pTask   : task pointer
*/
void    DeadOut(task* pTask);

/****** User Flag *******************************************************************/
void    SetUserFlag(task* tp, int8_t flag);
int8_t  GetUserFlag(task* tp);

/****** Other ***********************************************************************/
void    ObjectGenericExec(task* tp);

/************************/
/*  Function Ptrs       */
/************************/
#ifdef  SAMT_INCL_FUNCPTRS
/** Function ptr **/
#   define CreateSetObject_p            FUNC_PTR(b32 , __cdecl, (OBJ_ITEMTABLE*, OBJ_EDITTABLE*), 0x00487E40)
#   define ReviveSetObject_p            FUNC_PTR(void, __cdecl, (void)                          , 0x00488AD0)
#   define ObjectGenericExec_p          FUNC_PTR(void, __cdecl, (task*)                         , 0x005B4250)
#   define CheckViewV_p                 FUNC_PTR(b32 , __cdecl, (const NJS_POINT3*, f32)        , 0x007983F0)

/** User-Function ptr **/
#   define LoadSetFile_p                ((void*)0x00488DD0)
#   define LoadSetFileEx_p              ((void*)0x00488F60)
#   define CheckRangeOut_p              ((void*)0x00488C50)
#   define CheckRangeOutWithR_p         ((void*)0x00488C80)

#endif/*SAMT_INCL_FUNCPTRS*/

EXTERN_END

#endif/*_SA2B_SET_H_*/
