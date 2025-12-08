#pragma once

struct Inq_Text_SInstance
{
    Inq_String_SInstance FString;
    TTF_Text * FData;
    double FWidth;
    double FHeight;
};

struct Inq_Text_SArray
{
    Inq_Text_SInstance * FData;
    Sint64 FSize;
    Sint64 FCount;
};

void Inq_Text_IConstruct(Inq_Text_SInstance *const AInstance , TTF_Font *const AFont , Inq_String_SInstance const*const AString , Inq_String_SInstance const*const ALocalization);
Sint32 Inq_Text_ICompare(Inq_String_SInstance const*const AString , Inq_Text_SInstance const*const AInstance);
Sint32 Inq_Text_ICompareText(Inq_Text_SInstance const*const AA , Inq_Text_SInstance const*const AB);
double Inq_Text_IGetWidth(Inq_Text_SInstance const*const AInstance);
double Inq_Text_IGetHeight(Inq_Text_SInstance const*const AInstance);
Sint64 Inq_Text_IGetLineCount(Inq_Text_SInstance const*const AInstance);
void Inq_Text_IDraw(Inq_Text_SInstance const*const AInstance , double const AX , double const AY);
void Inq_Text_IDeconstruct(Inq_Text_SInstance *const AInstance);