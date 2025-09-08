#include"Exploitation.hxx"

namespace NExploitation::NClient
{
    void STime::IUpdate()
    {
        FLast = FAbsolute;
        FAbsolute = static_cast<double>(SDL_GetTicks());
        FRelative = FAbsolute - FLast;
    }
}