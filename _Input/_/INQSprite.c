#include"INQCore.h"

void Inq_Sprite_IConstruct(Inq_Sprite_SInstance *const AInstance , char const*const APath)
{
    AInstance->FImage = Inq_Atlas_ISearch(APath);
    AInstance->FXOffset =
    (
        Inq_Partition_IGetWidth() - Inq_Image_IGetWidth(AInstance->FImage) * Inq_Real_IGetMinimum
        (
            Inq_Partition_IGetWidth() / Inq_Image_IGetWidth(AInstance->FImage) , Inq_Partition_IGetHeight() / Inq_Image_IGetHeight(AInstance->FImage)
        )
    )
    / 2.0;
    AInstance->FYOffset =
    (
        Inq_Partition_IGetHeight() - Inq_Image_IGetHeight(AInstance->FImage) * Inq_Real_IGetMinimum
        (
            Inq_Partition_IGetWidth() / Inq_Image_IGetWidth(AInstance->FImage) , Inq_Partition_IGetHeight() / Inq_Image_IGetHeight(AInstance->FImage)
        )
    )
    / 2.0;
}

void Inq_Sprite_IDraw(Inq_Sprite_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY)
{
    Inq_Rectangle_SInstance LViewport;
    Inq_Rectangle_IConstruct
    (
        &LViewport
        ,
        AX * Inq_Partition_IGetWidth() + AInstance->FXOffset
        ,
        AY * Inq_Partition_IGetHeight() + AInstance->FYOffset
        ,
        Inq_Image_IGetWidth(AInstance->FImage) * Inq_Real_IGetMinimum
        (
            Inq_Partition_IGetWidth() / Inq_Image_IGetWidth(AInstance->FImage) , Inq_Partition_IGetHeight() / Inq_Image_IGetHeight(AInstance->FImage)
        )
        ,
        Inq_Image_IGetHeight(AInstance->FImage) * Inq_Real_IGetMinimum
        (
            Inq_Partition_IGetWidth() / Inq_Image_IGetWidth(AInstance->FImage) , Inq_Partition_IGetHeight() / Inq_Image_IGetHeight(AInstance->FImage)
        )
    );
    Inq_Image_IDraw(AInstance->FImage , &LViewport);
    Inq_Rectangle_IDeconstruct(&LViewport);
}

void Inq_Sprite_IDeconstruct(Inq_Sprite_SInstance *const AInstance)
{
    
}