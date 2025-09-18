#include"INQCore.h"

Inq_Partition_Array Inq_Partition_GArray;
Sint64 Inq_Partition_GArrayWidth;
Sint64 Inq_Partition_GArrayHeight;
double Inq_Partition_GWidth;
double Inq_Partition_GHeight;
bool Inq_Partition_GTurn;

void Inq_Partition_IInitialize(void)
{
    Inq_Partition_GArrayWidth = 10;
    Inq_Partition_GArrayHeight = 10;
    Inq_Array_IConstructSpace(&Inq_Partition_GArray , sizeof(Inq_Partition_SInstance) , Inq_Partition_GArrayWidth * Inq_Partition_GArrayHeight);
    Inq_Partition_GWidth = 0.1;
    Inq_Partition_GHeight = 0.1;
    Inq_File_SInstance LFile;
    Inq_File_IConstruct(&LFile , "Space/Test.txt");
    Sint64 LIdentifier;
    for(Sint64 LY = 0 ; LY < Inq_Partition_GArrayHeight ; LY++)
    {
        for(Sint64 LX = 0 ; LX < Inq_Partition_GArrayWidth ; LX++)
        {
            if(!Inq_File_IReadIntegral(&LFile , &LIdentifier))
            {
                Inq_Debug_IAssert(false , "Inq_Partition_IInitialize");
            }
            Inq_Terrain_IConstruct(&Inq_Partition_GArray.FData[LY * Inq_Partition_GArrayWidth + LX].FTerrain , LX , LY);
            if(LIdentifier != 0)
            {
                Inq_Entity_IConstruct(&Inq_Partition_GArray.FData[LY * Inq_Partition_GArrayWidth + LX].FEntity , LIdentifier , LX , LY);
            }
        }
    }
    Inq_File_IDeconstruct(&LFile);
}

void Inq_Partition_IConstruct(Sint64 const AIdentifier , Sint64 const AX , Sint64 const AY)
{
    Inq_Entity_IConstruct(&Inq_Partition_GArray.FData[AY * Inq_Partition_GArrayWidth + AX].FEntity , AIdentifier , AX , AY);
}

double Inq_Partition_IGetWidth(void)
{
    return(Inq_Partition_GWidth);
}

double Inq_Partition_IGetHeight(void)
{
    return(Inq_Partition_GHeight);
}

void Inq_Partition_IGetPosition(Inq_Entity_SInstance const*const AEntity , Sint64 *const AX , Sint64 *const AY)
{
    *AX = ((Sint64)AEntity - (Sint64)&((Inq_Partition_SInstance *)NULL)->FEntity - (Sint64)Inq_Partition_GArray.FData) / sizeof(Inq_Partition_SInstance) % Inq_Partition_GArrayWidth;
    *AY = ((Sint64)AEntity - (Sint64)&((Inq_Partition_SInstance *)NULL)->FEntity - (Sint64)Inq_Partition_GArray.FData) / sizeof(Inq_Partition_SInstance) / Inq_Partition_GArrayWidth;
}

void Inq_Partition_IDeconstruct(Sint64 const AX , Sint64 const AY)
{
    Inq_Entity_IDeconstruct(&Inq_Partition_GArray.FData[AX * Inq_Partition_GArrayWidth + AY].FEntity , AX , AY);
}

void Inq_Partition_IDeinitialize(void)
{
    for(Sint64 LY = 0 ; LY < Inq_Partition_GArrayHeight ; LY++)
    {
        for(Sint64 LX = 0 ; LX < Inq_Partition_GArrayWidth ; LX++)
        {
            if(Inq_Partition_GArray.FData[LY * Inq_Partition_GArrayWidth + LX].FEntity.FIdentifier != 0)
            {
                Inq_Entity_IDeconstruct(&Inq_Partition_GArray.FData[LY * Inq_Partition_GArrayWidth + LX].FEntity , LX , LY);
            }
            Inq_Terrain_IDeconstruct(&Inq_Partition_GArray.FData[LY * Inq_Partition_GArrayWidth + LX].FTerrain , LX , LY);
        }
    }
    Inq_Array_IDeconstruct(&Inq_Partition_GArray);
}