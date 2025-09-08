#include"Exploitation.hxx"

namespace NExploitation::NClient::NKeyboard
{
    SKey::SKey()
    {
        FModification = false;
        FState = "Up";
    }

    void SKey::IPreupdate()
    {
        FModification = false;
        if(FState == "Pressed")
        {
            FState = "Down";
            return;
        }
        if(FState == "Released")
        {
            FState = "Up";
            return;
        }
    }
    
    void SKey::IPostupdate(SDL_KeyboardEvent const& AEvent)
    {
        FModification = true;
        switch(AEvent.type)
        {
            case(SDL_EVENT_KEY_DOWN):
                FState = "Pressed";
            break;
            case(SDL_EVENT_KEY_UP):
                FState = "Released";
            break;
        }
    }

    SKey::~SKey()
    {
    
    }
}