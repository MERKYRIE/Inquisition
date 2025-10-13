#include"INQCore.h"

void Inq_Animation_IConstruct(Inq_Animation_SInstance *const AInstance , Inq_String_SInstance const*const APath)
{
    Inq_String_IConstruct(&AInstance->FPath , Inq_String_IFind(APath , '/' , 2));
    Inq_String_SArray LGlob;
    Inq_Glob_IConstruct(&LGlob , APath->FData , "*.png");
    Inq_Array_IConstructSpace(&AInstance->FFrameArray , sizeof(Inq_Frame_SInstance) , LGlob.FCount);
    for(Sint64 LIndex = 0 ; LIndex < AInstance->FFrameArray.FCount ; LIndex++)
    {
        Inq_Frame_IConstruct(&AInstance->FFrameArray.FData[LIndex] , &LGlob.FData[LIndex] , 0.5);
    }
    Inq_Glob_IDeconstruct(&LGlob);
    Inq_Array_ISort(&AInstance->FFrameArray , &Inq_Frame_ICompareFrame);
    for(Sint64 LIndex = 0 ; LIndex < AInstance->FFrameArray.FCount ; LIndex++)
    {
        SDL_Log("%s\n" , AInstance->FFrameArray.FData[LIndex].FSprite.FImage->FPath.FData);
    }
    SDL_Log("\n");
}

Sint32 Inq_Animation_ICompare(Inq_String_SInstance const*const APath , Inq_Animation_SInstance const*const AAnimation)
{
    return(Inq_String_ICompare(APath , &AAnimation->FPath));
}

Sint32 Inq_Animation_ICompareAnimation(Inq_Animation_SInstance const*const AA , Inq_Animation_SInstance const*const AB)
{
    return(Inq_Animation_ICompare(&AA->FPath , AB));
}

void Inq_Animation_IDraw(Inq_Animation_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY)
{
    Inq_Frame_IDraw(&AInstance->FFrameArray.FData[0] , AX , AY);
}

void Inq_Animation_IDeconstruct(Inq_Animation_SInstance *const AInstance)
{
    for(Sint64 LIndex = 0 ; LIndex < AInstance->FFrameArray.FCount ; LIndex++)
    {
        Inq_Frame_IDeconstruct(&AInstance->FFrameArray.FData[LIndex]);
    }
    Inq_Array_IDeconstruct(&AInstance->FFrameArray);
    Inq_String_IDeconstruct(&AInstance->FPath);
}