#pragma once

struct Inq_Terrain_SInstance
{
    Inq_Name_SInstance FName;
};

void Inq_Terrain_IConstruct(Inq_Terrain_SInstance *const AInstance , Sint64 const AIdentifier , Sint64 const AX , Sint64 const AY);
void Inq_Terrain_IUpdate(Inq_Terrain_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY);
void Inq_Terrain_IDeconstruct(Inq_Terrain_SInstance *const AInstance , Sint64 const AX , Sint64 const AY);