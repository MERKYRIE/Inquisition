#include"INQCore.h"

void Inq_Image_IConstruct(Inq_Image_SInstance *const AInstance , Inq_Surface_SInstance *const ASurface)
{
    AInstance->FData = SDL_CreateTextureFromSurface(Inq_Video_IGetRenderer() , ASurface->FData);
    Inq_Debug_IAssertHandle(AInstance->FData);
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

void Inq_Image_IDeconstruct(Inq_Image_SInstance *const AInstance)
{
    SDL_DestroyTexture(AInstance->FData);
}