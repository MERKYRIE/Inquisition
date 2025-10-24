#pragma once

struct Inq_Husk_SInstance
{
    Inq_Walking_SInstance FWalking;
};

void Inq_Husk_IInitialize(void);
void Inq_Husk_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AVariation , Sint64 const AX , Sint64 const AY);
Sint64 Inq_Husk_IGetIdentifier(void);
Sint64 Inq_Husk_IGetTitle(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
Inq_Integral_SArray const* Inq_Husk_IGetPropertyArray(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
Sint64 Inq_Husk_IGetDescription(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Husk_IUpdateVideo(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
Inq_Image_SInstance const* Inq_Husk_IGetPortrait(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
bool Inq_Husk_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
bool Inq_Husk_ICanWork(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Husk_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Husk_IDeinitialize(void);