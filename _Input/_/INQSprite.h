#pragma once

struct Inq_Sprite_SInstance
{
    Inq_Image_SInstance const* FImage;
};

void Inq_Sprite_IConstruct(Inq_Sprite_SInstance *const AInstance , char const*const APath);
void Inq_Sprite_IDraw(Inq_Sprite_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY);
void Inq_Sprite_IDeconstruct(Inq_Sprite_SInstance *const AInstance);