#pragma once

struct Inq_Player_SInstance
{
    Inq_Animator_SInstance FAnimator;
    Sint64 FMovementX;
    Sint64 FMovementY;
    double FXOffset;
    double FYOffset;
};

void Inq_Player_IInitialize(void);
void Inq_Player_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Player_IGetOffset(Sint64 const AX , Sint64 const AY , double *const AXOffset , double *const AYOffset);
void Inq_Player_IUpdateVideo(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY);
bool Inq_Player_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Player_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Player_IDeinitialize(void);