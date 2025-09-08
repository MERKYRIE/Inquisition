#include"INQCore.h"

SDL_Window * GWindow;
SDL_Renderer * GRenderer;
Sint64 GWidth;
Sint64 GHeight;
Sint64 GMinimalDimension;
Sint64 GMaximalDimension;
double GRatio;
double GInversedRatio;
Sint64 GProportionalWidth;
Sint64 GProportionalHeight;

void Inq_Video_IInitialize(void)
{
    Inq_Debug_IAssertHandle(GWindow = SDL_CreateWindow("Inquisition" , 0 , 0 , SDL_WINDOW_FULLSCREEN));
    Inq_Debug_IAssertHandle(GRenderer = SDL_CreateRenderer(GWindow , NULL));
    SDL_DisplayMode const* LMode;
    Inq_Debug_IAssertHandle(LMode = SDL_GetCurrentDisplayMode(1));
    GWidth = LMode->w;
    GHeight = LMode->h;
    GMinimalDimension = Inq_Integral_IGetMinimum(GWidth , GHeight);
    GMaximalDimension = Inq_Integral_IGetMaximum(GWidth , GHeight);
    GRatio = (double)GWidth / (double)GHeight;
    GInversedRatio = (double)GHeight / (double)GWidth;
    GProportionalWidth = 0;
    for(GProportionalHeight = 3 ; GProportionalHeight <= 9 ; GProportionalHeight++)
    {
        if(SDL_fabs(GProportionalHeight * GRatio - SDL_round(GProportionalHeight * GRatio)) < SDL_FLT_EPSILON)
        {
            GProportionalWidth = (Sint64)SDL_round(GProportionalHeight * GRatio);
            break;
        }
    }
    Inq_Debug_IAssert(GProportionalWidth , "GProportionalWidth");
}

void Inq_Video_IUpdate(void)
{
    SDL_RenderPresent(GRenderer);
    SDL_RenderClear(GRenderer);
}

SDL_Renderer * Inq_Video_IGetRenderer(void)
{
    return(GRenderer);
}

double Inq_Video_IGetSquareCoordinate(double const APixelCoordinate)
{
    return(APixelCoordinate / GMinimalDimension);
}

double Inq_Video_IGetPixelCoordinate(double const ASquareCoordinate)
{
    return(GMinimalDimension * ASquareCoordinate);
}

void Inq_Video_IDeinitialize(void)
{
    SDL_DestroyRenderer(GRenderer);
    SDL_DestroyWindow(GWindow);
}