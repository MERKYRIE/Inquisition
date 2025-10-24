#pragma once

struct Inq_Name_SInstance
{
    Inq_Text_SInstance const* FText;
    double FXOffset;
    double FYOffset;
};

void Inq_Name_IConstruct(Inq_Name_SInstance *const AInstance , char const*const AFont , Sint64 const AIdentifier);
void Inq_Name_IDraw(Inq_Name_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY);
void Inq_Name_IDeconstruct(Inq_Name_SInstance *const AInstance);