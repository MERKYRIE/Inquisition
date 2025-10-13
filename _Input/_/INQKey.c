#include"INQCore.h"

void Inq_Key_IConstruct(Inq_Key_SInstance *const AInstance)
{
    AInstance->FIsUp = true;
}

void Inq_Key_IPreupdate(Inq_Key_SInstance *const AInstance)
{
    AInstance->FIsModified = false;
    if(AInstance->FIsPressed)
    {
        AInstance->FIsPressed = false;
        return;
    }
    if(AInstance->FIsReleased)
    {
        AInstance->FIsReleased = false;
        return;
    }
}
    
void Inq_Key_IPostupdate(Inq_Key_SInstance *const AInstance , SDL_KeyboardEvent const*const AEvent)
{
    AInstance->FIsModified = true;
    switch(AEvent->type)
    {
        case(SDL_EVENT_KEY_DOWN):
            AInstance->FIsUp = false;
            AInstance->FIsPressed = true;
            AInstance->FIsDown = true;
        break;
        case(SDL_EVENT_KEY_UP):
            AInstance->FIsReleased = true;
            AInstance->FIsUp = true;
            AInstance->FIsDown = false;
        break;
    }
}

void Inq_Key_IDeconstruct(Inq_Key_SInstance *const AInstance)
{
    
}