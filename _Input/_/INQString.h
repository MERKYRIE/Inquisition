#pragma once

struct Inq_String_SInstance
{
    char * FData;
    Sint64 FSize;
    Sint64 FCount;
};

struct Inq_String_SArray
{
    Inq_String_SInstance * FData;
    Sint64 FSize;
    Sint64 FCount;
};

void Inq_String_IConstruct(Inq_String_SInstance *const AInstance , char const*const ARaw);
void Inq_String_IConstructSpace(Inq_String_SInstance *const AInstance , Sint64 const ACount);
void Inq_String_IConstructVoid(Inq_String_SInstance *const AInstance);
void Inq_String_IConstructCopy(Inq_String_SInstance *const ADestination , Inq_String_SInstance const*const ASource);
void Inq_String_IAdjust(Inq_String_SInstance *const AInstance , Sint64 const ACount);
void Inq_String_IPush(Inq_String_SInstance *const AInstance);
void Inq_String_ITerminate(Inq_String_SInstance *const AInstance);
void Inq_String_IClear(Inq_String_SInstance *const AInstance);
void Inq_String_IAppend(Inq_String_SInstance *const ADestination , Inq_String_SInstance const*const ASource);
void Inq_String_ICopy(Inq_String_SInstance *const ADestination , Inq_String_SInstance const*const ASource);
char * Inq_String_IGetLast(Inq_String_SInstance const*const AInstance);
void Inq_String_IReplace(Inq_String_SInstance const*const AInstance , char const ASource , char const ADestination);
void Inq_String_IGeneralize(Inq_String_SInstance const*const AInstance);
Sint32 Inq_String_ICompare(Inq_String_SInstance const*const AA , Inq_String_SInstance const*const AB);
char * Inq_String_IFind(Inq_String_SInstance const*const AInstance , char const ACharacter , Sint64 const ACount);
char * Inq_String_IFindLast(Inq_String_SInstance const*const AInstance , char const ACharacter , Sint64 const ACount);
Sint64 Inq_String_IParseIntegral(Inq_String_SInstance const*const AInstance);
void Inq_String_IDeconstruct(Inq_String_SInstance *const AInstance);