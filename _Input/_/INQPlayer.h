#pragma once

struct Inq_Player_SInstance
{
    Inq_Sprite_SInstance FSprite;
};

void Inq_Player_IInitialize(void);
void Inq_Player_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Player_IUpdate(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY);
void Inq_Player_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Player_IDeinitialize(void);