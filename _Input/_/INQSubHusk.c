#include"INQCore.h"

Sint64 Inq_SubHusk_GIdentifier;

void Inq_SubHusk_IInitialize(void)
{
    Inq_SubHusk_GIdentifier = Inq_Entity_IRegister
    (
        &(Inq_EntityStorage_SInstance)
        {
            .FConstruct = &Inq_SubHusk_IConstruct
            ,
            .FUpdateVideo = &Inq_SubHusk_IUpdateVideo
            ,
            .FUpdate = &Inq_SubHusk_IUpdate
            ,
            .FDeconstruct = &Inq_SubHusk_IDeconstruct
        }
    );
}

void Inq_SubHusk_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IConstruct(&AData->FSubHusk.FSprite , "Sub-Husk/IdleDown/000.png");
}

void Inq_SubHusk_IUpdateVideo(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IDraw(&AData->FSubHusk.FSprite , AX , AY);
}

bool Inq_SubHusk_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(true);
}

void Inq_SubHusk_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IDeconstruct(&AData->FSubHusk.FSprite);
}

void Inq_SubHusk_IDeinitialize(void)
{

}