#include"INQCore.h"

Inq_Entity_SList Inq_Entity_GList;
Inq_EntityStorage_SArray Inq_Entity_GStorageArray;
Sint64 Inq_Entity_GIdentifier;

void Inq_Entity_IInitialize(void)
{
    Inq_List_IConstructVoid(&Inq_Entity_GList , sizeof(Inq_Entity_SInstance));
    Inq_Array_IConstructVoid(&Inq_Entity_GStorageArray , sizeof(Inq_EntityStorage_SInstance));
    Inq_Entity_GIdentifier = Inq_Entity_IRegister
    (&(Inq_EntityStorage_SInstance)
        {
            .FConstruct = NULL
            ,
            .FUpdate = NULL
            ,
            .FDeconstruct = NULL
        }
    );
}

void Inq_Entity_IUpdate(void)
{
    for(Inq_Entity_SNode const* LNode = Inq_Entity_GList.FFront ; LNode ; LNode = LNode->FNode)
    {
        Sint64 LX;
        Sint64 LY;
        Inq_Partition_IGetPosition(LNode->FData , &LX , &LY);
        Inq_Entity_GStorageArray.FData[LNode->FData->FIdentifier].FUpdate(&LNode->FData->FData , LX , LY);
    }
}

Sint64 Inq_Entity_IRegister(Inq_EntityStorage_SInstance const*const AStorage)
{
    Inq_Array_IPush(&Inq_Entity_GStorageArray);
    Inq_Entity_GStorageArray.FData[Inq_Entity_GStorageArray.FCount - 1] = *AStorage;
    return(Inq_Entity_GStorageArray.FCount - 1);
}

void Inq_Entity_IConstruct(Inq_Entity_SInstance *const AInstance , Sint64 const LIdentifier , Sint64 const AX , Sint64 const AY)
{
    AInstance->FIdentifier = LIdentifier;
    AInstance->FNode = Inq_Entity_GList.FBack;
    Inq_List_IPush(&Inq_Entity_GList);
    Inq_Entity_GList.FBack->FData = AInstance;
    Inq_Entity_GStorageArray.FData[LIdentifier].FConstruct(&AInstance->FData , AX , AY);
}

void Inq_Entity_IDeconstruct(Inq_Entity_SInstance *const AInstance , Sint64 const AX , Sint64 const AY)
{
    Inq_Entity_GStorageArray.FData[AInstance->FIdentifier].FDeconstruct(&AInstance->FData , AX , AY);
    if(AInstance->FNode == NULL)
    {
        Inq_Entity_GList.FFront->FData = NULL;
    }
    else
    {
        AInstance->FNode->FNode->FData = NULL;
    }
    Inq_List_IErase(&Inq_Entity_GList , AInstance->FNode);
    Inq_Entity_SNode * LNode = AInstance->FNode;
    AInstance->FNode = NULL;
    AInstance->FIdentifier = 0;
    if(LNode != Inq_Entity_GList.FBack)
    {
        if(LNode == NULL)
        {
            Inq_Entity_GList.FFront->FData->FNode = NULL;
        }
        else if(LNode->FNode->FData)
        {
            LNode->FNode->FData->FNode = LNode;
        }
    }
}

void Inq_Entity_IDeinitialize(void)
{
    Inq_Array_IDeconstruct(&Inq_Entity_GStorageArray);
    Inq_List_IDeconstruct(&Inq_Entity_GList);
}