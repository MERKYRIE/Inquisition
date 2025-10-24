#pragma once

struct Inq_Ore_SInstance
{
    Inq_Name_SInstance FName;
};

void Inq_Ore_IInitialize(void);
void Inq_Ore_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AVariation , Sint64 const AX , Sint64 const AY);
Sint64 Inq_Ore_IGetIdentifier(void);
Sint64 Inq_Ore_IGetTitle(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
Inq_Integral_SArray const* Inq_Ore_IGetPropertyArray(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
Sint64 Inq_Ore_IGetDescription(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Ore_IUpdateVideo(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY);
bool Inq_Ore_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
Inq_Image_SInstance const* Inq_Ore_IGetPortrait(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
bool Inq_Ore_ICanWork(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Ore_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Ore_IDeinitialize(void);