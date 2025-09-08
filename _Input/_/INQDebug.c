#include"INQCore.h"

void Inq_Debug_IAssert(bool const ACondition , char const*const AMessage)
{
    if(!ACondition)
    {
        if
        (
            !SDL_ShowSimpleMessageBox
            (
                SDL_MESSAGEBOX_ERROR
                ,
                "Debug"
                ,
                AMessage
                ,
                NULL
            )
        )
        {
            SDL_Log("Debug: %s\n" , AMessage);
        }
        exit(0);
    }
}

void Inq_Debug_IAssertCondition(bool const ABoolean)
{
    Inq_Debug_IAssert(ABoolean , SDL_GetError());
}

void Inq_Debug_IAssertHandle(void const*const APointer)
{
    Inq_Debug_IAssert(APointer , SDL_GetError());
}