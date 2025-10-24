#include"INQCore.h"

Sint64 Inq_Ore_GIdentifier;
Inq_Integral_SArray Inq_Ore_GPropertyArray;

void Inq_Ore_IInitialize(void)
{
    Inq_Ore_GIdentifier = Inq_Entity_IRegister
    (
        &(Inq_EntityStorage_SInstance)
        {
            .FConstruct = &Inq_Ore_IConstruct
            ,
            .FGetTitle = &Inq_Ore_IGetTitle
            ,
            .FGetPropertyArray = &Inq_Ore_IGetPropertyArray
            ,
            .FGetDescription = &Inq_Ore_IGetDescription
            ,
            .FUpdateVideo = &Inq_Ore_IUpdateVideo
            ,
            .FGetPortrait = &Inq_Ore_IGetPortrait
            ,
            .FUpdate = &Inq_Ore_IUpdate
            ,
            .FCanWork = &Inq_Ore_ICanWork
            ,
            .FWork = NULL
            ,
            .FDeconstruct = &Inq_Ore_IDeconstruct
        }
    );
    Inq_Array_IConstructSpace(&Inq_Ore_GPropertyArray , sizeof(Sint64) , 0);
}

void Inq_Ore_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AVariation , Sint64 const AX , Sint64 const AY)
{
    Inq_Name_IConstruct(&AData->FOre.FName , "CyrillicGoth.ttf" , AVariation);
}

Sint64 Inq_Ore_IGetIdentifier(void)
{
    return(Inq_Ore_GIdentifier);
}

Sint64 Inq_Ore_IGetTitle(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(259);
}

Inq_Integral_SArray const* Inq_Ore_IGetPropertyArray(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(&Inq_Ore_GPropertyArray);
}

Sint64 Inq_Ore_IGetDescription(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(275);
}

void Inq_Ore_IUpdateVideo(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Name_IDraw(&AData->FOre.FName , AX , AY);
}

Inq_Image_SInstance const* Inq_Ore_IGetPortrait(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(Inq_Atlas_ISearch(""));
}

bool Inq_Ore_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(true);
}

bool Inq_Ore_ICanWork(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(false);
}

void Inq_Ore_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Name_IDeconstruct(&AData->FOre.FName);
}

void Inq_Ore_IDeinitialize(void)
{
    Inq_Array_IDeconstruct(&Inq_Ore_GPropertyArray);
}