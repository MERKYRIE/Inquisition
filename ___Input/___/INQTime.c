#include"INQCore.h"

double Inq_Time_GLastTimestamp;
double Inq_Time_GAbsoluteTimestamp;
double Inq_Time_GRelativeTimestamp;

double Inq_Time_IGetRelativeTimestamp(void)
{
    return(Inq_Time_GRelativeTimestamp);
}

void Inq_Time_IUpdate(void)
{
    Inq_Time_GLastTimestamp = Inq_Time_GAbsoluteTimestamp;
    Inq_Time_GAbsoluteTimestamp = (double)SDL_GetTicks();
    Inq_Time_GRelativeTimestamp = Inq_Time_GAbsoluteTimestamp - Inq_Time_GLastTimestamp;
}