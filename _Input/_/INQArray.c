#include"INQCore.h"

void Inq_Array_IConstruct(void *const AInstance , Sint64 const ASize , Sint64 const ACount , void const*const ARaw)
{
    Inq_Array_SInstance * LInstance = AInstance;
    Inq_Pointer_IConstruct(&LInstance->FData , ACount * ASize , ARaw);
    LInstance->FSize = ASize;
    LInstance->FCount = ACount;
}

void Inq_Array_IConstructSpace(void *const AInstance , Sint64 const ASize , Sint64 const ACount)
{
    Inq_Array_IConstruct(AInstance , ASize , ACount , NULL);
}

void Inq_Array_IConstructVoid(void *const AInstance , Sint64 const ASize)
{
    Inq_Array_IConstructSpace(AInstance , ASize , 0);
}

void Inq_Array_IConstructCopy(void *const ADestination , void const*const ASource)
{
    Inq_Array_SInstance const* LSource = ASource;
    Inq_Array_IConstruct(ADestination , LSource->FSize , LSource->FCount , LSource->FData);
}

void Inq_Array_IAdjust(void *const AInstance , Sint64 const ACount)
{
    Inq_Array_SInstance * LInstance = AInstance;
    Inq_Pointer_IAdjust(&LInstance->FData , LInstance->FCount * LInstance->FSize , ACount * LInstance->FSize);
    LInstance->FCount = ACount;
}

void Inq_Array_IPush(void *const AInstance)
{
    Inq_Array_SInstance * LInstance = AInstance;
    Inq_Array_IAdjust(LInstance , LInstance->FCount + 1);
}

void Inq_Array_IPop(void *const AInstance)
{
    Inq_Array_SInstance * LInstance = AInstance;
    Inq_Array_IAdjust(LInstance , LInstance->FCount - 1);
}

void Inq_Array_IClear(void *const AInstance)
{
    Inq_Array_SInstance * LInstance = AInstance;
    Inq_Array_IAdjust(LInstance , 0);
}

void Inq_Array_IAppend(void *const ADestination , void const*const ASource)
{
    Inq_Array_SInstance * LDestination = ADestination;
    Inq_Array_SInstance const* LSource = ASource;
    Inq_Array_IAdjust(LDestination , LDestination->FCount + LSource->FCount);
    Uint8 * LData = LDestination->FData;
    SDL_memcpy(LData + (LDestination->FCount - LSource->FCount) * LDestination->FSize , LSource->FData , LSource->FCount * LDestination->FSize);
}

void * Inq_Array_IGetLast(void const*const AInstance)
{
    Inq_Array_SInstance const* LInstance = AInstance;
    Uint8 * LData = LInstance->FData;
    return(&LData[(LInstance->FCount - 1) * LInstance->FSize]);
}

void Inq_Array_ISort(void const*const AInstance , SDL_CompareCallback AComparison)
{
    Inq_Array_SInstance const* LInstance = AInstance;
    SDL_qsort(LInstance->FData , LInstance->FCount , LInstance->FSize , AComparison);
}

void * Inq_Array_ISearch(void const*const AInstance , void const*const AKey , SDL_CompareCallback AComparison)
{
    Inq_Array_SInstance const* LInstance = AInstance;
    return(SDL_bsearch(AKey , LInstance->FData , LInstance->FCount , LInstance->FSize , AComparison));
}

void Inq_Array_IDeconstruct(void *const AInstance)
{
    Inq_Array_SInstance * LInstance = AInstance;
    Inq_Pointer_IDeconstruct(&LInstance->FData);
    LInstance->FSize = 0;
    LInstance->FCount = 0;
}