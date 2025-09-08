#include"Exploitation.hxx"

namespace NExploitation::NClient::NMouse
{
    SButton::SButton()
    {
        FModification = false;
        FState = "Up";
        FPressed = std::make_shared<SCursor>();
        FReleased = std::make_shared<SCursor>();
        FHeld = std::make_shared<SCursor>();
    }

    SButton* SButton::IPreupdate()
    {
        FModification = false;
        FPressed->IPreupdate();
        FReleased->IPreupdate();
        FHeld->IPreupdate();
        if(FState == "Pressed")
        {
            FState = "Down";
            return(this);
        }
        if(FState == "Released")
        {
            FState = "Up";
            return(this);
        }
        return(this);
    }
    
    SButton* SButton::IPostupdate(SDL_Event const& AEvent)
    {
        FModification = true;
        switch(AEvent.type)
        {
            case(SDL_EVENT_MOUSE_BUTTON_DOWN):
                FState = "Pressed";
                FPressed->IPostupdate(AEvent.motion);
            break;
            case(SDL_EVENT_MOUSE_BUTTON_UP):
                FState = "Released";
                FReleased->IPostupdate(AEvent.motion);
            break;
            case(SDL_EVENT_MOUSE_MOTION):
                FHeld->IPostupdate(AEvent.motion);
            break;
        }
        return(this);
    }

    SButton::~SButton()
    {
    
    }
}