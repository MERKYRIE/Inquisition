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
void Inq_Partition_IConstruct(Sint64 const AIdentifier , Sint64 const AX , Sint64 const AY);
Inq_Partition_SInstance * Inq_Partition_IGetPartition(Sint64 const AX , Sint64 const AY);
double Inq_Partition_IGetWidth(void);
double Inq_Partition_IGetHeight(void);
void Inq_Partition_IGetPosition(Inq_EntityData_UInstance const*const AData , Sint64 *const AX , Sint64 *const AY);
bool Inq_Partition_ICanMove(Inq_EntityData_UInstance const*const AData , Sint64 const AXOffset , Sint64 const AYOffset);
void Inq_Partition_IMove(Inq_EntityData_UInstance const*const AData , Sint64 const AXOffset , Sint64 const AYOffset);
void Inq_Partition_IDeconstruct(Sint64 const AX , Sint64 const AY);
void Inq_Partition_IDeinitialize(void);