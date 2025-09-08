#pragma once

namespace NExploitation::NClient
{
    inline struct STime
    {
        double FLast;
        double FAbsolute;
        double FRelative;

        void IUpdate();
    }
    GTime;
}