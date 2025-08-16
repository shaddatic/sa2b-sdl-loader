/*
*   SAMT for Sonic Adventure 2 (PC, 2012) - '/sonic/chao/al_parameter.h'
*
*   Description:
*       Contains functions related to the Chao parameters.
*/
#ifndef _SA2B_CHAO_PARAMETER_H_
#define _SA2B_CHAO_PARAMETER_H_

/************************/
/*  Abstract Types      */
/************************/
typedef struct task     task;

/************************/
/*  Enums               */
/************************/
enum
{
    SKILL_SWIM,
    SKILL_FLY,
    SKILL_RUN,
    SKILL_POWER,
    SKILL_STAMINA,
    SKILL_GUTS,
    SKILL_INTELLECT,
    SKILL_EMPTY,
    NB_SKILL,
};

/************************/
/*  Functions           */
/************************/
EXTERN_START
/** Check alignment **/
b32     AL_IsHero(uint8_t type);
b32     AL_IsHero2(task* pChaoTask);
b32     AL_IsDark(uint8_t type);
b32     AL_IsDark2(task* pChaoTask);

/** Get Chao skill points adjusted by stage **/
uint32_t AL_ParameterGetSkill(task* tp, uint16_t SkillKind);

/** Set param control timers to 0 **/
void     AL_ParameterControlInit(void);

EXTERN_END

#endif/*_SA2B_CHAO_PARAMETER_H_*/
