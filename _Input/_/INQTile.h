#pragma once

struct Inq_Tile_SInstance
{
    Inq_Text_SInstance const* FText;
};

void Inq_Tile_IConstruct(Inq_Tile_SInstance *const AInstance , char const*const AFont , char const*const AString);
void Inq_Tile_IDraw(Inq_Tile_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY);
void Inq_Tile_IDeconstruct(Inq_Tile_SInstance *const AInstance);