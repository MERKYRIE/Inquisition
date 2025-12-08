#pragma once

struct Inq_Walking_SInstance
{
    Inq_Animator_SInstance FAnimator;
    Sint64 FX;
    Sint64 FY;
    double FXOffset;
    double FYOffset;
};

void Inq_Walking_IConstruct(Inq_Walking_SInstance *const AInstance , char const*const APath);
double Inq_Walking_IGetXOffset(Inq_Walking_SInstance const*const AInstance);
double Inq_Walking_IGetYOffset(Inq_Walking_SInstance const*const AInstance);
bool Inq_Walking_IIsActive(Inq_Walking_SInstance const*const AInstance);
void Inq_Walking_IUpdateVideo(Inq_Walking_SInstance *const AInstance , Sint64 const AX , Sint64 const AY);
Inq_EntityData_UInstance * Inq_Walking_IUpdate(Inq_Walking_SInstance *const AInstance , Inq_EntityData_UInstance *const AData);
bool Inq_Walking_IWalkLeftUp(Inq_Walking_SInstance *const AInstance , Inq_EntityData_UInstance *const AData);
bool Inq_Walking_IWalkRightUp(Inq_Walking_SInstance *const AInstance , Inq_EntityData_UInstance *const AData);
bool Inq_Walking_IWalkLeftDown(Inq_Walking_SInstance *const AInstance , Inq_EntityData_UInstance *const AData);
bool Inq_Walking_IWalkRightDown(Inq_Walking_SInstance *const AInstance , Inq_EntityData_UInstance *const AData);
bool Inq_Walking_IWalkLeft(Inq_Walking_SInstance *const AInstance , Inq_EntityData_UInstance *const AData);
bool Inq_Walking_IWalkRight(Inq_Walking_SInstance *const AInstance , Inq_EntityData_UInstance *const AData);
bool Inq_Walking_IWalkUp(Inq_Walking_SInstance *const AInstance , Inq_EntityData_UInstance *const AData);
bool Inq_Walking_IWalkDown(Inq_Walking_SInstance *const AInstance , Inq_EntityData_UInstance *const AData);
void Inq_Walking_IDeconstruct(Inq_Walking_SInstance *const AInstance);