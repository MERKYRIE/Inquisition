#include"INQCore.h"

Sint64 Inq_Wall_GIdentifier;

void Inq_Wall_IInitialize(void)
{
    Inq_Wall_GIdentifier = Inq_Entity_IRegister
    (&(Inq_EntityStorage_SInstance)
        {
            .FConstruct = &Inq_Wall_IConstruct
            ,
            .FUpdate = &Inq_Wall_IUpdate
            ,
            .FDeconstruct = &Inq_Wall_IDeconstruct
        }
    );
}

void Inq_Wall_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Name_IConstruct(&AData->FWall.FName , "CyrillicGoth.ttf" , "Wall");
}

void Inq_Wall_IUpdate(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Name_IDraw(&AData->FWall.FName , AX , AY);
}

void Inq_Wall_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Name_IDeconstruct(&AData->FWall.FName);
}

void Inq_Wall_IDeinitialize(void)
{

}