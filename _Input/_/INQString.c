#include"INQCore.h"

void Inq_String_IConstruct(Inq_String_SInstance *const AInstance , char const*const ARaw)
{
    Inq_Array_IConstruct(AInstance , sizeof(char) , SDL_strlen(ARaw) , ARaw);
    Inq_String_ITerminate(AInstance);
}

void Inq_String_IConstructSpace(Inq_String_SInstance *const AInstance , Sint64 const ACount)
{
    Inq_Array_IConstructSpace(AInstance , sizeof(char) , 0);
    Inq_Debug_IAssert(false , "Inq_String_IConstructSpace");
}

void Inq_String_IConstructVoid(Inq_String_SInstance *const AInstance)
{
    Inq_Array_IConstructVoid(AInstance , sizeof(char));
    Inq_String_ITerminate(AInstance);
}

void Inq_String_IConstructCopy(Inq_String_SInstance *const ADestination , Inq_String_SInstance const*const ASource)
{
    Inq_Array_IConstructCopy(ADestination , ASource);
    Inq_Debug_IAssert(false , "Inq_String_IConstructCopy");
}

void Inq_String_IAdjust(Inq_String_SInstance *const AInstance , Sint64 const ACount)
{
    Inq_Array_IAdjust(AInstance , ACount);
    Inq_Debug_IAssert(false , "Inq_String_IAdjust");
}

void Inq_String_IPush(Inq_String_SInstance *const AInstance)
{
    Inq_Array_IPush(AInstance);
    Inq_String_ITerminate(AInstance);
}

void Inq_String_ITerminate(Inq_String_SInstance *const AInstance)
{
     Inq_Array_IPush(AInstance);
     AInstance->FCount--;
}

void Inq_String_IClear(Inq_String_SInstance *const AInstance)
{
    Inq_Array_IClear(AInstance);
    Inq_String_ITerminate(AInstance);
}

void Inq_String_IAppend(Inq_String_SInstance *const ADestination , Inq_String_SInstance const*const ASource)
{
    Inq_Array_IAppend(ADestination , ASource);
    Inq_String_ITerminate(ADestination);
}

char * Inq_String_IGetLast(Inq_String_SInstance const*const AInstance)
{
    return(Inq_Array_IGetLast(AInstance));
}

void Inq_String_IReplace(Inq_String_SInstance const*const AInstance , char const ASource , char const ADestination)
{
    for(Sint64 LIndex = 0 ; LIndex < AInstance->FCount ; LIndex++)
    {
        if(AInstance->FData[LIndex] == ASource)
        {
            AInstance->FData[LIndex] = ADestination;
        }
    }
}

void Inq_String_IGeneralize(Inq_String_SInstance const*const AInstance)
{
    Inq_String_IReplace(AInstance , '\\' , '/');
}

Sint32 Inq_String_ICompare(Inq_String_SInstance const*const AA , Inq_String_SInstance const*const AB)
{
    return(SDL_strcmp(AA->FData , AB->FData));
}

char * Inq_String_IFind(Inq_String_SInstance const*const AInstance , char const LCharacter)
{
    for(Sint64 LIndex = 0 ; LIndex < AInstance->FCount ; LIndex++)
    {
        if(AInstance->FData[LIndex] == LCharacter)
        {
            return(&AInstance->FData[LIndex + 1]);
        }
    }
    return(NULL);
}

Sint64 Inq_String_IParseIntegral(Inq_String_SInstance const*const AInstance)
{
    return(SDL_strtoll(AInstance->FData , NULL , 10));
}

void Inq_String_IDeconstruct(Inq_String_SInstance *const AInstance)
{
    Inq_Array_IDeconstruct(AInstance);
}