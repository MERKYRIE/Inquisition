#include"INQCore.h"

void Inq_Terrain_IConstruct(Inq_Terrain_SInstance *const AInstance , Sint64 const AIdentifier , Sint64 const AX , Sint64 const AY)
{
    Inq_String_SInstance LPath;
    Inq_String_IConstruct(&LPath , "Terrain/");
    Inq_String_SInstance LIdentifier;
    Inq_String_IConstructVoid(&LIdentifier);
    Inq_String_ISetIntegral(&LIdentifier , AIdentifier);
    Inq_String_IAppend(&LPath , &LIdentifier);
    Inq_String_IDeconstruct(&LIdentifier);
    Inq_String_SInstance LExtension;
    Inq_String_IConstruct(&LExtension , ".png");
    Inq_String_IAppend(&LPath , &LExtension);
    Inq_String_IDeconstruct(&LExtension);
    Inq_Sprite_IConstruct(&AInstance->FSprite , LPath.FData);
    Inq_String_IDeconstruct(&LPath);
}

void Inq_Terrain_IUpdate(Inq_Terrain_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IDraw(&AInstance->FSprite , AX , AY , 0.0 , 0.0);
}

void Inq_Terrain_IDeconstruct(Inq_Terrain_SInstance *const AInstance , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IDeconstruct(&AInstance->FSprite);
}