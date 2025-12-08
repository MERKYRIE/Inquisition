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
            .FGetTooltip = &Inq_Ore_IGetTooltip
            ,
            .FUpdateVideo = &Inq_Ore_IUpdateVideo
            ,
            .FGetPortrait = &Inq_Ore_IGetPortrait
            ,
            .FUpdate = &Inq_Ore_IUpdate
            ,
            .FCanWork = &Inq_Ore_ICanWork
            ,
            .FWork = &Inq_Ore_IWork
            ,
            .FDeconstruct = &Inq_Ore_IDeconstruct
        }
    );
    Inq_Array_IConstructSpace(&Inq_Ore_GPropertyArray , sizeof(Sint64) , 2);
    for(Sint64 LIndex = 0 ; LIndex < Inq_Ore_GPropertyArray.FCount ; LIndex++)
    {
        Inq_Ore_GPropertyArray.FData[LIndex] = 258;
    }
}

void Inq_Ore_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AVariation , Sint64 const AX , Sint64 const AY)
{
    Inq_String_SInstance LPath;
    Inq_String_IConstruct(&LPath , "Ore/");
    Inq_String_SInstance LVariation;
    Inq_String_IConstructVoid(&LVariation);
    Inq_String_ISetIntegral(&LVariation , AVariation);
    Inq_String_IAppend(&LPath , &LVariation);
    Inq_String_IDeconstruct(&LVariation);
    Inq_String_SInstance LExtension;
    Inq_String_IConstruct(&LExtension , ".png");
    Inq_String_IAppend(&LPath , &LExtension);
    Inq_String_IDeconstruct(&LExtension);
    Inq_Sprite_IConstruct(&AData->FOre.FSprite , LPath.FData);
    Inq_String_IDeconstruct(&LPath);
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

Sint64 Inq_Ore_IGetTooltip(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(257);
}

void Inq_Ore_IUpdateVideo(Inq_EntityData_UInstance const*const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IDraw(&AData->FOre.FSprite , AX , AY , 0.0 , 0.0);
}

Inq_Image_SInstance const* Inq_Ore_IGetPortrait(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(Inq_Atlas_ISearch("Portrait/Question.png"));
}

bool Inq_Ore_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(true);
}

bool Inq_Ore_ICanWork(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    return(true);
}

bool Inq_Ore_IWork(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    AData->FOre.FInteractionTimer += Inq_Time_IGetRelativeTimestamp() / 1'000.0;
    if(AData->FOre.FInteractionTimer >= 1.0)
    {
        AData->FOre.FInteractionTimer = 0.0;
        Inq_Player_IRecordOre();
        return(true);
    }
    return(false);
}

void Inq_Ore_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY)
{
    Inq_Sprite_IDeconstruct(&AData->FOre.FSprite);
}

void Inq_Ore_IDeinitialize(void)
{
    Inq_Array_IDeconstruct(&Inq_Ore_GPropertyArray);
}