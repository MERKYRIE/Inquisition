#pragma once

struct Inq_Image_SInstance
{
    SDL_Texture * FData;
};

void Inq_Image_IConstruct(Inq_Image_SInstance *const AInstance , Inq_Surface_SInstance *const ASurface);
void Inq_Image_IGetSize(Inq_Image_SInstance const*const AInstance , double *const AWidth , double *const AHeight);
void Inq_Image_IDeconstruct(Inq_Image_SInstance *const AInstance);