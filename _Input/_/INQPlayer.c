#include"INQCore.h"

Sint64 Inq_Player_GIdentifier;
Inq_Entity_SNode const* Inq_Player_GNode;

void Inq_Player_IInitialize(void)
{
    Inq_Player_GIdentifier = Inq_Entity_IRegister
    (
        &(Inq_EntityStorage_SInstance)
        {
            .FConstruct = &Inq_Player_IConstruct
            ,
            .FUpdateVideo = &Inq_Player_IUpdateVideo
            ,
            .FUpdate = &Inq_Player_IUpdate
            ,
            .FDeconstruct = &Inq_Player_IDeconstruct
        }
    );
}

void Inq_Player_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Player_GNode = Inq_Entity_IGetNode(AData);
    Inq_Animator_IConstruct(&AData->FPlayer.FAnimator , "Player");
}

void Inq_Player_IGetOffset(Sint64 const AX , Sint64 const AY , double *const AXOffset , double *const AYOffset)
{
    Sint64 LX;
    Sint64 LY;
    Inq_Partition_IGetPosition(&Inq_Player_GNode->FData->FData , &LX , &LY);
    *AXOffset = (AX - LX) * Inq_Partition_IGetWidth() + Inq_Video_IGetCenterX() - Inq_Partition_IGetWidth() / 2.0 - Inq_Player_GNode->FData->FData.FPlayer.FXOffset;
    *AYOffset = (AY - LY) * Inq_Partition_IGetHeight() + Inq_Video_IGetCenterY() - Inq_Partition_IGetHeight() / 2.0 - Inq_Player_GNode->FData->FData.FPlayer.FYOffset;
}

void Inq_Player_IUpdateVideo(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Animator_IDraw(&AData->FPlayer.FAnimator , AX , AY);
}

bool Inq_Player_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    if(Inq_Keyboard_IGetKey(SDL_SCANCODE_A)->FIsPressed && Inq_Partition_ICanMove(AData , -1 , 0))
    {
        AData->FPlayer.FMovementX = -1;
        AData->FPlayer.FMovementY = 0;
    }
    if(Inq_Keyboard_IGetKey(SDL_SCANCODE_D)->FIsPressed && Inq_Partition_ICanMove(AData , 1 , 0))
    {
        AData->FPlayer.FMovementX = 1;
        AData->FPlayer.FMovementY = 0;
    }
    if(Inq_Keyboard_IGetKey(SDL_SCANCODE_W)->FIsPressed && Inq_Partition_ICanMove(AData , 0 , -1))
    {
        AData->FPlayer.FMovementX = 0;
        AData->FPlayer.FMovementY = -1;
    }
    if(Inq_Keyboard_IGetKey(SDL_SCANCODE_S)->FIsPressed && Inq_Partition_ICanMove(AData , 0 , 1))
    {
        AData->FPlayer.FMovementX = 0;
        AData->FPlayer.FMovementY = 1;
    }
    if(AData->FPlayer.FMovementX != 0 || AData->FPlayer.FMovementY != 0)
    {
        AData->FPlayer.FXOffset += AData->FPlayer.FMovementX * Inq_Time_IGetRelativeTimestamp() / 1'000 / 5.0;
        AData->FPlayer.FYOffset += AData->FPlayer.FMovementY * Inq_Time_IGetRelativeTimestamp() / 1'000 / 5.0;
        if(SDL_fabs(AData->FPlayer.FXOffset) >= Inq_Partition_IGetWidth() || SDL_fabs(AData->FPlayer.FYOffset) >= Inq_Partition_IGetHeight())
        {
            Sint64 LMovementX = AData->FPlayer.FMovementX;
            Sint64 LMovementY = AData->FPlayer.FMovementY;
            AData->FPlayer.FMovementX = 0;
            AData->FPlayer.FMovementY = 0;
            AData->FPlayer.FXOffset = 0.0;
            AData->FPlayer.FYOffset = 0.0;
            Inq_Partition_IMove(AData , LMovementX , LMovementY);
            return(true);
        }
    }
    return(false);
}

void Inq_Player_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Animator_IDeconstruct(&AData->FPlayer.FAnimator);
}

void Inq_Player_IDeinitialize(void)
{

}