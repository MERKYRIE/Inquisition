#pragma once

namespace NExploitation::NClient::NMouse
{
    struct SSquare
    {
        bool FModification;
        double FX;
        double FY;

        SSquare();
        SSquare* IPreupdate();
        SSquare* IPostupdate(double const& AX , double const& AY);
        ~SSquare();
    };
}