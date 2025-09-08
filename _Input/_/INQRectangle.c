#include"INQCore.h"

void Inq_Rectangle_IConstruct(Inq_Rectangle_SInstance *const AInstance , double const AX , double const AY , double const AWidth , double const AHeight)
{
    AInstance->FData = (SDL_FRect)
    {
        .x = (float)Inq_Video_IGetPixelCoordinate(AX) , .y = (float)Inq_Video_IGetPixelCoordinate(AY)
        ,
        .w = (float)Inq_Video_IGetPixelCoordinate(AWidth) , .h = (float)Inq_Video_IGetPixelCoordinate(AHeight)
    };
}

void Inq_Rectangle_IDeconstruct(Inq_Rectangle_SInstance *const AInstance)
{
    
}