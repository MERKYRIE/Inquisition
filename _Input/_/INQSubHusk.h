#pragma once

struct Inq_SubHusk_SInstance
{
    Inq_Sprite_SInstance FSprite;
};

void Inq_SubHusk_IInitialize(void);
void Inq_SubHusk_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_SubHusk_IUpdateVideo(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY);
bool Inq_SubHusk_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_SubHusk_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_SubHusk_IDeinitialize(void);