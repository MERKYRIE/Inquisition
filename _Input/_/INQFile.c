#include"INQCore.h"

void Inq_File_IConstruct(Inq_File_SInstance *const AInstance , char const*const APath)
{
    AInstance->FData = SDL_IOFromFile(APath , "r");
    Inq_Debug_IAssertHandle(AInstance->FData);
}

Sint64 Inq_File_IRead(Inq_File_SInstance *const AInstance , void *const APointer , Sint64 ASize)
{
    return(SDL_ReadIO(AInstance->FData , APointer , ASize));
}

bool Inq_File_IReadString(Inq_File_SInstance *const AInstance , Inq_String_SInstance *const AString)
{
    Inq_String_IClear(AString);
    if(SDL_GetIOStatus(AInstance->FData) == SDL_IO_STATUS_EOF)
    {
        return(false);
    }
    char LCharacter;
    while(true)
    {
        if(!Inq_File_IRead(AInstance , &LCharacter , sizeof(char)))
        {
            if(SDL_GetIOStatus(AInstance->FData) != SDL_IO_STATUS_EOF)
            {
                Inq_Debug_IAssertCondition(true);
            }
        }
        if(LCharacter != '\n' && SDL_GetIOStatus(AInstance->FData) == SDL_IO_STATUS_READY)
        {
            Inq_String_IPush(AString);
            *Inq_String_IGetLast(AString) = LCharacter;
        }
        else
        {
            break;
        }
    }
    return(true);
}

void Inq_File_IDeconstruct(Inq_File_SInstance *const AInstance)
{
    Inq_Debug_IAssertCondition(SDL_CloseIO(AInstance->FData));
}