#include"INQCore.h"

void Inq_Walking_IConstruct(Inq_Walking_SInstance *const AInstance , char const*const APath)
{
    Inq_Animator_IConstruct(&AInstance->FAnimator , APath);
}

double Inq_Walking_IGetXOffset(Inq_Walking_SInstance const*const AInstance)
{
    return(AInstance->FXOffset);
}

double Inq_Walking_IGetYOffset(Inq_Walking_SInstance const*const AInstance)
{
    return(AInstance->FYOffset);
}

bool Inq_Walking_IIsActive(Inq_Walking_SInstance const*const AInstance)
{
    return(AInstance->FX != 0 || AInstance->FY != 0);
}

void Inq_Walking_IUpdateVideo(Inq_Walking_SInstance *const AInstance , Sint64 const AX , Sint64 const AY)
{
    Inq_Animator_IDraw(&AInstance->FAnimator , AX , AY , AInstance->FXOffset , AInstance->FYOffset);
}

Inq_EntityData_UInstance * Inq_Walking_IUpdate(Inq_Walking_SInstance *const AInstance , Inq_EntityData_UInstance *const AData)
{
    AInstance->FXOffset += AInstance->FX * Inq_Time_IGetRelativeTimestamp() / 1'000.0 / 4.0;
    AInstance->FYOffset += AInstance->FY * Inq_Time_IGetRelativeTimestamp() / 1'000.0 / 4.0;
    if(SDL_fabs(AInstance->FXOffset) >= Inq_Partition_IGetWidth() || SDL_fabs(AInstance->FYOffset) >= Inq_Partition_IGetHeight())
    {
        AInstance->FXOffset = 0.0;
        AInstance->FYOffset = 0.0;
        if(AInstance->FX == -1)
        {
            Inq_Animator_ISetAnimation(&AInstance->FAnimator , "IdleLeft");
        }
        else if(AInstance->FX == 1)
        {
            Inq_Animator_ISetAnimation(&AInstance->FAnimator , "IdleRight");
        }
        else if(AInstance->FY == -1)
        {
            Inq_Animator_ISetAnimation(&AInstance->FAnimator , "IdleUp");
        }
        else if(AInstance->FY == 1)
        {
            Inq_Animator_ISetAnimation(&AInstance->FAnimator , "IdleDown");
        }
        Sint64 LX = AInstance->FX;
        Sint64 LY = AInstance->FY;
        AInstance->FX = 0;
        AInstance->FY = 0;
        Inq_EntityData_UInstance * LData = Inq_Partition_IWalk(AData , LX , LY);
        return(LData);
    }
    return(NULL);
}

bool Inq_Walking_IWalkLeftUp(Inq_Walking_SInstance *const AInstance , Inq_EntityData_UInstance *const AData)
{
    if(Inq_Partition_ICanWalk(AData , -1 , -1))
    {
        AInstance->FX = -1;
        AInstance->FY = -1;
        Inq_Animator_ISetAnimation(&AInstance->FAnimator , "WalkLeft");
        return(true);
    }
    return(false);
}

bool Inq_Walking_IWalkRightUp(Inq_Walking_SInstance *const AInstance , Inq_EntityData_UInstance *const AData)
{
    if(Inq_Partition_ICanWalk(AData , 1 , -1))
    {
        AInstance->FX = 1;
        AInstance->FY = -1;
        Inq_Animator_ISetAnimation(&AInstance->FAnimator , "WalkRight");
        return(true);
    }
    return(false);
}

bool Inq_Walking_IWalkLeftDown(Inq_Walking_SInstance *const AInstance , Inq_EntityData_UInstance *const AData)
{
    if(Inq_Partition_ICanWalk(AData , -1 , 1))
    {
        AInstance->FX = -1;
        AInstance->FY = 1;
        Inq_Animator_ISetAnimation(&AInstance->FAnimator , "WalkLeft");
        return(true);
    }
    return(false);
}

bool Inq_Walking_IWalkRightDown(Inq_Walking_SInstance *const AInstance , Inq_EntityData_UInstance *const AData)
{
    if(Inq_Partition_ICanWalk(AData , 1 , 1))
    {
        AInstance->FX = 1;
        AInstance->FY = 1;
        Inq_Animator_ISetAnimation(&AInstance->FAnimator , "WalkRight");
        return(true);
    }
    return(false);
}

bool Inq_Walking_IWalkLeft(Inq_Walking_SInstance *const AInstance , Inq_EntityData_UInstance *const AData)
{
    if(Inq_Partition_ICanWalk(AData , -1 , 0))
    {
        AInstance->FX = -1;
        AInstance->FY = 0;
        Inq_Animator_ISetAnimation(&AInstance->FAnimator , "WalkLeft");
        return(true);
    }
    return(false);
}

bool Inq_Walking_IWalkRight(Inq_Walking_SInstance *const AInstance , Inq_EntityData_UInstance *const AData)
{
    if(Inq_Partition_ICanWalk(AData , 1 , 0))
    {
        AInstance->FX = 1;
        AInstance->FY = 0;
        Inq_Animator_ISetAnimation(&AInstance->FAnimator , "WalkRight");
        return(true);
    }
    return(false);
}

bool Inq_Walking_IWalkUp(Inq_Walking_SInstance *const AInstance , Inq_EntityData_UInstance *const AData)
{
    if(Inq_Partition_ICanWalk(AData , 0 , -1))
    {
        AInstance->FX = 0;
        AInstance->FY = -1;
        Inq_Animator_ISetAnimation(&AInstance->FAnimator , "WalkUp");
        return(true);
    }
    return(false);
}

bool Inq_Walking_IWalkDown(Inq_Walking_SInstance *const AInstance , Inq_EntityData_UInstance *const AData)
{
    if(Inq_Partition_ICanWalk(AData , 0 , 1))
    {
        AInstance->FX = 0;
        AInstance->FY = 1;
        Inq_Animator_ISetAnimation(&AInstance->FAnimator , "WalkDown");
        return(true);
    }
    return(false);
}

void Inq_Walking_IDeconstruct(Inq_Walking_SInstance *const AInstance)
{
    Inq_Animator_IDeconstruct(&AInstance->FAnimator);
}