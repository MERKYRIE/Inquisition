#include"INQCore.h"

Sint64 Inq_Player_GIdentifier;

void Inq_Player_IInitialize(void)
{
    Inq_Player_GIdentifier = Inq_Entity_IRegister
    (&(Inq_EntityStorage_SInstance)
        {
            .FConstruct = &Inq_Player_IConstruct
            ,
            .FUpdate = &Inq_Player_IUpdate
            ,
            .FDeconstruct = &Inq_Player_IDeconstruct
        }
    );
}

void Inq_Player_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IConstruct(&AData->FPlayer.FSprite , "Player.png");
}

void Inq_Player_IUpdate(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IDraw(&AData->FPlayer.FSprite , AX , AY);
}

void Inq_Player_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IDeconstruct(&AData->FPlayer.FSprite);
}

void Inq_Player_IDeinitialize(void)
{

}