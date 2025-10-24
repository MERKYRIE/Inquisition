#include"INQCore.h"

Sint64 Inq_HuskRack_GIdentifier;
Inq_Integral_SArray Inq_HuskRack_GPropertyArray;

void Inq_HuskRack_IInitialize(void)
{
    Inq_HuskRack_GIdentifier = Inq_Entity_IRegister
    (
        &(Inq_EntityStorage_SInstance)
        {
            .FConstruct = &Inq_HuskRack_IConstruct
            ,
            .FGetTitle = &Inq_HuskRack_IGetTitle
            ,
            .FGetPropertyArray = &Inq_HuskRack_IGetPropertyArray
            ,
            .FGetDescription = &Inq_HuskRack_IGetDescription
            ,
            .FUpdateVideo = &Inq_HuskRack_IUpdateVideo
            ,
            .FGetPortrait = &Inq_HuskRack_IGetPortrait
            ,
            .FUpdate = &Inq_HuskRack_IUpdate
            ,
            .FCanWork = &Inq_HuskRack_ICanWork
            ,
            .FWork = &Inq_HuskRack_IWork
            ,
            .FDeconstruct = &Inq_HuskRack_IDeconstruct
        }
    );
    Inq_Array_IConstructSpace(&Inq_HuskRack_GPropertyArray , sizeof(Sint64) , 63);
    for(Sint64 LIndex = 0 ; LIndex < Inq_HuskRack_GPropertyArray.FCount ; LIndex++)
    {
        Inq_HuskRack_GPropertyArray.FData[LIndex] = 258;
    }
}

void Inq_HuskRack_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AVariation , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IConstruct(&AData->FHuskRack.FSprite , "System/Husk rack.png");
}

Sint64 Inq_HuskRack_IGetIdentifier(void)
{
    return(Inq_HuskRack_GIdentifier);
}

Sint64 Inq_HuskRack_IGetTitle(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(260);
}


Inq_Integral_SArray const* Inq_HuskRack_IGetPropertyArray(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(&Inq_HuskRack_GPropertyArray);
}

Sint64 Inq_HuskRack_IGetDescription(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(273);
}

void Inq_HuskRack_IUpdateVideo(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IDraw(&AData->FHuskRack.FSprite , AX , AY , 0.0 , 0.0);
}

Inq_Image_SInstance const* Inq_HuskRack_IGetPortrait(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(Inq_Atlas_ISearch("System/Husk rack.png"));
}

bool Inq_HuskRack_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(true);
}

bool Inq_HuskRack_ICanWork(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(Inq_Partition_IIsPartitionEmpty(AX , AY + 1));
}

void Inq_HuskRack_IWork(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Partition_IConstruct(Inq_Husk_IGetIdentifier() , 0 , AX , AY + 1);
}

void Inq_HuskRack_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IDeconstruct(&AData->FHuskRack.FSprite);
}

void Inq_HuskRack_IDeinitialize(void)
{
    Inq_Array_IDeconstruct(&Inq_HuskRack_GPropertyArray);
}