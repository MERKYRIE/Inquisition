#pragma once

struct Inq_Font_SInstance
{       
    Inq_String_SInstance FPath;
    TTF_Font * FData;
    Inq_Text_SArray FTextArray;
};

struct Inq_Font_SArray
{
    Inq_Font_SInstance * FData;
    Sint64 FSize;
    Sint64 FCount;
};

void Inq_Font_IConstruct(Inq_Font_SInstance *const AInstance , Inq_String_SInstance const*const APath , TTF_HorizontalAlignment const AAlignment);
Sint32 Inq_Font_ICompare(Inq_String_SInstance const*const APath , Inq_Font_SInstance const*const AFont);
Sint32 Inq_Font_ICompareFont(Inq_Font_SInstance const*const AA , Inq_Font_SInstance const*const AB);
Inq_Text_SInstance const* Inq_Font_ISearch(Inq_Font_SInstance const*const AInstance , Sint64 const AIdentifier);
void Inq_Font_IDeconstruct(Inq_Font_SInstance *const AInstance);