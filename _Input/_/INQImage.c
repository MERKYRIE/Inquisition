#include"INQCore.h"

void Inq_Image_IConstruct(Inq_Image_SInstance *const AInstance , Inq_String_SInstance const*const APath)
{
    Inq_String_IConstruct(&AInstance->FPath , Inq_String_IFind(APath , '/'));
    Inq_Debug_IAssertHandle(AInstance->FData = IMG_LoadTexture(Inq_Video_IGetRenderer() , APath->FData));
    Inq_Debug_IAssertCondition(SDL_SetTextureScaleMode(AInstance->FData , SDL_SCALEMODE_NEAREST));
}

Sint32 Inq_Image_ICompare(Inq_String_SInstance const*const APath , Inq_Image_SInstance const*const AImage)
{
    return(Inq_String_ICompare(APath , &AImage->FPath));
}

Sint32 Inq_Image_ICompareImage(Inq_Image_SInstance const*const AA , Inq_Image_SInstance const*const AB)
{
    return(Inq_Image_ICompare(&AA->FPath , AB));
}

void Inq_Image_IGetSize(Inq_Image_SInstance const*const AInstance , double *const AWidth , double *const AHeight)
{
    float LWidth;
    float LHeight;
    SDL_GetTextureSize(AInstance->FData , &LWidth , &LHeight);
    if(AWidth)
    {
        *AWidth = LWidth;
    }
    if(AHeight)
    {
        *AHeight = LHeight;
    }
}

void Inq_Image_IDraw(Inq_Image_SInstance const*const AInstance , Inq_Rectangle_SInstance const*const AViewport)
{
    Inq_Debug_IAssertCondition(SDL_RenderTexture(Inq_Video_IGetRenderer() , AInstance->FData , NULL , &AViewport->FData));
}

void Inq_Image_IDeconstruct(Inq_Image_SInstance *const AInstance)
{
    SDL_DestroyTexture(AInstance->FData);
    Inq_String_IDeconstruct(&AInstance->FPath);
}