#include"INQCore.h"

void Inq_Text_IConstruct(Inq_Text_SInstance *const AInstance , TTF_Font *const AFont , Inq_String_SInstance const*const AString , Inq_String_SInstance const*const ALocalization)
{
    Inq_String_IConstruct(&AInstance->FString , AString->FData);
    Inq_Debug_IAssertHandle(AInstance->FData = TTF_CreateText(Inq_Typeface_IGetEngine() , AFont , ALocalization->FData , ALocalization->FCount));
    Inq_Debug_IAssertCondition(TTF_SetTextColor(AInstance->FData , 100 , 100 , 100 , SDL_ALPHA_OPAQUE));
}

double Inq_Text_IGetWidth(Inq_Text_SInstance const*const AInstance)
{
    return(0.0);
}

double Inq_Text_IGetHeight(Inq_Text_SInstance const*const AInstance)
{
    return(0.0);
}

double Inq_Text_IGetMinimum(Inq_Text_SInstance const*const AInstance)
{
    return(0.0);
}

double Inq_Text_IGetMaximum(Inq_Text_SInstance const*const AInstance)
{
    return(0.0);
}

Sint32 Inq_Text_ICompare(Inq_String_SInstance const*const AString , Inq_Text_SInstance const*const AInstance)
{
    return(Inq_String_ICompare(AString , &AInstance->FString));
}

Sint32 Inq_Text_ICompareText(Inq_Text_SInstance const*const AA , Inq_Text_SInstance const*const AB)
{
    return(Inq_Text_ICompare(&AA->FString , AB));
}

void Inq_Text_IDraw(Inq_Text_SInstance const*const AInstance , double const AX , double const AY)
{
    Inq_Debug_IAssertCondition(TTF_DrawRendererText(AInstance->FData , (float)Inq_Video_IGetPixelCoordinate(AX) , (float)Inq_Video_IGetPixelCoordinate(AY)));
}

void Inq_Text_IDeconstruct(Inq_Text_SInstance *const AInstance)
{
    TTF_DestroyText(AInstance->FData);
    Inq_String_IDeconstruct(&AInstance->FString);
}