#include"INQCore.h"

void Inq_Partition_IConstruct(Inq_Partition_SInstance *const AInstance)
{
    Inq_Terrain_IConstruct(&AInstance->FTerrain);
}

void Inq_Partition_IUpdate(Inq_Partition_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY)
{
    if(AInstance->FEntity)
    {
        Inq_Entity_SInstance * LEntity = AInstance->FEntity;
        LEntity->FUpdate(AInstance->FEntity , AX , AY);
    }
    else
    {
        Inq_Terrain_IUpdate(&AInstance->FTerrain , AX , AY);
    }
}

void Inq_Partition_IDeconstruct(Inq_Partition_SInstance *const AInstance)
{
    if(AInstance->FEntity)
    {
        Inq_Entity_IDeconstruct(AInstance->FEntity);
    }
    Inq_Terrain_IDeconstruct(&AInstance->FTerrain);
}