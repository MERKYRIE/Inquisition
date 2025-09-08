#include"INQCore.h"

void Inq_Terrain_IConstruct(Inq_Terrain_SInstance *const AInstance)
{
    Inq_Tile_IConstruct(&AInstance->FTile , "CyrillicGoth.ttf" , "Terrain");
}

void Inq_Terrain_IUpdate(Inq_Terrain_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY)
{
    Inq_Tile_IDraw(&AInstance->FTile , AX , AY);
}

void Inq_Terrain_IDeconstruct(Inq_Terrain_SInstance *const AInstance)
{
    Inq_Tile_IDeconstruct(&AInstance->FTile);
}