#pragma once

struct Inq_Animator_SInstance
{
    Inq_Animation_SArray FAnimationArray;
    Inq_Animation_SInstance const* FAnimation;
};

void Inq_Animator_IConstruct(Inq_Animator_SInstance *const AInstance , char const*const APath);
void Inq_Animator_ISetAnimation(Inq_Animator_SInstance *const AInstance , char const*const APath);
void Inq_Animator_IDraw(Inq_Animator_SInstance const*const AInstance , Sint64 const AX , Sint64 const AY);
void Inq_Animator_IDeconstruct(Inq_Animator_SInstance *const AInstance);