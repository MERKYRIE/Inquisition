#include"INQCore.h"

TTF_TextEngine * Inq_Typeface_GEngine;
double Inq_Font_GGetLineSkip;
Inq_Font_SArray Inq_Typeface_GFontArray;

void Inq_Typeface_IInitialize(void)
{
    Inq_Debug_IAssertCondition(TTF_Init());
    Inq_Debug_IAssertHandle(Inq_Typeface_GEngine = TTF_CreateRendererTextEngine(Inq_Video_IGetRenderer()));
    Inq_Font_GGetLineSkip = 0.014;
    Inq_Array_IConstructVoid(&Inq_Typeface_GFontArray , sizeof(Inq_Font_SInstance));
    Inq_String_SArray LGlob;
    Inq_Glob_IConstruct(&LGlob , "Font/Center" , "ttf");
    Inq_Array_IAdjust(&Inq_Typeface_GFontArray , Inq_Typeface_GFontArray.FCount + LGlob.FCount);
    for(Sint64 LIndex = 0 ; LIndex < LGlob.FCount ; LIndex++)
    {
        Inq_Font_IConstruct(&Inq_Typeface_GFontArray.FData[(Inq_Typeface_GFontArray.FCount - 1) - LIndex] , &LGlob.FData[LIndex] , TTF_HORIZONTAL_ALIGN_CENTER);
    }
    Inq_Glob_IDeconstruct(&LGlob);
    Inq_Glob_IConstruct(&LGlob , "Font/Left" , "ttf");
    Inq_Array_IAdjust(&Inq_Typeface_GFontArray , Inq_Typeface_GFontArray.FCount + LGlob.FCount);
    for(Sint64 LIndex = 0 ; LIndex < LGlob.FCount ; LIndex++)
    {
        Inq_Font_IConstruct(&Inq_Typeface_GFontArray.FData[(Inq_Typeface_GFontArray.FCount - 1) - LIndex] , &LGlob.FData[LIndex] , TTF_HORIZONTAL_ALIGN_LEFT);
    }
    Inq_Glob_IDeconstruct(&LGlob);
    Inq_Glob_IConstruct(&LGlob , "Font/Right" , "ttf");
    Inq_Array_IAdjust(&Inq_Typeface_GFontArray , Inq_Typeface_GFontArray.FCount + LGlob.FCount);
    for(Sint64 LIndex = 0 ; LIndex < LGlob.FCount ; LIndex++)
    {
        Inq_Font_IConstruct(&Inq_Typeface_GFontArray.FData[(Inq_Typeface_GFontArray.FCount - 1) - LIndex] , &LGlob.FData[LIndex] , TTF_HORIZONTAL_ALIGN_RIGHT);
    }
    Inq_Glob_IDeconstruct(&LGlob);
    Inq_Array_ISort(&Inq_Typeface_GFontArray , &Inq_Font_ICompareFont);
    for(Sint64 LIndex = 0 ; LIndex < Inq_Typeface_GFontArray.FCount ; LIndex++)
    {
        SDL_Log("%s\n" , Inq_Typeface_GFontArray.FData[LIndex].FPath.FData);
    }
    SDL_Log("\n");
}

double Inq_Typeface_IGetLineSkip(void)
{
    return(Inq_Font_GGetLineSkip);
}

Inq_Font_SInstance const* Inq_Typeface_ISearch(char const*const APath)
{
    Inq_String_SInstance LPath;
    Inq_String_IConstruct(&LPath , APath);
    Inq_Font_SInstance * LFont = Inq_Array_ISearch(&Inq_Typeface_GFontArray , &LPath , &Inq_Font_ICompare);
    Inq_String_IDeconstruct(&LPath);
    return(LFont);
}

TTF_TextEngine * Inq_Typeface_IGetEngine(void)
{
    return(Inq_Typeface_GEngine);
}

void Inq_Typeface_IDeinitialize(void)
{
    for(Sint64 LIndex = 0 ; LIndex < Inq_Typeface_GFontArray.FCount ; LIndex++)
    {
        Inq_Font_IDeconstruct(&Inq_Typeface_GFontArray.FData[LIndex]);
    }
    Inq_Array_IDeconstruct(&Inq_Typeface_GFontArray);
    TTF_DestroyRendererTextEngine(Inq_Typeface_GEngine);
    TTF_Quit();
}