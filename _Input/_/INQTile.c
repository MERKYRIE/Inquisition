#include"INQCore.h"

void Inq_Tile_IConstruct(Inq_Tile_SInstance *const AInstance , char const*const AFont , char const*const AString)
{
    AInstance->FText = Inq_Font_ISearch(Inq_Typeface_ISearch(AFont) , AString);
}

void Inq_Tile_IDraw(Inq_Tile_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY)
{
    Inq_Text_IDraw(AInstance->FText , AX * Inq_Space_IGetPartitionWidth() , AY * Inq_Space_IGetPartitionHeight());
}

void Inq_Tile_IDeconstruct(Inq_Tile_SInstance *const AInstance)
{
    
}