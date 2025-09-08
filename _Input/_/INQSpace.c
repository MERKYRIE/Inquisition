#include"INQCore.h"

Sint64 GWidth;
Sint64 GHeight;
double GPartitionWidth;
double GPartitionHeight;
Inq_Space_SMatrix GMatrix;

void Inq_Space_IInitialize(void)
{
    GWidth = 10;
    GHeight = 10;
    GPartitionWidth = 0.1;
    GPartitionHeight = 0.1;
    Inq_Array_IConstructSpace(&GMatrix , sizeof(Inq_Partition_SInstance) , GWidth * GHeight);
    for(Sint64 LY = 0 ; LY < GHeight ; LY++)
    {
        for(Sint64 LX = 0 ; LX < GWidth ; LX++)
        {
            Inq_Partition_IConstruct(&GMatrix.FData[LY * GWidth + LX]);
        }
    }
    GMatrix.FData[0 * GWidth + 0].FEntity = SDL_realloc(GMatrix.FData[0 * GWidth + 0].FEntity , sizeof(Inq_Inquisitor_SInstance));
    Inq_Inquisitor_IConstruct(GMatrix.FData[0 * GWidth + 0].FEntity);
}

void Inq_Space_IUpdate(void)
{
    for(Sint64 LY = 0 ; LY < GHeight ; LY++)
    {
        for(Sint64 LX = 0 ; LX < GWidth ; LX++)
        {
            Inq_Partition_IUpdate(&GMatrix.FData[LY * GWidth + LX] , LX , LY);
        }
    }
}

double Inq_Space_IGetPartitionWidth(void)
{
    return(GPartitionWidth);
}

double Inq_Space_IGetPartitionHeight(void)
{
    return(GPartitionHeight);
}

void Inq_Space_IDeinitialize(void)
{
    for(Sint64 LY = 0 ; LY < GHeight ; LY++)
    {
        for(Sint64 LX = 0 ; LX < GWidth ; LX++)
        {
            Inq_Partition_IDeconstruct(&GMatrix.FData[LY * GWidth + LX]);
        }
    }
    Inq_Array_IDeconstruct(&GMatrix);
}