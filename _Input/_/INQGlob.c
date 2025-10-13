#include"INQCore.h"

void Inq_Glob_IConstruct(Inq_String_SArray *const AInstance , char const*const APath , char const*const APattern)
{
    char ** LArray;
    Sint32 LCount;
    Inq_Debug_IAssertHandle(LArray = SDL_GlobDirectory(APath , APattern , 0 , &LCount));
    Inq_Array_IConstructSpace(AInstance , sizeof(Inq_String_SInstance) , LCount);
    for(Sint64 LIndex = 0 ; LIndex < LCount ; LIndex++)
    {
        Inq_String_IConstruct(&AInstance->FData[LIndex] , APath);
        Inq_String_SInstance LBuffer;
        Inq_String_IConstruct(&LBuffer , "/");
        Inq_String_IAppend(&AInstance->FData[LIndex] , &LBuffer);
        Inq_String_IDeconstruct(&LBuffer);
        Inq_String_IConstruct(&LBuffer , LArray[LIndex]);
        Inq_String_IAppend(&AInstance->FData[LIndex] , &LBuffer);
        Inq_String_IDeconstruct(&LBuffer);
        Inq_String_IGeneralize(&AInstance->FData[LIndex]);
    }
    SDL_free(LArray);
}

void Inq_Glob_IDeconstruct(Inq_String_SArray *const AInstance)
{
    for(Sint64 LIndex = 0 ; LIndex < AInstance->FCount ; LIndex++)
    {
        Inq_String_IDeconstruct(&AInstance->FData[LIndex]);
    }
    Inq_Array_IDeconstruct(AInstance);
}