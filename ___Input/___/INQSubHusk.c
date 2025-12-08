#include"INQCore.h"

Sint64 Inq_SubHusk_GIdentifier;
Inq_Integral_SArray Inq_SubHusk_GPropertyArray;

void Inq_SubHusk_IInitialize(void)
{
    Inq_SubHusk_GIdentifier = Inq_Entity_IRegister
    (
        &(Inq_EntityStorage_SInstance)
        {
            .FConstruct = &Inq_SubHusk_IConstruct
            ,
            .FGetTitle = &Inq_SubHusk_IGetTitle
            ,
            .FGetPropertyArray = &Inq_SubHusk_IGetPropertyArray
            ,
            .FGetDescription = &Inq_SubHusk_IGetDescription
            ,
            .FGetTooltip = &Inq_SubHusk_IGetTooltip
            ,
            .FUpdateVideo = &Inq_SubHusk_IUpdateVideo
            ,
            .FGetPortrait = &Inq_SubHusk_IGetPortrait
            ,
            .FUpdate = &Inq_SubHusk_IUpdate
            ,
            .FCanWork = &Inq_SubHusk_ICanWork
            ,
            .FWork = NULL
            ,
            .FDeconstruct = &Inq_SubHusk_IDeconstruct
        }
    );
    Inq_Array_IConstructSpace(&Inq_SubHusk_GPropertyArray , sizeof(Sint64) , 8);
    for(Sint64 LIndex = 0 ; LIndex < Inq_SubHusk_GPropertyArray.FCount ; LIndex++)
    {
        Inq_SubHusk_GPropertyArray.FData[LIndex] = 258;
    }
}

void Inq_SubHusk_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AVariation , Sint64 const AX , Sint64 const AY)
{
    Inq_Walking_IConstruct(&AData->FSubHusk.FWalking , "Crew/Recruitable/Machine slave/Sub-husk");
}

Sint64 Inq_SubHusk_IGetIdentifier(void)
{
    return(Inq_SubHusk_GIdentifier);
}

Sint64 Inq_SubHusk_IGetTitle(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(8);
}

Inq_Integral_SArray const* Inq_SubHusk_IGetPropertyArray(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(&Inq_SubHusk_GPropertyArray);
}

Sint64 Inq_SubHusk_IGetDescription(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(272);
}

Sint64 Inq_SubHusk_IGetTooltip(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(257);
}

void Inq_SubHusk_IUpdateVideo(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Walking_IUpdateVideo(&AData->FSubHusk.FWalking , AX , AY);
}

Inq_Image_SInstance const* Inq_SubHusk_IGetPortrait(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(Inq_Atlas_ISearch("Portrait/Sub-husk.png"));
}

bool Inq_SubHusk_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    if(Inq_Walking_IIsActive(&AData->FSubHusk.FWalking))
    {
        return(Inq_Walking_IUpdate(&AData->FSubHusk.FWalking , AData) != NULL);
    }
    else
    {
        if(Inq_Walking_IWalkLeft(&AData->FSubHusk.FWalking , AData))
        {

        }
        else if(Inq_Walking_IWalkRight(&AData->FSubHusk.FWalking , AData))
        {
        
        }
        else if(Inq_Walking_IWalkUp(&AData->FSubHusk.FWalking , AData))
        {
        
        }
        else if(Inq_Walking_IWalkDown(&AData->FSubHusk.FWalking , AData))
        {
        
        }
        else
        {
            return(true);
        }
    }
    return(false);
}

bool Inq_SubHusk_ICanWork(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(false);
}

void Inq_SubHusk_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Walking_IDeconstruct(&AData->FSubHusk.FWalking);
}

void Inq_SubHusk_IDeinitialize(void)
{
    Inq_Array_IDeconstruct(&Inq_SubHusk_GPropertyArray);
}