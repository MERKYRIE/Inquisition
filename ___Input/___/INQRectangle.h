#pragma once

struct Inq_Rectangle_SInstance
{
    SDL_FRect FData;
};

void Inq_Rectangle_IConstruct(Inq_Rectangle_SInstance *const AInstance , double const AX , double const AY , double const AWidth , double const AHeight);
void Inq_Rectangle_IDeconstruct(Inq_Rectangle_SInstance *const AInstance);