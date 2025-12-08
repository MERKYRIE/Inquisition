#include"INQCore.h"

void Inq_Pointer_IConstruct(void *const AInstance , Sint64 const ASize , void const*const ARaw)
{
    Inq_Pointer_SInstance * LInstance = AInstance;
    LInstance->FData = NULL;
    Inq_Pointer_IAdjust(LInstance , 0 , ASize);
    if(LInstance->FData && ARaw)
    {
        SDL_memcpy(LInstance->FData , ARaw , ASize);
    }
}

void Inq_Pointer_IConstructSpace(void *const AInstance , Sint64 const ASize)
{
    Inq_Pointer_IConstruct(AInstance , ASize , NULL);
}

void Inq_Pointer_IConstructVoid(void *const AInstance)
{
    Inq_Pointer_IConstructSpace(AInstance , 0);
}

void Inq_Pointer_IConstructCopy(void *const ADestination , void const*const ASource , Sint64 const ASize)
{
    Inq_Pointer_SInstance const* LSource = ASource;
    Inq_Pointer_IConstruct(ADestination , ASize , LSource->FData);
}

void Inq_Pointer_IAdjust(void *const AInstance , Sint64 const AOldSize , Sint64 const ANewSize)
{
    Inq_Pointer_SInstance * LInstance = AInstance;
    if(ANewSize != 0)
    {
        LInstance->FData = SDL_realloc(LInstance->FData , ANewSize);
        Inq_Debug_IAssert(LInstance->FData != NULL , "Inq_Pointer_IAdjust");
    }
    else
    {
        SDL_free(LInstance->FData);
        LInstance->FData = NULL;
    }
    if(LInstance->FData && AOldSize < ANewSize)
    {
        Uint8 * LData = LInstance->FData;
        SDL_memset(LData + AOldSize , 0 , ANewSize - AOldSize);
    }
}

void Inq_Pointer_IDeconstruct(void *const AInstance)
{
    Inq_Pointer_SInstance * LInstance = AInstance;
    Inq_Pointer_IAdjust(LInstance , 1 , 0);
}