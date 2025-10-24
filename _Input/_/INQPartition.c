#include"INQCore.h"

Inq_Partition_Array Inq_Partition_GArray;
Sint64 Inq_Partition_GArrayWidth;
Sint64 Inq_Partition_GArrayHeight;
double Inq_Partition_GWidth;
double Inq_Partition_GHeight;

void Inq_Partition_IInitialize(void)
{
    Inq_Partition_GArrayWidth = 10;
    Inq_Partition_GArrayHeight = 10;
    Inq_Array_IConstructSpace(&Inq_Partition_GArray , sizeof(Inq_Partition_SInstance) , Inq_Partition_GArrayWidth * Inq_Partition_GArrayHeight);
    Inq_Partition_GWidth = 0.1;
    Inq_Partition_GHeight = 0.1;
    Sint64 LIdentifier;
    Sint64 LVariation;
    Inq_File_SInstance LIdentifierFile;
    Inq_File_SInstance LVariationFile;
    Inq_File_IConstruct(&LIdentifierFile , "Identifier/Test.txt");
    Inq_File_IConstruct(&LVariationFile , "Variation/Test.txt");
    for(Sint64 LY = 0 ; LY < Inq_Partition_GArrayHeight ; LY++)
    {
        for(Sint64 LX = 0 ; LX < Inq_Partition_GArrayWidth ; LX++)
        {
            if(!Inq_File_IReadIntegral(&LIdentifierFile , &LIdentifier))
            {
                Inq_Debug_IAssert(false , "Inq_Partition_IInitialize");
            }
            if(!Inq_File_IReadIntegral(&LVariationFile , &LVariation))
            {
                Inq_Debug_IAssert(false , "Inq_Partition_IInitialize");
            }
            if(LIdentifier != 0)
            {
                Inq_Entity_IConstruct(&Inq_Partition_IGetPartition(LX , LY)->FEntity , LIdentifier , LVariation , LX , LY);
            }
        }
    }
    Inq_File_IDeconstruct(&LVariationFile);
    Inq_File_IDeconstruct(&LIdentifierFile);
    Inq_File_IConstruct(&LIdentifierFile , "Terrain/Test.txt");
    for(Sint64 LY = 0 ; LY < Inq_Partition_GArrayHeight ; LY++)
    {
        for(Sint64 LX = 0 ; LX < Inq_Partition_GArrayWidth ; LX++)
        {
            if(!Inq_File_IReadIntegral(&LIdentifierFile , &LIdentifier))
            {
                Inq_Debug_IAssert(false , "Inq_Partition_IInitialize");
            }
            Inq_Terrain_IConstruct(&Inq_Partition_IGetPartition(LX , LY)->FTerrain , LIdentifier , LX , LY);
        }
    }
    Inq_File_IDeconstruct(&LIdentifierFile);
}

void Inq_Partition_IConstruct(Sint64 const AIdentifier , Sint64 const AVariation , Sint64 const AX , Sint64 const AY)
{
    Inq_Entity_IConstruct(&Inq_Partition_IGetPartition(AX , AY)->FEntity , AIdentifier , AVariation , AX , AY);
}

bool Inq_Partition_IIsPartitionEmpty(Sint64 const AX , Sint64 const AY)
{
    return(0 <= AX && AX < Inq_Partition_GArrayWidth && 0 <= AY && AY < Inq_Partition_GArrayHeight && !Inq_Entity_IIsFilled(&Inq_Partition_IGetPartition(AX , AY)->FEntity));
}

Inq_Partition_SInstance * Inq_Partition_IGetPartition(Sint64 const AX , Sint64 const AY)
{
    return(&Inq_Partition_GArray.FData[AY * Inq_Partition_GArrayWidth + AX]);
}

Sint64 Inq_Partition_IGetArrayWidth(void)
{
    return(Inq_Partition_GArrayWidth);
}

Sint64 Inq_Partition_IGetArrayHeight(void)
{
    return(Inq_Partition_GArrayHeight);
}

double Inq_Partition_IGetWidth(void)
{
    return(Inq_Partition_GWidth);
}

double Inq_Partition_IGetHeight(void)
{
    return(Inq_Partition_GHeight);
}

void Inq_Partition_IGetPosition(Inq_EntityData_UInstance const*const AData , Sint64 *const AX , Sint64 *const AY)
{
    Sint64 LIndex =
    (
        (Sint64)AData - (Sint64)&((Inq_Entity_SInstance *)NULL)->FData - (Sint64)&((Inq_Partition_SInstance *)NULL)->FEntity - (Sint64)Inq_Partition_GArray.FData
    )
    / sizeof(Inq_Partition_SInstance);
    *AX = LIndex % Inq_Partition_GArrayWidth;
    *AY = LIndex / Inq_Partition_GArrayWidth;
}

Inq_Image_SInstance const* Inq_Partition_IGetPortrait(Inq_EntityData_UInstance const*const AData , Sint64 const AXOffset , Sint64 const AYOffset)
{
    Sint64 LX;
    Sint64 LY;
    Inq_Partition_IGetPosition(AData , &LX , &LY);
    return(Inq_Entity_IGetPortrait(&Inq_Partition_IGetPartition(LX + AXOffset , LY + AYOffset)->FEntity , LX + AXOffset , LY + AYOffset));
}

