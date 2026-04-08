#include"INQCore.h"

Sint64 Inq_Player_GIdentifier;
Inq_Integral_SArray Inq_Player_GPropertyArray;
Inq_Entity_SNode const* Inq_Player_GNode;
Sint64 Inq_Player_GOreCount;

void Inq_Player_IInitialize(void)
{
    Inq_Player_GIdentifier = Inq_Entity_IRegister
    (
        &(Inq_EntityStorage_SInstance)
        {
            .FConstruct = &Inq_Player_IConstruct
            ,
            .FGetTitle = &Inq_Player_IGetTitle
            ,
            .FGetPropertyArray = &Inq_Player_IGetPropertyArray
            ,
            .FGetDescription = &Inq_Player_IGetDescription
            ,
            .FGetTooltip = &Inq_Player_IGetTooltip
            ,
            .FUpdateVideo = &Inq_Player_IUpdateVideo
            ,
            .FGetPortrait = &Inq_Player_IGetPortrait
            ,
            .FUpdate = &Inq_Player_IUpdate
            ,
            .FCanWork = NULL
            ,
            .FWork = NULL
            ,
            .FDeconstruct = &Inq_Player_IDeconstruct
        }
    );
    Inq_Array_IConstructSpace(&Inq_Player_GPropertyArray , sizeof(Sint64) , 12);
    for(Sint64 LIndex = 0 ; LIndex < 8 ; LIndex++)
    {
        Inq_Player_GPropertyArray.FData[LIndex] = LIndex + 262;
    }
    for(Sint64 LIndex = 8 ; LIndex < Inq_Player_GPropertyArray.FCount ; LIndex++)
    {
        Inq_Player_GPropertyArray.FData[LIndex] = 258;
    }
}

void Inq_Player_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AVariation , Sint64 const AX , Sint64 const AY)
{
    Inq_Player_GNode = Inq_Entity_IGetNode(AData);
    Inq_Walking_IConstruct(&AData->FPlayer.FWalking , "Commander/Cybernetic");
    Inq_Array_IConstructVoid(&AData->FPlayer.FWidgetArray , sizeof(Inq_Widget_SInstance));
}

Sint64 Inq_Player_IGetIdentifier(void)
{
    return(Inq_Player_GIdentifier);
}

void Inq_Player_IGetOffset(Sint64 const AX , Sint64 const AY , double *const AXOffset , double *const AYOffset)
{
    Sint64 LX;
    Sint64 LY;
    Inq_Partition_IGetPosition(&Inq_Player_GNode->FData->FData , &LX , &LY);
    *AXOffset = (AX - LX) * Inq_Partition_IGetWidth() + Inq_Video_IGetCenterX() - Inq_Partition_IGetWidth() / 2.0 - Inq_Walking_IGetXOffset(&Inq_Player_GNode->FData->FData.FPlayer.FWalking);
    *AYOffset = (AY - LY) * Inq_Partition_IGetHeight() + Inq_Video_IGetCenterY() - Inq_Partition_IGetHeight() / 2.0 - Inq_Walking_IGetYOffset(&Inq_Player_GNode->FData->FData.FPlayer.FWalking);
}

Sint64 Inq_Player_IGetTitle(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(276);
}

Inq_Integral_SArray const* Inq_Player_IGetPropertyArray(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(&Inq_Player_GPropertyArray);
}

Sint64 Inq_Player_IGetDescription(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(277);
}

Sint64 Inq_Player_IGetTooltip(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(278);
}

void Inq_Player_IUpdateVideo(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Walking_IUpdateVideo(&AData->FPlayer.FWalking , AX , AY);
}

Inq_Image_SInstance const* Inq_Player_IGetPortrait(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(Inq_Atlas_ISearch("Portrait/Cybernetic.png"));
}

