#pragma once

struct Inq_Wall_SInstance
{
    Inq_Name_SInstance FName;
};

void Inq_Wall_IInitialize(void);
void Inq_Wall_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Wall_IUpdateVideo(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY);
bool Inq_Wall_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Wall_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Wall_IDeinitialize(void);