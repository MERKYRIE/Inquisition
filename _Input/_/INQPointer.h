#pragma once

struct Inq_Pointer_SInstance
{
    void * FData;
};

void Inq_Pointer_IConstruct(void *const AInstance , Sint64 const ASize , void const*const ARaw);
void Inq_Pointer_IConstructSpace(void *const AInstance , Sint64 const ASize);
void Inq_Pointer_IConstructVoid(void *const AInstance);
void Inq_Pointer_IConstructCopy(void *const ADestination , void const*const ASource , Sint64 const ASize);
void Inq_Pointer_IAdjust(void *const AInstance , Sint64 const AOldSize , Sint64 const ANewSize);
void Inq_Pointer_IDeconstruct(void *const AInstance);