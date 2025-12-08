#pragma once

struct Inq_Wall_SInstance
{
    Inq_Sprite_SInstance FSprite;
};

void Inq_Wall_IInitialize(void);
void Inq_Wall_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AVariation , Sint64 const AX , Sint64 const AY);
Sint64 Inq_Wall_IGetIdentifier(void);
Sint64 Inq_Wall_IGetTitle(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
Inq_Integral_SArray const* Inq_Wall_IGetPropertyArray(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
Sint64 Inq_Wall_IGetDescription(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
Sint64 Inq_Wall_IGetTooltip(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Wall_IUpdateVideo(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY);
Inq_Image_SInstance const* Inq_Wall_IGetPortrait(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
bool Inq_Wall_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
bool Inq_Wall_ICanWork(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Wall_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Wall_IDeinitialize(void);