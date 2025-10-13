#pragma comment(lib , "../SimpleDirectMediaLayer/SDL3")
#pragma comment(lib , "../SimpleDirectMediaLayer/Image/SDL3_image")
#pragma comment(lib , "../SimpleDirectMediaLayer/TrueTypeFont/SDL3_ttf")

#include"../SimpleDirectMediaLayer/SDL_main.h"

#include"INQCore.h"

void Inq_Core_IInitialize(void)
{
    Inq_Debug_IAssertCondition(SDL_Init(SDL_INIT_VIDEO));
    Inq_Video_IInitialize();
    Inq_Atlas_IInitialize();
    Inq_Typeface_IInitialize();
    Inq_Keyboard_IInitialize();
    Inq_Entity_IInitialize();
    Inq_Player_IInitialize();
    Inq_Wall_IInitialize();
    Inq_SubHusk_IInitialize();
    Inq_Husk_IInitialize();
    Inq_Partition_IInitialize();
}

void Inq_Core_IInitiate(void)
{
    /*
    while(NClient::GKeyboard.FKeys["Escape"]->FState == "Up")
    {
        NClient::GMouse.IUpdate();
    }
    */
    while(!Inq_Keyboard_IGetKey(SDL_SCANCODE_ESCAPE)->FIsPressed)
    {
        Inq_Time_IUpdate();
        Inq_Keyboard_IUpdate();
        Inq_Entity_IUpdate();
        Inq_Video_IUpdate();
    }
}

void Inq_Core_IDeinitialize(void)
{
    Inq_Partition_IDeinitialize();
    Inq_Husk_IDeinitialize();
    Inq_SubHusk_IDeinitialize();
    Inq_Wall_IDeinitialize();
    Inq_Player_IDeinitialize();
    Inq_Entity_IDeinitialize();
    Inq_Keyboard_IDeinitialize();
    Inq_Typeface_IDeinitialize();
    Inq_Atlas_IDeinitialize();
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