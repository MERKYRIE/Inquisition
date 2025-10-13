#pragma once

struct Inq_Husk_SInstance
{
    Inq_Sprite_SInstance FSprite;
};

void Inq_Husk_IInitialize(void);
void Inq_Husk_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Husk_IUpdateVideo(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY);
bool Inq_Husk_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Husk_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Husk_IDeinitialize(void);