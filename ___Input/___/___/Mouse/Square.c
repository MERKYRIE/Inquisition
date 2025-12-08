#include"Exploitation.hxx"

namespace NExploitation::NClient::NMouse
{
    SSquare::SSquare()
    {
        FModification = false;
        FX = 0.0;
        FY = 0.0;
    }

    SSquare* SSquare::IPreupdate()
    {
        FModification = false;
        FX = 0.0;
        FY = 0.0;
        return(this);
    }

    SSquare* SSquare::IPostupdate(double const& AX , double const& AY)
    {
        FModification = true;
        FX = GVideo.IPixelToSquare(AX);
        FY = GVideo.IPixelToSquare(AY);
        return(this);
    }

    SSquare::~SSquare()
    {
    
    }
}