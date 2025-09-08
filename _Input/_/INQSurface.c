#include"INQCore.h"

void Inq_Surface_IConstruct(Inq_Surface_SInstance *const AInstance , TTF_Font *const AFont , Inq_String_SInstance const*const AString)
{
    AInstance->FData = TTF_RenderText_LCD_Wrapped
    (
        AFont , AString->FData , 0 , (SDL_Color){.r = 100 , .g = 100 , .b = 100 , .a = SDL_ALPHA_OPAQUE} , (SDL_Color){.r = 0 , .g = 0 , .b = 0 , .a = SDL_ALPHA_OPAQUE} , 0
    );
    Inq_Debug_IAssertHandle(AInstance->FData);
}

void Inq_Surface_IDeconstruct(Inq_Surface_SInstance *const AInstance)
{
    SDL_DestroySurface(AInstance->FData);
}