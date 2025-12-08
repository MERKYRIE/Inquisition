#include"INQCore.h"

void Inq_File_IConstruct(Inq_File_SInstance *const AInstance , char const*const APath)
{
    AInstance->FData = SDL_IOFromFile(APath , "r");
    Inq_Debug_IAssertHandle(AInstance->FData);
}

bool Inq_File_IRead(Inq_File_SInstance *const AInstance , void *const APointer , Sint64 ASize)
{
    Sint64 LSize = SDL_ReadIO(AInstance->FData , APointer , ASize);
    SDL_IOStatus LStatus = SDL_GetIOStatus(AInstance->FData);
    Inq_Debug_IAssertCondition((LStatus == SDL_IO_STATUS_READY || LStatus == SDL_IO_STATUS_EOF) && (ASize == LSize || (ASize > LSize && LSize == 0)));
    return(LSize == ASize);
}

bool Inq_File_IReadCharacter(Inq_File_SInstance *const AInstance , char *const ACharacter)
{
    return(Inq_File_IRead(AInstance , ACharacter , sizeof(char)));
}

bool Inq_File_IReadString(Inq_File_SInstance *const AInstance , Inq_String_SInstance *const AString , bool AIsSpaceDelimiting)
{
    Inq_String_IClear(AString);
    if(SDL_GetIOStatus(AInstance->FData) == SDL_IO_STATUS_EOF)
    {
        return(false);
    }
    char LCharacter;
    while(Inq_File_IReadCharacter(AInstance , &LCharacter) && LCharacter != '\n' && (!AIsSpaceDelimiting || LCharacter != ' '))
    {
        if(LCharacter == '\r')
        {
            continue;
        }
        Inq_String_IPush(AString);
        *Inq_String_IGetLast(AString) = LCharacter;
    }
    return(true);
}

bool Inq_File_IReadIntegral(Inq_File_SInstance *const AInstance , Sint64 *const AIntegral)
{
    Inq_String_SInstance LString;
    Inq_String_IConstructVoid(&LString);
    bool LFlag = Inq_File_IReadString(AInstance , &LString , true);
    *AIntegral = Inq_String_IGetIntegral(&LString);
    Inq_String_IDeconstruct(&LString);
    return(LFlag);
}

void Inq_File_IDeconstruct(Inq_File_SInstance *const AInstance)
{
    Inq_Debug_IAssertCondition(SDL_CloseIO(AInstance->FData));
}