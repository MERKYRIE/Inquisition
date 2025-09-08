#include"INQCore.h"

void Inq_Inquisitor_IConstruct(Inq_Inquisitor_SInstance *const AInstance)
{
    AInstance->FUpdate = &Inq_Inquisitor_IUpdate;
    AInstance->FDeconstruct = &Inq_Inquisitor_IDeconstruct;
    Inq_Tile_IConstruct(&AInstance->FTile , "CyrillicGoth.ttf" , "Inquisitor");
}

void Inq_Inquisitor_IUpdate(Inq_Inquisitor_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY)
{
    Inq_Tile_IDraw(&AInstance->FTile , AX , AY);
}

void Inq_Inquisitor_IDeconstruct(Inq_Inquisitor_SInstance *const AInstance)
{
    Inq_Tile_IDeconstruct(&AInstance->FTile);
}