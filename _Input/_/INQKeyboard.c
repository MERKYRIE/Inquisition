#include"INQCore.h"

Inq_Key_SArray Inq_Keyboard_GKeyArray;

void Inq_Keyboard_IInitialize(void)
{
    Inq_Array_IConstructSpace(&Inq_Keyboard_GKeyArray , sizeof(Inq_Key_SInstance) , SDL_SCANCODE_COUNT);
    for(Sint64 LIndex = 0 ; LIndex < Inq_Keyboard_GKeyArray.FCount ; LIndex++)
    {
        Inq_Key_IConstruct(&Inq_Keyboard_GKeyArray.FData[LIndex]);
    }
}

void Inq_Keyboard_IUpdate(void)
{
    for(Sint64 LIndex = 0 ; LIndex < Inq_Keyboard_GKeyArray.FCount ; LIndex++)
    {
        Inq_Key_IPreupdate(&Inq_Keyboard_GKeyArray.FData[LIndex]);
    }
    SDL_PumpEvents();
    Sint64 LEventCount = SDL_PeepEvents(NULL , 0 , SDL_GETEVENT , SDL_EVENT_KEY_DOWN , SDL_EVENT_KEY_UP);
    SDL_Event * LEventArray;
    Inq_Pointer_IConstructSpace(&LEventArray , LEventCount * sizeof(SDL_Event));
    SDL_PeepEvents(LEventArray , (Sint32)LEventCount , SDL_GETEVENT , SDL_EVENT_KEY_DOWN , SDL_EVENT_KEY_UP);
    for(Sint64 LIndex = 0 ; LIndex < LEventCount ; LIndex++)
    {
        Inq_Key_IPostupdate(&Inq_Keyboard_GKeyArray.FData[LEventArray[LIndex].key.scancode] , &LEventArray[LIndex].key);
    }
    Inq_Pointer_IDeconstruct(&LEventArray);
}

Inq_Key_SInstance const* Inq_Keyboard_IGetKey(SDL_Scancode const AScancode)
{
    return(&Inq_Keyboard_GKeyArray.FData[AScancode]);
}

void Inq_Keyboard_IDeinitialize(void)
{
    for(Sint64 LIndex = 0 ; LIndex < Inq_Keyboard_GKeyArray.FCount ; LIndex++)
    {
        Inq_Key_IDeconstruct(&Inq_Keyboard_GKeyArray.FData[LIndex]);
    }
    Inq_Array_IDeconstruct(&Inq_Keyboard_GKeyArray);
}