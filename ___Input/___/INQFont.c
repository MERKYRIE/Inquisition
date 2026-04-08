#include"INQCore.h"

void Inq_Font_IConstruct(Inq_Font_SInstance *const AInstance , Inq_String_SInstance const*const APath , TTF_HorizontalAlignment const AAlignment , char const*const ALocalization)
{
    Inq_String_IConstruct(&AInstance->FPath , Inq_String_IFind(APath , '/' , 1));
    Inq_Array_IConstructVoid(&AInstance->FTextArray , sizeof(Inq_Text_SInstance));
    Inq_Debug_IAssertHandle(AInstance->FData = TTF_OpenFont(APath->FData , 16));
    TTF_SetFontWrapAlignment(AInstance->FData , AAlignment);
    TTF_SetFontLineSkip(AInstance->FData , (Sint32)Inq_Video_IGetPixelCoordinate(Inq_Typeface_IGetLineSkip()));
    Inq_File_SInstance LEnglishFile;
    Inq_File_IConstruct(&LEnglishFile , "Text/English.txt");
    Inq_File_SInstance LRussianFile;
    Inq_File_IConstruct(&LRussianFile , ALocalization);
    Inq_String_SInstance LEnglishString;
    Inq_String_IConstructVoid(&LEnglishString);
    Inq_String_SInstance LRussianString;
    Inq_String_IConstructVoid(&LRussianString);
    while(Inq_File_IReadString(&LEnglishFile , &LEnglishString , false) && Inq_File_IReadString(&LRussianFile , &LRussianString , false))
    {
        Inq_Array_IPush(&AInstance->FTextArray);
        Inq_Text_IConstruct(Inq_Array_IGetLast(&AInstance->FTextArray) , AInstance->FData , &LEnglishString , &LRussianString);
    }
    Inq_String_IDeconstruct(&LEnglishString);
    Inq_File_IDeconstruct(&LEnglishFile);
    for(Sint64 LIndex = 0 ; LIndex < AInstance->FTextArray.FCount ; LIndex++)
    {
        SDL_Log("%s\n" , AInstance->FTextArray.FData[LIndex].FString.FData);
    }
    SDL_Log("\n");
}

Sint32 Inq_Font_ICompare(Inq_String_SInstance const*const APath , Inq_Font_SInstance const*const AFont)
{
    return(Inq_String_ICompare(APath , &AFont->FPath));
}

Sint32 Inq_Font_ICompareFont(Inq_Font_SInstance const*const AA , Inq_Font_SInstance const*const AB)
{
    return(Inq_Font_ICompare(&AA->FPath , AB));
}

Inq_Text_SInstance const* Inq_Font_ISearch(Inq_Font_SInstance const*const AInstance , Sint64 const AIdentifier)
{
    return(&AInstance->FTextArray.FData[AIdentifier]);
}

void Inq_Font_IDeconstruct(Inq_Font_SInstance *const AInstance)
{
    for(Sint64 LIndex = 0 ; LIndex < AInstance->FTextArray.FCount ; LIndex++)
    {
        Inq_Text_IDeconstruct(&AInstance->FTextArray.FData[LIndex]);
    }
    Inq_Array_IDeconstruct(&AInstance->FTextArray);
    TTF_CloseFont(AInstance->FData);
    Inq_String_IDeconstruct(&AInstance->FPath);
}