#pragma once

struct Inq_Partition_SInstance
{
    Inq_Terrain_SInstance FTerrain;
    void * FEntity;
};

void Inq_Partition_IConstruct(Inq_Partition_SInstance *const AInstance);
void Inq_Partition_IUpdate(Inq_Partition_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY);
void Inq_Partition_IDeconstruct(Inq_Partition_SInstance *const AInstance);