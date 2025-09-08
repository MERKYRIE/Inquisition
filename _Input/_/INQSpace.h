#pragma once

struct Inq_Space_SMatrix
{
    Inq_Partition_SInstance * FData;
    Sint64 FSize;
    Sint64 FCount;
};
        
void Inq_Space_IInitialize(void);
void Inq_Space_IUpdate(void);
double Inq_Space_IGetPartitionWidth(void);
double Inq_Space_IGetPartitionHeight(void);
void Inq_Space_IDeinitialize(void);