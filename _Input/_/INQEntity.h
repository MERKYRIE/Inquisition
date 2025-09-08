#pragma once

struct Inq_Entity_SInstance
{
    void (*FUpdate)(Inq_Entity_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY);
    void (*FDeconstruct)(Inq_Entity_SInstance *const AInstance);
};

void Inq_Entity_IConstruct(Inq_Entity_SInstance *const AInstance);
void Inq_Entity_IUpdate(Inq_Entity_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY);
void Inq_Entity_IDeconstruct(Inq_Entity_SInstance *const AInstance);