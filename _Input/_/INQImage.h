#pragma once

struct Inq_Image_SInstance
{
    Inq_String_SInstance FPath;
    SDL_Texture * FData;
    double FWidth;
    double FHeight;
};

struct Inq_Image_SArray
{
    Inq_Image_SInstance * FData;
    Sint64 FSize;
    Sint64 FCount;
};

void Inq_Image_IConstruct(Inq_Image_SInstance *const AInstance , Inq_String_SInstance const*const APath);
Sint32 Inq_Image_ICompare(Inq_String_SInstance const*const APath , Inq_Image_SInstance const*const AImage);
Sint32 Inq_Image_ICompareImage(Inq_Image_SInstance const*const AA , Inq_Image_SInstance const*const AB);
double Inq_Image_IGetWidth(Inq_Image_SInstance const*const AInstance);
double Inq_Image_IGetHeight(Inq_Image_SInstance const*const AInstance);
void Inq_Image_IDraw(Inq_Image_SInstance const*const AInstance , Inq_Rectangle_SInstance const*const AViewport);
void Inq_Image_IDeconstruct(Inq_Image_SInstance *const AInstance);