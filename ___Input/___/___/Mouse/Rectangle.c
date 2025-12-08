#include"Exploitation.hxx"

namespace NExploitation::NClient::NMouse
{
    SRectangle::SRectangle()
    {
        FModification = false;
        FX = 0.0;
        FY = 0.0;
    }

    SRectangle* SRectangle::IPreupdate()
    {
        FModification = false;
        FX = 0.0;
        FY = 0.0;
        return(this);
    }

    SRectangle* SRectangle::IPostupdate(double const& AX , double const& AY)
    {
        FModification = true;
        FX = GVideo.IPixelToRectangleHorizontal(AX);
        FY = GVideo.IPixelToRectangleVertical(AY);
        return(this);
    }

    SRectangle::~SRectangle()
    {
    
    }
}