Sint64 Inq_Partition_IGetTitle(Inq_EntityData_UInstance const*const AData , Sint64 const AXOffset , Sint64 const AYOffset)
{
    Sint64 LX;
    Sint64 LY;
    Inq_Partition_IGetPosition(AData , &LX , &LY);
    return(Inq_Entity_IGetTitle(&Inq_Partition_IGetPartition(LX + AXOffset , LY + AYOffset)->FEntity , LX + AXOffset , LY + AYOffset));
}

Inq_Integral_SArray const* Inq_Partition_IGetPropertyArray(Inq_EntityData_UInstance const*const AData , Sint64 const AXOffset , Sint64 const AYOffset)
{
    Sint64 LX;
    Sint64 LY;
    Inq_Partition_IGetPosition(AData , &LX , &LY);
    return(Inq_Entity_IGetPropertyArray(&Inq_Partition_IGetPartition(LX + AXOffset , LY + AYOffset)->FEntity , LX + AXOffset , LY + AYOffset));
}

Sint64 Inq_Partition_IGetDescription(Inq_EntityData_UInstance const*const AData , Sint64 const AXOffset , Sint64 const AYOffset)
{
    Sint64 LX;
    Sint64 LY;
    Inq_Partition_IGetPosition(AData , &LX , &LY);
    return(Inq_Entity_IGetDescription(&Inq_Partition_IGetPartition(LX + AXOffset , LY + AYOffset)->FEntity , LX + AXOffset , LY + AYOffset));
}

void Inq_Partition_IUpdate(void)
{
    for(Sint64 LY = 0 ; LY < Inq_Partition_GArrayHeight ; LY++)
    {
        for(Sint64 LX = 0 ; LX < Inq_Partition_GArrayWidth ; LX++)
        {
            if(Inq_Partition_IGetPartition(LX , LY)->FEntity.FIdentifier == 0)
            {
                Inq_Terrain_IUpdate(&Inq_Partition_IGetPartition(LX , LY)->FTerrain , LX , LY);
            }
        }
    }
}

bool Inq_Partition_ICanWork(Inq_EntityData_UInstance const*const AData , Sint64 const AXOffset , Sint64 const AYOffset)
{
    Sint64 LX;
    Sint64 LY;
    Inq_Partition_IGetPosition(AData , &LX , &LY);
    return
    (
        0 <= LX + AXOffset && LX + AXOffset < Inq_Partition_GArrayWidth && 0 <= LY + AYOffset && LY + AYOffset < Inq_Partition_GArrayHeight
        &&
        Inq_Entity_IIsFilled(&Inq_Partition_IGetPartition(LX + AXOffset , LY + AYOffset)->FEntity)
        &&
        Inq_Entity_ICanWork(&Inq_Partition_IGetPartition(LX + AXOffset , LY + AYOffset)->FEntity , LX + AXOffset , LY + AYOffset)
    );
}

void Inq_Partition_IWork(Inq_EntityData_UInstance const*const AData , Sint64 const AXOffset , Sint64 const AYOffset)
{
    Sint64 LX;
    Sint64 LY;
    Inq_Partition_IGetPosition(AData , &LX , &LY);
    Inq_Entity_IWork(&Inq_Partition_IGetPartition(LX + AXOffset , LY + AYOffset)->FEntity , LX + AXOffset , LY + AYOffset);
}

bool Inq_Partition_ICanWalk(Inq_EntityData_UInstance const*const AData , Sint64 const AXOffset , Sint64 const AYOffset)
{
    Sint64 LX;
    Sint64 LY;
    Inq_Partition_IGetPosition(AData , &LX , &LY);
    return
    (
        0 <= LX + AXOffset && LX + AXOffset < Inq_Partition_GArrayWidth && 0 <= LY + AYOffset && LY + AYOffset < Inq_Partition_GArrayHeight
        &&
        !Inq_Entity_IIsFilled(&Inq_Partition_IGetPartition(LX + AXOffset , LY + AYOffset)->FEntity)
    );
}

Inq_EntityData_UInstance * Inq_Partition_IWalk(Inq_EntityData_UInstance const*const AData , Sint64 const AXOffset , Sint64 const AYOffset)
{
    Sint64 LX;
    Sint64 LY;
    Inq_Partition_IGetPosition(AData , &LX , &LY);
    return(Inq_Entity_IWalk(&Inq_Partition_IGetPartition(LX , LY)->FEntity , AXOffset , AYOffset));
}

void Inq_Partition_IDeconstruct(Sint64 const AX , Sint64 const AY)
{
    Inq_Entity_IDeconstruct(&Inq_Partition_IGetPartition(AX , AY)->FEntity , AX , AY);
}

void Inq_Partition_IDeinitialize(void)
{
    for(Sint64 LY = 0 ; LY < Inq_Partition_GArrayHeight ; LY++)
    {
        for(Sint64 LX = 0 ; LX < Inq_Partition_GArrayWidth ; LX++)
        {
            if(Inq_Partition_IGetPartition(LX , LY)->FEntity.FIdentifier != 0)
            {
                Inq_Entity_IDeconstruct(&Inq_Partition_IGetPartition(LX , LY)->FEntity , LX , LY);
            }
            Inq_Terrain_IDeconstruct(&Inq_Partition_IGetPartition(LX , LY)->FTerrain , LX , LY);
        }
    }
    Inq_Array_IDeconstruct(&Inq_Partition_GArray);
}