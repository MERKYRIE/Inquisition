#pragma once

struct Inq_Array_SInstance
{
    void * FData;
    Sint64 FSize;
    Sint64 FCount;
};

void Inq_Array_IConstruct(void *const AInstance , Sint64 const ASize , Sint64 const ACount , void const*const ARaw);
void Inq_Array_IConstructSpace(void *const AInstance , Sint64 const ASize , Sint64 const ACount);
void Inq_Array_IConstructVoid(void *const AInstance , Sint64 const ASize);
void Inq_Array_IConstructCopy(void *const ADestination , void const*const ASource);
void Inq_Array_IAdjust(void *const AInstance , Sint64 const ACount);
void Inq_Array_IPush(void *const AInstance);
void Inq_Array_IPop(void *const AInstance);
void Inq_Array_IClear(void *const AInstance);
void Inq_Array_IAppend(void *const ADestination , void const*const ASource);
void * Inq_Array_IGetLast(void const*const AInstance);
void Inq_Array_ISort(void const*const AInstance , SDL_CompareCallback AComparison);
void * Inq_Array_ISearch(void const*const AInstance , void const*const AKey , SDL_CompareCallback AComparison);
void Inq_Array_IDeconstruct(void *const AInstance);