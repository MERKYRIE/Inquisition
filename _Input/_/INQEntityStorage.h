#pragma once

struct Inq_EntityStorage_SInstance
{
    void (*FConstruct)(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
    void (*FUpdateVideo)(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY);
    bool (*FUpdate)(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
    void (*FDeconstruct)(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
};

struct Inq_EntityStorage_SArray
{
    Inq_EntityStorage_SInstance * FData;
    Sint64 FSize;
    Sint64 FCount;
};