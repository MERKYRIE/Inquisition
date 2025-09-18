#pragma once

struct Inq_Inquisitor_SInstance
{
    Inq_Sprite_SInstance FSprite;
};

void Inq_Inquisitor_IInitialize(void);
void Inq_Inquisitor_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Inquisitor_IUpdate(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY);
void Inq_Inquisitor_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Inquisitor_IDeinitialize(void);