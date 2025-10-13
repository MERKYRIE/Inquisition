#pragma once

struct Inq_Sprite_SInstance
{
    Inq_Image_SInstance const* FImage;
    double FXOffset;
    double FYOffset;
};

void Inq_Sprite_IConstruct(Inq_Sprite_SInstance *const AInstance , char const*const APath);
Sint32 Inq_Sprite_ICompare(Inq_String_SInstance const*const APath , Inq_Sprite_SInstance const*const ASprite);
Sint32 Inq_Sprite_ICompareSprite(Inq_Sprite_SInstance const*const AA , Inq_Sprite_SInstance const*const AB);
void Inq_Sprite_IDraw(Inq_Sprite_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY);
void Inq_Sprite_IDeconstruct(Inq_Sprite_SInstance *const AInstance);