bool Inq_Player_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    if(Inq_Keyboard_IGetKey(SDL_SCANCODE_P)->FIsPressed)
    {
        Inq_Typeface_IDeinitialize();
        Inq_Typeface_IInitialize("Text/English.txt");
    }
    for(Sint64 LIndex = 0 ; LIndex < AData->FPlayer.FWidgetArray.FCount ; LIndex++)
    {
        Inq_Widget_IDraw(&AData->FPlayer.FWidgetArray.FData[LIndex]);
    }
    if(Inq_Walking_IIsActive(&AData->FPlayer.FWalking))
    {
        return(Inq_Walking_IUpdate(&AData->FPlayer.FWalking , AData) != NULL);
    }
    else if(AData->FPlayer.FInteractionX != 0 || AData->FPlayer.FInteractionY != 0)
    {
        if(Inq_Partition_IWork(AData , AData->FPlayer.FInteractionX , AData->FPlayer.FInteractionY))
        {
            if(AData->FPlayer.FInteractionX == -1)
            {
                Inq_Animator_ISetAnimation(&AData->FPlayer.FWalking.FAnimator , "IdleLeft");
            }
            else if(AData->FPlayer.FInteractionX == 1)
            {
                Inq_Animator_ISetAnimation(&AData->FPlayer.FWalking.FAnimator , "IdleRight");
            }
            else if(AData->FPlayer.FInteractionY == -1)
            {
                Inq_Animator_ISetAnimation(&AData->FPlayer.FWalking.FAnimator , "IdleUp");
            }
            else if(AData->FPlayer.FInteractionY == 1)
            {
                Inq_Animator_ISetAnimation(&AData->FPlayer.FWalking.FAnimator , "IdleDown");
            }
            AData->FPlayer.FInteractionX = 0;
            AData->FPlayer.FInteractionY = 0;
            return(true);
        }
    }
    else if(AData->FPlayer.FWidgetArray.FCount != 0)
    {
        if(Inq_Keyboard_IGetKey(SDL_SCANCODE_TAB)->FIsPressed)
        {
            while(AData->FPlayer.FWidgetArray.FCount != 0)
            {
                Inq_Widget_IDeconstruct(Inq_Array_IGetLast(&AData->FPlayer.FWidgetArray));
                Inq_Array_IPop(&AData->FPlayer.FWidgetArray);
            }
        }
    }
    else
    {
        if(Inq_Keyboard_IGetKey(SDL_SCANCODE_X)->FIsPressed)
        {
            return(true);
        }
        else if(Inq_Keyboard_IGetKey(SDL_SCANCODE_Q)->FIsPressed && !Inq_Walking_IWalkLeftUp(&AData->FPlayer.FWalking , AData) && Inq_Partition_ICanWork(AData , -1 , -1))
        {
            AData->FPlayer.FInteractionX = -1;
            AData->FPlayer.FInteractionY = -1;
            Inq_Animator_ISetAnimation(&AData->FPlayer.FWalking.FAnimator , "WorkLeft");
        }
        else if(Inq_Keyboard_IGetKey(SDL_SCANCODE_E)->FIsPressed && !Inq_Walking_IWalkRightUp(&AData->FPlayer.FWalking , AData) && Inq_Partition_ICanWork(AData , 1 , -1))
        {
            AData->FPlayer.FInteractionX = 1;
            AData->FPlayer.FInteractionY = -1;
            Inq_Animator_ISetAnimation(&AData->FPlayer.FWalking.FAnimator , "WorkRight");
        }
        else if(Inq_Keyboard_IGetKey(SDL_SCANCODE_Z)->FIsPressed && !Inq_Walking_IWalkLeftDown(&AData->FPlayer.FWalking , AData) && Inq_Partition_ICanWork(AData , -1 , 1))
        {
            AData->FPlayer.FInteractionX = -1;
            AData->FPlayer.FInteractionY = 1;
            Inq_Animator_ISetAnimation(&AData->FPlayer.FWalking.FAnimator , "WorkLeft");
        }
        else if(Inq_Keyboard_IGetKey(SDL_SCANCODE_C)->FIsPressed && !Inq_Walking_IWalkRightDown(&AData->FPlayer.FWalking , AData) && Inq_Partition_ICanWork(AData , 1 , 1))
        {
            AData->FPlayer.FInteractionX = 1;
            AData->FPlayer.FInteractionY = 1;
            Inq_Animator_ISetAnimation(&AData->FPlayer.FWalking.FAnimator , "WorkRight");
        }
        else if(Inq_Keyboard_IGetKey(SDL_SCANCODE_A)->FIsPressed && !Inq_Walking_IWalkLeft(&AData->FPlayer.FWalking , AData) && Inq_Partition_ICanWork(AData , -1 , 0))
        {
            AData->FPlayer.FInteractionX = -1;
            AData->FPlayer.FInteractionY = 0;
            Inq_Animator_ISetAnimation(&AData->FPlayer.FWalking.FAnimator , "WorkLeft");
        }
        else if(Inq_Keyboard_IGetKey(SDL_SCANCODE_D)->FIsPressed && !Inq_Walking_IWalkRight(&AData->FPlayer.FWalking , AData) && Inq_Partition_ICanWork(AData , 1 , 0))
        {
            AData->FPlayer.FInteractionX = 1;
            AData->FPlayer.FInteractionY = 0;
            Inq_Animator_ISetAnimation(&AData->FPlayer.FWalking.FAnimator , "WorkRight");
        }
        else if(Inq_Keyboard_IGetKey(SDL_SCANCODE_W)->FIsPressed && !Inq_Walking_IWalkUp(&AData->FPlayer.FWalking , AData) && Inq_Partition_ICanWork(AData , 0 , -1))
        {
            AData->FPlayer.FInteractionX = 0;
            AData->FPlayer.FInteractionY = -1;
            Inq_Animator_ISetAnimation(&AData->FPlayer.FWalking.FAnimator , "WorkUp");
        }
        else if(Inq_Keyboard_IGetKey(SDL_SCANCODE_S)->FIsPressed && !Inq_Walking_IWalkDown(&AData->FPlayer.FWalking , AData) && Inq_Partition_ICanWork(AData , 0 , 1))
        {
            AData->FPlayer.FInteractionX = 0;
            AData->FPlayer.FInteractionY = 1;
            Inq_Animator_ISetAnimation(&AData->FPlayer.FWalking.FAnimator , "WorkDown");
        }
        else if(Inq_Keyboard_IGetKey(SDL_SCANCODE_KP_5)->FIsPressed)
        {
            Inq_Player_IInspect(AData , AX , AY , 0 , 0);
        }
        else if(Inq_Keyboard_IGetKey(SDL_SCANCODE_KP_7)->FIsPressed)
        {
            Inq_Player_IInspect(AData , AX , AY , -1 , -1);
        }
        else if(Inq_Keyboard_IGetKey(SDL_SCANCODE_KP_9)->FIsPressed)
        {
            Inq_Player_IInspect(AData , AX , AY , 1 , -1);
        }
        else if(Inq_Keyboard_IGetKey(SDL_SCANCODE_KP_1)->FIsPressed)
        {
            Inq_Player_IInspect(AData , AX , AY , -1 , 1);
        }
        else if(Inq_Keyboard_IGetKey(SDL_SCANCODE_KP_3)->FIsPressed)
        {
            Inq_Player_IInspect(AData , AX , AY , 1 , 1);
        }
        else if(Inq_Keyboard_IGetKey(SDL_SCANCODE_KP_4)->FIsPressed)
        {
            Inq_Player_IInspect(AData , AX , AY , -1 , 0);
        }
        else if(Inq_Keyboard_IGetKey(SDL_SCANCODE_KP_6)->FIsPressed)
        {
            Inq_Player_IInspect(AData , AX , AY , 1 , 0);
        }
        else if(Inq_Keyboard_IGetKey(SDL_SCANCODE_KP_8)->FIsPressed)
        {
            Inq_Player_IInspect(AData , AX , AY , 0 , -1);
        }
        else if(Inq_Keyboard_IGetKey(SDL_SCANCODE_KP_2)->FIsPressed)
        {
            Inq_Player_IInspect(AData , AX , AY , 0 , 1);
        }
    }
    return(false);
}

