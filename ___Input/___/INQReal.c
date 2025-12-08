#include"INQCore.h"

double Inq_Real_IGetMinimum(double const AA , double const AB)
{
    return(AA < AB ? AA : AB);
}

double Inq_Real_IGetMaximum(double const AA , double const AB)
{
    return(AA > AB ? AA : AB);
}