#pragma once

struct Inq_Node_SInstance
{
    void * FData;
    Inq_Node_SInstance * FNode;
};

void Inq_Node_IConstruct(Inq_Node_SInstance *const AInstance);
void Inq_Node_ICopy(Inq_Node_SInstance *const ADestination , Inq_Node_SInstance const*const ASource , Sint64 const ASize);
void Inq_Node_IDeconstruct(Inq_Node_SInstance *const AInstance);