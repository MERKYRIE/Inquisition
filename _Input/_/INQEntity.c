#include"INQCore.h"

Inq_Entity_SList Inq_Entity_GList;
Inq_EntityStorage_SArray Inq_Entity_GStorageArray;
Sint64 Inq_Entity_GIdentifier;
Inq_Entity_SNode const* Inq_Entity_GNode;

void Inq_Entity_IInitialize(void)
{
    Inq_List_IConstructVoid(&Inq_Entity_GList , sizeof(Inq_Entity_SInstance));
    Inq_Array_IConstructVoid(&Inq_Entity_GStorageArray , sizeof(Inq_EntityStorage_SInstance));
    Inq_Entity_GIdentifier = Inq_Entity_IRegister
    (
        &(Inq_EntityStorage_SInstance)
        {
            .FConstruct = NULL
            ,
            .FUpdateVideo = NULL
            ,
            .FUpdate = NULL
            ,
            .FDeconstruct = NULL
        }
    );
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

bool Inq_Entity_IIsFilled(Inq_Entity_SInstance const*const AInstance)
{
    return(AInstance->FIdentifier != 0);
}

void Inq_Entity_IUpdate(void)
{
    for(Inq_Entity_SNode const* LNode = Inq_Entity_GList.FFront ; LNode ; LNode = LNode->FNode)
    {
        Sint64 LX;
        Sint64 LY;
        Inq_Partition_IGetPosition(&LNode->FData->FData , &LX , &LY);
        Inq_Entity_GStorageArray.FData[LNode->FData->FIdentifier].FUpdateVideo(&LNode->FData->FData , LX , LY);
    }
    while(Inq_Entity_GNode)
    {
        Sint64 LX;
        Sint64 LY;
        Inq_Partition_IGetPosition(&Inq_Entity_GNode->FData->FData , &LX , &LY);
        if(!Inq_Entity_GStorageArray.FData[Inq_Entity_GNode->FData->FIdentifier].FUpdate(&Inq_Entity_GNode->FData->FData , LX , LY))
        {
            return;
        }
        Inq_Entity_GNode = Inq_Entity_GNode->FNode;
    }
    Inq_Entity_GNode = Inq_Entity_GList.FFront;
}

void Inq_Entity_IMove(Inq_Entity_SInstance const*const AEntity , Sint64 const AXOffset , Sint64 const AYOffset)
{
    Sint64 LX;
    Sint64 LY;
    Inq_Partition_IGetPosition(&AEntity->FData , &LX , &LY);
    Inq_Partition_IGetPartition(LX + AXOffset , LY + AYOffset)->FEntity = Inq_Partition_IGetPartition(LX , LY)->FEntity;
    Inq_Partition_IGetPartition(LX , LY)->FEntity.FIdentifier = 0;
    Inq_Entity_IGetNode(&Inq_Partition_IGetPartition(LX + AXOffset , LY + AYOffset)->FEntity.FData)->FData = &Inq_Partition_IGetPartition(LX + AXOffset , LY + AYOffset)->FEntity;
    Inq_Entity_SInstance const*const A = &Inq_Partition_IGetPartition(LX , LY)->FEntity;
    Inq_Entity_SInstance const*const B = &Inq_Partition_IGetPartition(LX + AXOffset , LY + AYOffset)->FEntity;
}

Inq_Entity_SNode * Inq_Entity_IGetNode(Inq_EntityData_UInstance const*const AData)
{
    Sint64 LX;
    Sint64 LY;
    Inq_Partition_IGetPosition(AData , &LX , &LY);
    if(Inq_Partition_IGetPartition(LX , LY)->FEntity.FNode == NULL)
    {
        return(Inq_Entity_GList.FFront);
    }
    else
    {
        return(Inq_Partition_IGetPartition(LX , LY)->FEntity.FNode->FNode);
    }
}

void Inq_Entity_IDeconstruct(Inq_Entity_SInstance *const AInstance , Sint64 const AX , Sint64 const AY)
{
    Inq_Entity_GStorageArray.FData[AInstance->FIdentifier].FDeconstruct(&AInstance->FData , AX , AY);
    Inq_Entity_IGetNode(&AInstance->FData)->FData = NULL;
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