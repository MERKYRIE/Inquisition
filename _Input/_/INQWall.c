#include"INQCore.h"

Sint64 Inq_Wall_GIdentifier;
Inq_Integral_SArray Inq_Wall_GPropertyArray;

void Inq_Wall_IInitialize(void)
{
    Inq_Wall_GIdentifier = Inq_Entity_IRegister
    (
        &(Inq_EntityStorage_SInstance)
        {
            .FConstruct = &Inq_Wall_IConstruct
            ,
            .FGetTitle = &Inq_Wall_IGetTitle
            ,
            .FGetPropertyArray = &Inq_Wall_IGetPropertyArray
            ,
            .FGetDescription = &Inq_Wall_IGetDescription
            ,
            .FUpdateVideo = &Inq_Wall_IUpdateVideo
            ,
            .FGetPortrait = &Inq_Wall_IGetPortrait
            ,
            .FUpdate = &Inq_Wall_IUpdate
            ,
            .FCanWork = &Inq_Wall_ICanWork
            ,
            .FWork = NULL
            ,
            .FDeconstruct = &Inq_Wall_IDeconstruct
        }
    );
    Inq_Array_IConstructSpace(&Inq_Wall_GPropertyArray , sizeof(Sint64) , 0);
}

void Inq_Wall_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AVariation , Sint64 const AX , Sint64 const AY)
{
    Inq_Name_IConstruct(&AData->FWall.FName , "CyrillicGoth.ttf" , AVariation);
}

Sint64 Inq_Wall_IGetIdentifier(void)
{
    return(Inq_Wall_GIdentifier);
}

Sint64 Inq_Wall_IGetTitle(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(2);
}

Inq_Integral_SArray const* Inq_Wall_IGetPropertyArray(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(&Inq_Wall_GPropertyArray);
}

Sint64 Inq_Wall_IGetDescription(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(274);
}

void Inq_Wall_IUpdateVideo(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Name_IDraw(&AData->FWall.FName , AX , AY);
}

Inq_Image_SInstance const* Inq_Wall_IGetPortrait(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(Inq_Atlas_ISearch(""));
}

bool Inq_Wall_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(true);
}

bool Inq_Wall_ICanWork(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(false);
}

void Inq_Wall_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Name_IDeconstruct(&AData->FWall.FName);
}

void Inq_Wall_IDeinitialize(void)
{
    Inq_Array_IDeconstruct(&Inq_Wall_GPropertyArray);
}