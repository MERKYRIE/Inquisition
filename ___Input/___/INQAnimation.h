#pragma once

struct Inq_Animation_SInstance
{
    Inq_String_SInstance FPath;
    Inq_Frame_SArray FFrameArray;
    Inq_Frame_SInstance * FFrame;
};

struct Inq_Animation_SArray
{
    Inq_Animation_SInstance * FData;
    Sint64 FSize;
    Sint64 FCount;
};

void Inq_Animation_IConstruct(Inq_Animation_SInstance *const AInstance , Inq_String_SInstance const*const APath);
Sint32 Inq_Animation_ICompare(Inq_String_SInstance const*const APath , Inq_Animation_SInstance const*const AAnimation);
Sint32 Inq_Animation_ICompareAnimation(Inq_Animation_SInstance const*const AA , Inq_Animation_SInstance const*const AB);
void Inq_Animation_ISetZeroFrame(Inq_Animation_SInstance *const AInstance);
bool Inq_Animation_IDraw(Inq_Animation_SInstance *const AInstance , double const ATimer , Sint64 const AX , Sint64 const AY , double const AXOffset , double const AYOffset);
void Inq_Animation_IDeconstruct(Inq_Animation_SInstance *const AInstance);