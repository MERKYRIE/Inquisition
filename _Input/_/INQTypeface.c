#include"INQCore.h"

TTF_TextEngine * Inq_Typeface_GEngine;
Inq_Font_SArray Inq_Typeface_GFontArray;

void Inq_Typeface_IInitialize(void)
{
    Inq_Debug_IAssertCondition(TTF_Init());
    Inq_Debug_IAssertHandle(Inq_Typeface_GEngine = TTF_CreateRendererTextEngine(Inq_Video_IGetRenderer()));
    Inq_String_SArray LGlob;
    Inq_Glob_IConstruct(&LGlob , "Font/" , "*.ttf");
    Inq_Array_IConstructSpace(&Inq_Typeface_GFontArray , sizeof(Inq_Font_SInstance) , LGlob.FCount);
    for(Sint64 LIndex = 0 ; LIndex < LGlob.FCount ; LIndex++)
    {
        Inq_Font_IConstruct(&Inq_Typeface_GFontArray.FData[LIndex] , &LGlob.FData[LIndex]);
    }
    Inq_Glob_IDeconstruct(&LGlob);
    Inq_Array_ISort(&Inq_Typeface_GFontArray , &Inq_Font_ICompareFont);
    for(Sint64 LIndex = 0 ; LIndex < Inq_Typeface_GFontArray.FCount ; LIndex++)
    {
        SDL_Log("%s\n" , Inq_Typeface_GFontArray.FData[LIndex].FPath.FData);
    }
    SDL_Log("\n");
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