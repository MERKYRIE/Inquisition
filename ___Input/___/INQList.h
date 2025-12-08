#pragma once

struct Inq_List_SInstance
{
    Inq_Node_SInstance * FFront;
    Inq_Node_SInstance * FBack;
    Sint64 FSize;
};

void Inq_List_IConstructVoid(void *const AInstance , Sint64 const ASize);
void Inq_List_IConstructCopy(void *const ADestination , void const*const ASource);;
void Inq_List_IPush(void *const AInstance);
void Inq_List_IClear(void *const AInstance);
void Inq_List_IAppend(void *const ADestination , void const*const ASource);
void * Inq_List_IGetLast(void const*const AInstance);
void Inq_List_IErase(void *const AInstance , void *const ANode);
void Inq_List_IDeconstruct(void *const AInstance);