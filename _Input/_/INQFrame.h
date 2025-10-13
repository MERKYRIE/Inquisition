#pragma once

struct Inq_Frame_SInstance
{
    Inq_Sprite_SInstance FSprite;
    double FDuration;
};

struct Inq_Frame_SArray
{
    Inq_Frame_SInstance * FData;
    Sint64 FSize;
    Sint64 FCount;
};

void Inq_Frame_IConstruct(Inq_Frame_SInstance *const AInstance , Inq_String_SInstance const*const APath , double const ADuration);
Sint32 Inq_Frame_ICompare(Inq_String_SInstance const*const APath , Inq_Frame_SInstance const*const AFrame);
Sint32 Inq_Frame_ICompareFrame(Inq_Frame_SInstance const*const AA , Inq_Frame_SInstance const*const AB);
void Inq_Frame_IDraw(Inq_Frame_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY);
void Inq_Frame_IDeconstruct(Inq_Frame_SInstance *const AInstance);