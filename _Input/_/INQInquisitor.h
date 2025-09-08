#pragma once

struct Inq_Inquisitor_SInstance
{
    void (*FUpdate)(Inq_Inquisitor_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY);
    void (*FDeconstruct)(Inq_Inquisitor_SInstance *const AInstance);
    Inq_Tile_SInstance FTile;
};

void Inq_Inquisitor_IConstruct(Inq_Inquisitor_SInstance *const AInstance);
void Inq_Inquisitor_IUpdate(Inq_Inquisitor_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY);
void Inq_Inquisitor_IDeconstruct(Inq_Inquisitor_SInstance *const AInstance);