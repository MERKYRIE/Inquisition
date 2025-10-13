#include"INQCore.h"

void Inq_Frame_IConstruct(Inq_Frame_SInstance *const AInstance , Inq_String_SInstance const*const APath , double const ADuration)
{
    Inq_Sprite_IConstruct(&AInstance->FSprite , Inq_String_IFind(APath , '/' , 1));
    AInstance->FDuration = ADuration;
}

Sint32 Inq_Frame_ICompare(Inq_String_SInstance const*const APath , Inq_Frame_SInstance const*const AFrame)
{
    return(Inq_Sprite_ICompare(APath , &AFrame->FSprite));
}

Sint32 Inq_Frame_ICompareFrame(Inq_Frame_SInstance const*const AA , Inq_Frame_SInstance const*const AB)
{
    return(Inq_Sprite_ICompareSprite(&AA->FSprite , &AB->FSprite));
}

void Inq_Frame_IDraw(Inq_Frame_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IDraw(&AInstance->FSprite , AX , AY);
}

void Inq_Frame_IDeconstruct(Inq_Frame_SInstance *const AInstance)
{
    Inq_Sprite_IDeconstruct(&AInstance->FSprite);
}