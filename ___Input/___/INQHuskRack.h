#pragma once

struct Inq_HuskRack_SInstance
{
    Inq_Sprite_SInstance FSprite;
    double FInteractionTimer;
};

void Inq_HuskRack_IInitialize(void);
void Inq_HuskRack_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AVariation , Sint64 const AX , Sint64 const AY);
Sint64 Inq_HuskRack_IGetIdentifier(void);
Sint64 Inq_HuskRack_IGetTitle(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
Inq_Integral_SArray const* Inq_HuskRack_IGetPropertyArray(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
Sint64 Inq_HuskRack_IGetDescription(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
Sint64 Inq_HuskRack_IGetTooltip(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_HuskRack_IUpdateVideo(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY);
Inq_Image_SInstance const* Inq_HuskRack_IGetPortrait(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
bool Inq_HuskRack_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
bool Inq_HuskRack_ICanWork(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
bool Inq_HuskRack_IWork(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_HuskRack_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_HuskRack_IDeinitialize(void);