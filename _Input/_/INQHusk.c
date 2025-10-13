#include"INQCore.h"

Sint64 Inq_Husk_GIdentifier;

void Inq_Husk_IInitialize(void)
{
    Inq_Husk_GIdentifier = Inq_Entity_IRegister
    (
        &(Inq_EntityStorage_SInstance)
        {
            .FConstruct = &Inq_Husk_IConstruct
            ,
            .FUpdateVideo = &Inq_Husk_IUpdateVideo
            ,
            .FUpdate = &Inq_Husk_IUpdate
            ,
            .FDeconstruct = &Inq_Husk_IDeconstruct
        }
    );
}

void Inq_Husk_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IConstruct(&AData->FHusk.FSprite , "Husk/IdleDown/000.png");
}

void Inq_Husk_IUpdateVideo(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IDraw(&AData->FHusk.FSprite , AX , AY);
}

bool Inq_Husk_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(true);
}

void Inq_Husk_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IDeconstruct(&AData->FHusk.FSprite);
}

void Inq_Husk_IDeinitialize(void)
{

}