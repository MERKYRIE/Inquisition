#pragma once

struct Inq_Entity_SInstance
{
    Sint64 FIdentifier;
    Inq_EntityData_UInstance FData;
    Inq_Entity_SNode * FNode;
};

struct Inq_Entity_SList
{
    Inq_Entity_SNode * FFront;
    Inq_Entity_SNode * FBack;
    Sint64 FSize;
};

struct Inq_Entity_SNode
{
    Inq_Entity_SInstance * FData;
    Inq_Entity_SNode * FNode;
};

void Inq_Entity_IInitialize(void);
Sint64 Inq_Entity_IRegister(Inq_EntityStorage_SInstance const*const AStorage);
void Inq_Entity_IConstruct(Inq_Entity_SInstance *const AInstance , Sint64 const LIdentifier , Sint64 const AVariation , Sint64 const AX , Sint64 const AY);
Sint64 Inq_Entity_IGetIdentifier(void);
bool Inq_Entity_IIsFilled(Inq_Entity_SInstance const*const AInstance);
Inq_Image_SInstance const* Inq_Entity_IGetPortrait(Inq_Entity_SInstance *const AEntity , Sint64 const AX , Sint64 const AY);
Sint64 Inq_Entity_IGetTitle(Inq_Entity_SInstance *const AEntity , Sint64 const AX , Sint64 const AY);
Inq_Integral_SArray const* Inq_Entity_IGetPropertyArray(Inq_Entity_SInstance *const AEntity , Sint64 const AX , Sint64 const AY);
Sint64 Inq_Entity_IGetDescription(Inq_Entity_SInstance *const AEntity , Sint64 const AX , Sint64 const AY);
Sint64 Inq_Entity_IGetTooltip(Inq_Entity_SInstance *const AEntity , Sint64 const AX , Sint64 const AY);
void Inq_Entity_IUpdate(void);
bool Inq_Entity_ICanWork(Inq_Entity_SInstance *const AEntity , Sint64 const AX , Sint64 const AY);
bool Inq_Entity_IWork(Inq_Entity_SInstance *const AEntity , Sint64 const AX , Sint64 const AY);
Inq_EntityData_UInstance * Inq_Entity_IWalk(Inq_Entity_SInstance const*const AEntity , Sint64 const AXOffset , Sint64 const AYOffset);
Inq_Entity_SNode * Inq_Entity_IGetNode(Inq_EntityData_UInstance const*const AData);
void Inq_Entity_IDeconstruct(Inq_Entity_SInstance *const AInstance , Sint64 const AX , Sint64 const AY);
void Inq_Entity_IDeinitialize(void);