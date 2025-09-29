#pragma once

struct Inq_Enemy_SInstance
{
    Inq_Sprite_SInstance FSprite;
};

void Inq_Enemy_IInitialize(void);
void Inq_Enemy_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Enemy_IUpdate(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY);
void Inq_Enemy_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Enemy_IDeinitialize(void);