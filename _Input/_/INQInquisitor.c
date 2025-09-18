#include"INQCore.h"

Sint64 Inq_Inquisitor_GIdentifier;

void Inq_Inquisitor_IInitialize(void)
{
    Inq_Inquisitor_GIdentifier = Inq_Entity_IRegister
    (&(Inq_EntityStorage_SInstance)
        {
            .FConstruct = &Inq_Inquisitor_IConstruct
            ,
            .FUpdate = &Inq_Inquisitor_IUpdate
            ,
            .FDeconstruct = &Inq_Inquisitor_IDeconstruct
        }
    );
}

void Inq_Inquisitor_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IConstruct(&AData->FInquisitor.FSprite , "i_chartselection_clear.png");
}

void Inq_Inquisitor_IUpdate(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IDraw(&AData->FInquisitor.FSprite , AX , AY);
}

void Inq_Inquisitor_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IDeconstruct(&AData->FInquisitor.FSprite);
}

void Inq_Inquisitor_IDeinitialize(void)
{

}