void Inq_Player_IInspect(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY , Sint64 const AXOffset , Sint64 const AYOffset)
{
    if(!Inq_Partition_IIsPartitionEmpty(AX + AXOffset , AY + AYOffset))
    {
        Inq_Array_IPush(&AData->FPlayer.FWidgetArray);
        Inq_Widget_IConstructImage
        (
            Inq_Array_IGetLast(&AData->FPlayer.FWidgetArray) , Inq_Atlas_ISearch("Dialogue/Inspection.png") , Inq_Video_IGetCenterX() - 1.556 * 0.5 , Inq_Video_IGetCenterY() - 0.5 , 1.556 * 1.0 , 1.0
        );
        Inq_Array_IPush(&AData->FPlayer.FWidgetArray);
        Inq_Widget_IConstructImage
        (
            Inq_Array_IGetLast(&AData->FPlayer.FWidgetArray) , Inq_Partition_IGetPortrait(AData , AXOffset , AYOffset)
            ,
            Inq_Video_IGetCenterX() + 0.552 , Inq_Video_IGetCenterY() - 0.461 , 0.179 , 0.179
        );
        Inq_Array_IPush(&AData->FPlayer.FWidgetArray);
        Inq_Widget_IConstructText
        (
            Inq_Array_IGetLast(&AData->FPlayer.FWidgetArray) , Inq_Partition_IGetTitle(AData , AXOffset , AYOffset) , Inq_Video_IGetCenterX() - 0.731 , Inq_Video_IGetCenterY() - 0.456
        );
        Inq_Array_IPush(&AData->FPlayer.FWidgetArray);
        Inq_Widget_IConstructText
        (
            Inq_Array_IGetLast(&AData->FPlayer.FWidgetArray) , Inq_Partition_IGetDescription(AData , AXOffset , AYOffset)
            ,
            Inq_Video_IGetCenterX() - 0.731 , Inq_Video_IGetCenterY() - (0.456 - Inq_Typeface_IGetLineSkip())
        );
        double LOffset = Inq_Text_IGetLineCount(Inq_Widget_IGetText(Inq_Array_IGetLast(&AData->FPlayer.FWidgetArray))) * Inq_Typeface_IGetLineSkip();
        Inq_Array_IPush(&AData->FPlayer.FWidgetArray);
        Inq_Widget_IConstructText
        (
            Inq_Array_IGetLast(&AData->FPlayer.FWidgetArray) , Inq_Partition_IGetTooltip(AData , AXOffset , AYOffset)
            ,
            Inq_Video_IGetCenterX() - 0.731 , Inq_Video_IGetCenterY() - (0.456 - Inq_Typeface_IGetLineSkip()) + LOffset
        );
        Inq_Array_IPush(&AData->FPlayer.FWidgetArray);
        Inq_Widget_IConstructText
        (
            Inq_Array_IGetLast(&AData->FPlayer.FWidgetArray) , 279 + (Inq_Player_GOreCount <= 5 ? Inq_Player_GOreCount : 6)
            ,
            Inq_Video_IGetCenterX() - 0.731 , Inq_Video_IGetCenterY() - 0.456 + 2 * Inq_Typeface_IGetLineSkip() + LOffset
        );
        Inq_Integral_SArray const* LPropertyArray = Inq_Partition_IGetPropertyArray(AData , AXOffset , AYOffset);
        for(Sint64 LIndex = 0 ; LIndex < LPropertyArray->FCount ; LIndex++)
        {
            Inq_Array_IPush(&AData->FPlayer.FWidgetArray);
            Inq_Widget_IConstructText
            (
                Inq_Array_IGetLast(&AData->FPlayer.FWidgetArray) , LPropertyArray->FData[LIndex]
                ,
                Inq_Video_IGetCenterX() - 0.731 , Inq_Video_IGetCenterY() - 0.456 + (3 + LIndex) * Inq_Typeface_IGetLineSkip() + LOffset
            );
        }
    }
}

void Inq_Player_IRecordOre(void)
{
    Inq_Player_GOreCount++;
}

void Inq_Player_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Array_IDeconstruct(&AData->FPlayer.FWidgetArray);
    Inq_Walking_IDeconstruct(&AData->FPlayer.FWalking);
}

void Inq_Player_IDeinitialize(void)
{
    Inq_Array_IDeconstruct(&Inq_Player_GPropertyArray);
}