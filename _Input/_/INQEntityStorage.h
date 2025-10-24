#pragma once

struct Inq_EntityStorage_SInstance
{
    void (*FConstruct)(Inq_EntityData_UInstance *const AData , Sint64 const AVariation , Sint64 const AX , Sint64 const AY);
    Sint64 (*FGetTitle)(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
    Inq_Integral_SArray const* (*FGetPropertyArray)(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
    Sint64 (*FGetDescription)(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
    void (*FUpdateVideo)(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
    Inq_Image_SInstance const* (*FGetPortrait)(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
    bool (*FUpdate)(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
    bool (*FCanWork)(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
    void (*FWork)(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
    void (*FDeconstruct)(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
};

struct Inq_EntityStorage_SArray
{
    Inq_EntityStorage_SInstance * FData;
    Sint64 FSize;
    Sint64 FCount;
};