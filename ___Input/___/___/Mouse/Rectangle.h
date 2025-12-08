#pragma once

namespace NExploitation::NClient::NMouse
{
    struct SRectangle
    {
        bool FModification;
        double FX;
        double FY;

        SRectangle();
        SRectangle* IPreupdate();
        SRectangle* IPostupdate(double const& AX , double const& AY);
        ~SRectangle();
    };
}