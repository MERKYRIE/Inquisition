#pragma once

struct Inq_Widget_SInstance
{
    Inq_Image_SInstance const* FImage;
    Inq_Text_SInstance const* FText;
    Inq_Rectangle_SInstance FViewport;
    bool FIsText;
};

struct Inq_Widget_SArray
{
    Inq_Widget_SInstance * FData;
    Sint64 FSize;
    Sint64 FCount;
};

void Inq_Widget_IConstructImage(Inq_Widget_SInstance *const AInstance , Inq_Image_SInstance const* AImage , double const AX , double const AY , double const AWidth , double const AHeight);
void Inq_Widget_IConstructText(Inq_Widget_SInstance *const AInstance , Sint64 const AIdentifier , double const AX , double const AY);
void Inq_Widget_IDraw(Inq_Widget_SInstance const*const AInstance);
void Inq_Widget_IDeconstruct(Inq_Widget_SInstance *const AInstance);