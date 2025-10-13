#include"INQCore.h"

void Inq_Name_IConstruct(Inq_Name_SInstance *const AInstance , char const*const AFont , char const*const AString)
{
    AInstance->FText = Inq_Font_ISearch(Inq_Typeface_ISearch(AFont) , AString);
    AInstance->FXOffset = (Inq_Partition_IGetWidth() - Inq_Text_IGetWidth(AInstance->FText)) / 2.0;
    AInstance->FYOffset = (Inq_Partition_IGetHeight() - Inq_Text_IGetHeight(AInstance->FText)) / 2.0;
}

void Inq_Name_IDraw(Inq_Name_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY)
{
    double LXOffset;
    double LYOffset;
    Inq_Player_IGetOffset(AX , AY , &LXOffset , &LYOffset);
    Inq_Text_IDraw(AInstance->FText , LXOffset + AInstance->FXOffset , LYOffset + AInstance->FYOffset);
}

void Inq_Name_IDeconstruct(Inq_Name_SInstance *const AInstance)
{
    
}