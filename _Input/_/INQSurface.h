#pragma once

struct Inq_Surface_SInstance
{
    SDL_Surface * FData;
};

void Inq_Surface_IConstruct(Inq_Surface_SInstance *const AInstance , TTF_Font *const AFont , Inq_String_SInstance const*const AString);
void Inq_Surface_IDeconstruct(Inq_Surface_SInstance *const AInstance);