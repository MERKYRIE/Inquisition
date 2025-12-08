#include"INQCore.h"

Sint64 Inq_Husk_GIdentifier;
Inq_Integral_SArray Inq_Husk_GPropertyArray;

void Inq_Husk_IInitialize(void)
{
    Inq_Husk_GIdentifier = Inq_Entity_IRegister
    (
        &(Inq_EntityStorage_SInstance)
        {
            .FConstruct = &Inq_Husk_IConstruct
            ,
            .FGetTitle = &Inq_Husk_IGetTitle
            ,
            .FGetPropertyArray = &Inq_Husk_IGetPropertyArray
            ,
            .FGetDescription = &Inq_Husk_IGetDescription
            ,
            .FGetTooltip = &Inq_Husk_IGetTooltip
            ,
            .FUpdateVideo = &Inq_Husk_IUpdateVideo
            ,
            .FGetPortrait = &Inq_Husk_IGetPortrait
            ,
            .FUpdate = &Inq_Husk_IUpdate
            ,
            .FCanWork = &Inq_Husk_ICanWork
            ,
            .FWork = &Inq_Husk_IWork
            ,
            .FDeconstruct = &Inq_Husk_IDeconstruct
        }
    );
    Inq_Array_IConstructSpace(&Inq_Husk_GPropertyArray , sizeof(Sint64) , 16);
    for(Sint64 LIndex = 0 ; LIndex < Inq_Husk_GPropertyArray.FCount ; LIndex++)
    {
        Inq_Husk_GPropertyArray.FData[LIndex] = 258;
    }
}

void Inq_Husk_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AVariation , Sint64 const AX , Sint64 const AY)
{
    Inq_Walking_IConstruct(&AData->FHusk.FWalking , "Crew/Recruitable/Machine slave/Husk");
}

Sint64 Inq_Husk_IGetIdentifier(void)
{
    return(Inq_Husk_GIdentifier);
}

Sint64 Inq_Husk_IGetTitle(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(3);
}

Inq_Integral_SArray const* Inq_Husk_IGetPropertyArray(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(&Inq_Husk_GPropertyArray);
}

Sint64 Inq_Husk_IGetDescription(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(271);
}

Sint64 Inq_Husk_IGetTooltip(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(257);
}

void Inq_Husk_IUpdateVideo(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Walking_IUpdateVideo(&AData->FHusk.FWalking , AX , AY);
}

Inq_Image_SInstance const* Inq_Husk_IGetPortrait(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(Inq_Atlas_ISearch("Portrait/Husk.png"));
}

bool Inq_Husk_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    if(Inq_Walking_IIsActive(&AData->FHusk.FWalking))
    {
        return(Inq_Walking_IUpdate(&AData->FHusk.FWalking , AData) != NULL);
    }
    else if(AData->FHusk.FInteractionX != 0 || AData->FHusk.FInteractionY != 0)
    {
        if(Inq_Partition_IWork(AData , AData->FHusk.FInteractionX , AData->FHusk.FInteractionY))
        {
            if(AData->FHusk.FInteractionX == -1)
            {
                Inq_Animator_ISetAnimation(&AData->FHusk.FWalking.FAnimator , "IdleLeft");
            }
            else if(AData->FHusk.FInteractionX == 1)
            {
                Inq_Animator_ISetAnimation(&AData->FHusk.FWalking.FAnimator , "IdleRight");
            }
            else if(AData->FHusk.FInteractionY == -1)
            {
                Inq_Animator_ISetAnimation(&AData->FHusk.FWalking.FAnimator , "IdleUp");
            }
            else if(AData->FHusk.FInteractionY == 1)
            {
                Inq_Animator_ISetAnimation(&AData->FHusk.FWalking.FAnimator , "IdleDown");
            }
            AData->FHusk.FInteractionX = 0;
            AData->FHusk.FInteractionY = 0;
            return(true);
        }
    }
    else
    {
        for(Sint64 LY = 0 ; LY < Inq_Partition_IGetArrayHeight() ; LY++)
        {
            for(Sint64 LX = 0 ; LX < Inq_Partition_IGetArrayWidth() ; LX++)
            {
                if(Inq_Partition_IGetPartition(LX , LY)->FEntity.FIdentifier == Inq_Ore_IGetIdentifier())
                {
                    if(LX - AX < -1)
                    {
                        Inq_Walking_IWalkLeft(&AData->FHusk.FWalking , AData);
                    }
                    else if(LX - AX > 1)
                    {
                        Inq_Walking_IWalkRight(&AData->FHusk.FWalking , AData);
                    }
                    else if(LY - AY < -1)
                    {
                        Inq_Walking_IWalkUp(&AData->FHusk.FWalking , AData);
                    }
                    else if(LY - AY > 1)
                    {
                        Inq_Walking_IWalkDown(&AData->FHusk.FWalking , AData);
                    }
                    else
                    {
                        AData->FHusk.FInteractionX = LX - AX;
                        AData->FHusk.FInteractionY = LY - AY;
                        if(AData->FHusk.FInteractionX == -1)
                        {
                            Inq_Animator_ISetAnimation(&AData->FHusk.FWalking.FAnimator , "WorkLeft");
                        }
                        else if(AData->FHusk.FInteractionX == 1)
                        {
                            Inq_Animator_ISetAnimation(&AData->FHusk.FWalking.FAnimator , "WorkRight");
                        }
                        else if(AData->FHusk.FInteractionY == -1)
                        {
                            Inq_Animator_ISetAnimation(&AData->FHusk.FWalking.FAnimator , "WorkUp");
                        }
                        else if(AData->FHusk.FInteractionY == 1)
                        {
                            Inq_Animator_ISetAnimation(&AData->FHusk.FWalking.FAnimator , "WorkDown");
                        }
                    }
                }
            }
        }
    }
    return(false);
}

bool Inq_Husk_ICanWork(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(true);
}

bool Inq_Husk_IWork(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(true);
}

void Inq_Husk_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Walking_IDeconstruct(&AData->FHusk.FWalking);
}

void Inq_Husk_IDeinitialize(void)
{
    Inq_Array_IDeconstruct(&Inq_Husk_GPropertyArray);
}