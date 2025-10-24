#pragma once

struct Inq_Player_SInstance
{
    Inq_Walking_SInstance FWalking;
    Sint64 FInteractionX;
    Sint64 FInteractionY;
    double FInteractionTimer;
    Inq_Widget_SArray FWidgetArray;
};

void Inq_Player_IInitialize(void);
void Inq_Player_IConstruct(Inq_EntityData_UInstance *const AData , Sint64 const AVariation , Sint64 const AX , Sint64 const AY);
Sint64 Inq_Player_IGetIdentifier(void);
void Inq_Player_IGetOffset(Sint64 const AX , Sint64 const AY , double *const AXOffset , double *const AYOffset);
Sint64 Inq_Player_IGetTitle(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
Inq_Integral_SArray const* Inq_Player_IGetPropertyArray(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
Sint64 Inq_Player_IGetDescription(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Player_IUpdateVideo(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
Inq_Image_SInstance const* Inq_Player_IGetPortrait(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
bool Inq_Player_IUpdate(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Player_IInspect(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY , Sint64 const AXOffset , Sint64 const AYOffset);
void Inq_Player_IDeconstruct(Inq_EntityData_UInstance *const AData , Sint64 const AX , Sint64 const AY);
void Inq_Player_IDeinitialize(void);