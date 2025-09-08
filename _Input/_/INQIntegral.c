#include"INQCore.h"

Sint64 Inq_Integral_IGetMinimum(Sint64 const AA , Sint64 const AB)
{
    return(AA < AB ? AA : AB);
}

Sint64 Inq_Integral_IGetMaximum(Sint64 const AA , Sint64 const AB)
{
    return(AA > AB ? AA : AB);
}