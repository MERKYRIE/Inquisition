#pragma comment(lib , "../SimpleDirectMediaLayer/SDL3")
#pragma comment(lib , "../SimpleDirectMediaLayer/TrueTypeFont/SDL3_ttf")

#include"../SimpleDirectMediaLayer/SDL_main.h"

#include"INQCore.h"

void Inq_Core_IInitialize(void)
{
    Inq_Debug_IAssertCondition(SDL_Init(SDL_INIT_VIDEO));
    Inq_Video_IInitialize();
    Inq_Typeface_IInitialize();
    Inq_Space_IInitialize();
}

void Inq_Core_IInitiate(void)
{
    /*
    while(NClient::GKeyboard.FKeys["Escape"]->FState == "Up")
    {
        NClient::GKeyboard.IUpdate();
        NClient::GMouse.IUpdate();
        NClient::GTime.IUpdate();
    }
    */
    while(true)
    {
        Inq_Space_IUpdate();
        Inq_Video_IUpdate();
    }
}

void Inq_Core_IDeinitialize(void)
{
    Inq_Space_IDeinitialize();
    Inq_Typeface_IDeinitialize();
    Inq_Video_IDeinitialize();
    SDL_Quit();
}

Sint32 main(Sint32 AArgumentCount , char ** AArgumentArray)
{
    Inq_Core_IInitialize();
    Inq_Core_IInitiate();
    Inq_Core_IDeinitialize();
    return(0);
}