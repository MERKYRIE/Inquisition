#pragma once

struct Inq_Integral_SArray
{
    Sint64 * FData;
    Sint64 FSize;
    Sint64 FCount;
};

Sint64 Inq_Integral_IGetMinimum(Sint64 const AA , Sint64 const AB);
Sint64 Inq_Integral_IGetMaximum(Sint64 const AA , Sint64 const AB);