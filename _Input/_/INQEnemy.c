#include"INQCore.h"

Sint64 Inq_Enemy_GIdentifier;

void Inq_Enemy_IInitialize(void)
{
    Inq_Enemy_GIdentifier = Inq_Entity_IRegister
    (&(Inq_EntityStorage_SInstance)
        {
            .FConstruct = &Inq_Enemy_IConstruct
            ,
            .FUpdate = &Inq_Enemy_IUpdate
            ,
            .FDeconstruct = &Inq_Enemy_IDeconstruct
        }
    );
}

void Inq_Enemy_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IConstruct(&AData->FEnemy.FSprite , "Sub-Husk.png");
}

void Inq_Enemy_IUpdate(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IDraw(&AData->FEnemy.FSprite , AX , AY);
}

void Inq_Enemy_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IDeconstruct(&AData->FEnemy.FSprite);
}

void Inq_Enemy_IDeinitialize(void)
{

}