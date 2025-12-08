#include"INQCore.h"

void Inq_List_IConstructVoid(void *const AInstance , Sint64 const ASize)
{
    Inq_List_SInstance * LInstance = AInstance;
    LInstance->FFront = NULL;
    LInstance->FBack = NULL;
    LInstance->FSize = ASize;
}

void Inq_List_IConstructCopy(void *const ADestination , void const*const ASource)
{
    Inq_List_SInstance const* LSource = ASource;
    Inq_List_SInstance * LDestination = ADestination;
    Inq_List_IConstructVoid(LDestination , LSource->FSize);
    Inq_List_IAppend(LDestination , LSource);
}

void Inq_List_IPush(void *const AInstance)
{
    Inq_List_SInstance * LInstance = AInstance;
    Inq_Node_SInstance * LNode =  NULL;
    Inq_Pointer_IConstructSpace(&LNode , sizeof(Inq_Node_SInstance));
    Inq_Node_IConstruct(LNode);
    if(!LInstance->FFront)
    {
        LInstance->FFront = LNode;
    }
    else
    {
        LInstance->FBack->FNode = LNode;
    }
    LInstance->FBack = LNode;
}

void Inq_List_IClear(void *const AInstance)
{
    Inq_List_SInstance * LInstance = AInstance;
    for(Inq_Node_SInstance * LNode = LInstance->FFront ; LNode ; LNode = LNode->FNode)
    {
        Inq_Node_IDeconstruct(LNode);
        Inq_Pointer_IDeconstruct(&(Inq_Node_SInstance *){LNode});
    }
    LInstance->FFront = NULL;
    LInstance->FBack = NULL;
}

void Inq_List_IAppend(void *const ADestination , void const*const ASource)
{
    Inq_List_SInstance * LDestination = ADestination;
    Inq_List_SInstance const* LSource = ASource;
    for(Inq_Node_SInstance const* LNode = LSource->FFront ; LNode ; LNode = LNode->FNode)
    {
        Inq_List_IPush(LDestination);
        Inq_Node_ICopy(LDestination->FBack , LNode , LDestination->FSize);
    }
}

void * Inq_List_IGetLast(void const*const AInstance)
{
    Inq_List_SInstance const* LInstance = AInstance;
    return(LInstance->FBack->FData);
}

void Inq_List_IErase(void *const AInstance , void *const ANode)
{
    Inq_List_SInstance * LInstance = AInstance;
    Inq_Node_SInstance * LLastNode = ANode;
    Inq_Node_SInstance * LNode;
    if(LLastNode == NULL)
    {
        LNode = LInstance->FFront;
        LInstance->FFront = LNode->FNode;
    }
    else
    {
        LNode = LLastNode->FNode;
        LLastNode->FNode = LNode->FNode;
    }
    if(LNode == LInstance->FBack)
    {
        LInstance->FBack = LLastNode;
    }
    Inq_Node_IDeconstruct(LNode);
    Inq_Pointer_IDeconstruct(&LNode);
}

void Inq_List_IDeconstruct(void *const AInstance)
{
    Inq_List_SInstance * LInstance = AInstance;
    Inq_List_IClear(LInstance);
    LInstance->FSize = 0;
}