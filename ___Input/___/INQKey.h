#pragma once

struct Inq_Key_SInstance
{
    bool FIsModified;
    bool FIsUp;
    bool FIsPressed;
    bool FIsDown;
    bool FIsReleased;
};

struct Inq_Key_SArray
{
    Inq_Key_SInstance * FData;
    Sint64 FSize;
    Sint64 FCount;
};

void Inq_Key_IConstruct(Inq_Key_SInstance *const AInstance);
void Inq_Key_IPreupdate(Inq_Key_SInstance *const AInstance);
void Inq_Key_IPostupdate(Inq_Key_SInstance *const AInstance , SDL_KeyboardEvent const*const AEvent);
void Inq_Key_IDeconstruct(Inq_Key_SInstance *const AInstance);