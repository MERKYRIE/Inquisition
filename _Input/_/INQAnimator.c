#include"INQCore.h"

void Inq_Animator_IConstruct(Inq_Animator_SInstance *const AInstance , char const*const APath)
{
    Inq_String_SInstance LPath;
    Inq_String_IConstruct(&LPath , "Image/");
    Inq_String_SInstance LSubpath;
    Inq_String_IConstruct(&LSubpath , APath);
    Inq_String_IAppend(&LPath , &LSubpath);
    Inq_String_SArray LGlob;
    Inq_Glob_IConstruct(&LGlob , LPath.FData , NULL);
    Inq_Array_IConstructSpace(&AInstance->FAnimationArray , sizeof(Inq_Animation_SInstance) , LGlob.FCount);
    for(Sint64 LIndex = 0 ; LIndex < AInstance->FAnimationArray.FCount ; LIndex++)
    {
        Inq_Animation_IConstruct(&AInstance->FAnimationArray.FData[LIndex] , &LGlob.FData[LIndex]);
    }
    Inq_Glob_IDeconstruct(&LGlob);
    Inq_String_IDeconstruct(&LSubpath);
    Inq_String_IDeconstruct(&LPath);
    Inq_Array_ISort(&AInstance->FAnimationArray , &Inq_Animation_ICompareAnimation);
    Inq_Animator_ISetAnimation(AInstance , "IdleDown");
    for(Sint64 LIndex = 0 ; LIndex < AInstance->FAnimationArray.FCount ; LIndex++)
    {
        SDL_Log("%s\n" , AInstance->FAnimationArray.FData[LIndex].FPath.FData);
    }
    SDL_Log("\n");
}

void Inq_Animator_ISetAnimation(Inq_Animator_SInstance *const AInstance , char const*const APath)
{
    Inq_String_SInstance LPath;
    Inq_String_IConstruct(&LPath , APath);
    AInstance->FAnimation = Inq_Array_ISearch(&AInstance->FAnimationArray , &LPath , &Inq_Animation_ICompare);
    Inq_Animation_ISetZeroFrame(AInstance->FAnimation);
    AInstance->FTimer = 0.0;
    Inq_String_IDeconstruct(&LPath);
}

void Inq_Animator_IDraw(Inq_Animator_SInstance *const AInstance , Sint64 const AX , Sint64 const AY , double const AXOffset , double const AYOffset)
{
    AInstance->FTimer += Inq_Time_IGetRelativeTimestamp() / 1000.0;
    if(Inq_Animation_IDraw(AInstance->FAnimation , AInstance->FTimer , AX , AY , AXOffset , AYOffset))
    {
        AInstance->FTimer = 0.0;
    }
}

void Inq_Animator_IDeconstruct(Inq_Animator_SInstance *const AInstance)
{
    for(Sint64 LIndex = 0 ; LIndex < AInstance->FAnimationArray.FCount ; LIndex++)
    {
        Inq_Animation_IDeconstruct(&AInstance->FAnimationArray.FData[LIndex]);
    }
    Inq_Array_IDeconstruct(&AInstance->FAnimationArray);
}