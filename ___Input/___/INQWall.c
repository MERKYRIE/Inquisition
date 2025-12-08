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
            .FGetTooltip = &Inq_Wall_IGetTooltip
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
    Inq_Array_IConstructSpace(&Inq_Wall_GPropertyArray , sizeof(Sint64) , 1);
    for(Sint64 LIndex = 0 ; LIndex < Inq_Wall_GPropertyArray.FCount ; LIndex++)
    {
        Inq_Wall_GPropertyArray.FData[LIndex] = 258;
    }
}

void Inq_Wall_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AVariation , Sint64 const AX , Sint64 const AY)
{
    Inq_String_SInstance LPath;
    Inq_String_IConstruct(&LPath , "Wall/");
    Inq_String_SInstance LVariation;
    Inq_String_IConstructVoid(&LVariation);
    Inq_String_ISetIntegral(&LVariation , AVariation);
    Inq_String_IAppend(&LPath , &LVariation);
    Inq_String_IDeconstruct(&LVariation);
    Inq_String_SInstance LExtension;
    Inq_String_IConstruct(&LExtension , ".png");
    Inq_String_IAppend(&LPath , &LExtension);
    Inq_String_IDeconstruct(&LExtension);
    Inq_Sprite_IConstruct(&AData->FWall.FSprite , LPath.FData);
    Inq_String_IDeconstruct(&LPath);
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

Sint64 Inq_Wall_IGetTooltip(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(257);
}

void Inq_Wall_IUpdateVideo(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IDraw(&AData->FWall.FSprite , AX , AY , 0.0 , 0.0);
}

Inq_Image_SInstance const* Inq_Wall_IGetPortrait(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(Inq_Atlas_ISearch("Portrait/Question.png"));
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
    Inq_Sprite_IDeconstruct(&AData->FWall.FSprite);
}

void Inq_Wall_IDeinitialize(void)
{
    Inq_Array_IDeconstruct(&Inq_Wall_GPropertyArray);
}