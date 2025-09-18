#include"INQCore.h"

void Inq_Terrain_IConstruct(Inq_Terrain_SInstance *const AInstance , Sint64 const AX , Sint64 const AY)
{
    Inq_Name_IConstruct(&AInstance->FName , "CyrillicGoth.ttf" , "Terrain");
}

void Inq_Terrain_IUpdate(Inq_Terrain_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY)
{
    Inq_Name_IDraw(&AInstance->FName , AX , AY);
}

void Inq_Terrain_IDeconstruct(Inq_Terrain_SInstance *const AInstance , Sint64 const AX , Sint64 const AY)
{
    Inq_Name_IDeconstruct(&AInstance->FName);
}