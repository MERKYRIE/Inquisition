#pragma once

struct Inq_Partition_SInstance
{
    Inq_Terrain_SInstance FTerrain;
    Inq_Entity_SInstance FEntity;
};

struct Inq_Partition_Array
{
    Inq_Partition_SInstance * FData;
    Sint64 FSize;
    Sint64 FCount;
};

void Inq_Partition_IInitialize(void);
void Inq_Partition_IConstruct(Sint64 const AIdentifier , Sint64 const AVariation , Sint64 const AX , Sint64 const AY);
bool Inq_Partition_IIsPartitionEmpty(Sint64 const AX , Sint64 const AY);
Inq_Partition_SInstance * Inq_Partition_IGetPartition(Sint64 const AX , Sint64 const AY);
Sint64 Inq_Partition_IGetArrayWidth(void);
Sint64 Inq_Partition_IGetArrayHeight(void);
double Inq_Partition_IGetWidth(void);
double Inq_Partition_IGetHeight(void);
void Inq_Partition_IGetPosition(Inq_EntityData_UInstance const*const AData , Sint64 *const AX , Sint64 *const AY);
Inq_Image_SInstance const* Inq_Partition_IGetPortrait(Inq_EntityData_UInstance const*const AData , Sint64 const AXOffset , Sint64 const AYOffset);
Sint64 Inq_Partition_IGetTitle(Inq_EntityData_UInstance const*const AData , Sint64 const AXOffset , Sint64 const AYOffset);
Inq_Integral_SArray const* Inq_Partition_IGetPropertyArray(Inq_EntityData_UInstance const*const AData , Sint64 const AXOffset , Sint64 const AYOffset);
Sint64 Inq_Partition_IGetDescription(Inq_EntityData_UInstance const*const AData , Sint64 const AXOffset , Sint64 const AYOffset);
Sint64 Inq_Partition_IGetTooltip(Inq_EntityData_UInstance const*const AData , Sint64 const AXOffset , Sint64 const AYOffset);
void Inq_Partition_IUpdate(void);
bool Inq_Partition_ICanWork(Inq_EntityData_UInstance const*const AData , Sint64 const AXOffset , Sint64 const AYOffset);
bool Inq_Partition_IWork(Inq_EntityData_UInstance const*const AData , Sint64 const AXOffset , Sint64 const AYOffset);
bool Inq_Partition_ICanWalk(Inq_EntityData_UInstance const*const AData , Sint64 const AXOffset , Sint64 const AYOffset);
Inq_EntityData_UInstance * Inq_Partition_IWalk(Inq_EntityData_UInstance const*const AData , Sint64 const AXOffset , Sint64 const AYOffset);
void Inq_Partition_IDeconstruct(Sint64 const AX , Sint64 const AY);
void Inq_Partition_IDeinitialize(void);