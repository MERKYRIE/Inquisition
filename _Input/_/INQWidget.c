#include"INQCore.h"

void Inq_Widget_IConstructImage(Inq_Widget_SInstance *const AInstance , Inq_Image_SInstance const* AImage , double const AX , double const AY , double const AWidth , double const AHeight)
{
    AInstance->FImage = AImage;
    AInstance->FText = NULL;
    Inq_Rectangle_IConstruct(&AInstance->FViewport , AX , AY , AWidth , AHeight);
    AInstance->FIsText = false;
}

void Inq_Widget_IConstructText(Inq_Widget_SInstance *const AInstance , Sint64 const AIdentifier , double const AX , double const AY)
{
    AInstance->FImage = NULL;
    AInstance->FText = Inq_Font_ISearch(Inq_Typeface_ISearch("CyrillicGoth.ttf") , AIdentifier);
    Inq_Rectangle_IConstruct(&AInstance->FViewport , 0.0 , 0.0 , 0.0 , 0.0);
    AInstance->FViewport.FData.x = (float)AX;
    AInstance->FViewport.FData.y = (float)AY;
    AInstance->FIsText = true;
}

void Inq_Widget_IDraw(Inq_Widget_SInstance const*const AInstance)
{
    if(!AInstance->FIsText)
    {
        Inq_Image_IDraw(AInstance->FImage , &AInstance->FViewport);
    }
    else
    {
        Inq_Text_IDraw(AInstance->FText , AInstance->FViewport.FData.x , AInstance->FViewport.FData.y);
    }
}

void Inq_Widget_IDeconstruct(Inq_Widget_SInstance *const AInstance)
{
    Inq_Rectangle_IDeconstruct(&AInstance->FViewport);
}