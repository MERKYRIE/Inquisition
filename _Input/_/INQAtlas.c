#include"INQCore.h"

Inq_Image_SArray Inq_Atlas_GImageArray;

void Inq_Atlas_IInitialize(void)
{
    Inq_String_SArray LGlob;
    Inq_Glob_IConstruct(&LGlob , "Image" , "png");
    Inq_Array_IConstructSpace(&Inq_Atlas_GImageArray , sizeof(Inq_Image_SInstance) , LGlob.FCount);
    for(Sint64 LIndex = 0 ; LIndex < Inq_Atlas_GImageArray.FCount ; LIndex++)
    {
        Inq_Image_IConstruct(&Inq_Atlas_GImageArray.FData[LIndex] , &LGlob.FData[LIndex]);
    }
    Inq_Glob_IDeconstruct(&LGlob);
    Inq_Array_ISort(&Inq_Atlas_GImageArray , &Inq_Image_ICompareImage);
    for(Sint64 LIndex = 0 ; LIndex < Inq_Atlas_GImageArray.FCount ; LIndex++)
    {
        SDL_Log("%s\n" , Inq_Atlas_GImageArray.FData[LIndex].FPath.FData);
    }
    SDL_Log("\n");
}

Inq_Image_SInstance const* Inq_Atlas_ISearch(char const*const APath)
{
    Inq_String_SInstance LPath;
    Inq_String_IConstruct(&LPath , APath);
    Inq_Image_SInstance * LImage = Inq_Array_ISearch(&Inq_Atlas_GImageArray , &LPath , &Inq_Image_ICompare);
    Inq_String_IDeconstruct(&LPath);
    return(LImage);
}

void Inq_Atlas_IDeinitialize(void)
{
    for(Sint64 LIndex = 0 ; LIndex < Inq_Atlas_GImageArray.FCount ; LIndex++)
    {
        Inq_Image_IDeconstruct(&Inq_Atlas_GImageArray.FData[LIndex]);
    }
    Inq_Array_IDeconstruct(&Inq_Atlas_GImageArray);
}