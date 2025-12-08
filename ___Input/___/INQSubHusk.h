#pragma once

struct Inq_SubHusk_SInstance
{
    Inq_Walking_SInstance FWalking;
};

void Inq_SubHusk_IInitialize(void);
void Inq_SubHusk_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AVariation , Sint64 const AX , Sint64 const AY);
Sint64 Inq_SubHusk_IGetIdentifier(void);
Sint64 Inq_SubHusk_IGetTitle(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
Inq_Integral_SArray const* Inq_SubHusk_IGetPropertyArray(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
Sint64 Inq_SubHusk_IGetDescription(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
Sint64 Inq_SubHusk_IGetTooltip(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_SubHusk_IUpdateVideo(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
Inq_Image_SInstance const* Inq_SubHusk_IGetPortrait(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
bool Inq_SubHusk_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
bool Inq_SubHusk_ICanWork(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_SubHusk_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_SubHusk_IDeinitialize(void);