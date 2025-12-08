#include"INQCore.h"

SDL_Window * Inq_Video_GWindow;
SDL_Renderer * Inq_Video_GRenderer;
Sint64 Inq_Video_GWidth;
Sint64 Inq_Video_GHeight;
Sint64 Inq_Video_GMinimalDimension;
Sint64 Inq_Video_GMaximalDimension;
double Inq_Video_GRatio;
double Inq_Video_GInversedRatio;
Sint64 Inq_Video_GProportionalWidth;
Sint64 Inq_Video_GProportionalHeight;
double Inq_Video_GCenterX;
double Inq_Video_GCenterY;

void Inq_Video_IInitialize(void)
{
    Inq_Debug_IAssertHandle(Inq_Video_GWindow = SDL_CreateWindow("Inquisition" , 0 , 0 , SDL_WINDOW_FULLSCREEN));
    Inq_Debug_IAssertHandle(Inq_Video_GRenderer = SDL_CreateRenderer(Inq_Video_GWindow , NULL));
    Sint32 LWidth;
    Sint32 LHeight;
    Inq_Debug_IAssertCondition(SDL_GetRenderOutputSize(Inq_Video_GRenderer , &LWidth , &LHeight));
    Inq_Video_GWidth = LWidth;
    Inq_Video_GHeight = LHeight;
    Inq_Video_GMinimalDimension = Inq_Integral_IGetMinimum(Inq_Video_GWidth , Inq_Video_GHeight);
    Inq_Video_GMaximalDimension = Inq_Integral_IGetMaximum(Inq_Video_GWidth , Inq_Video_GHeight);
    Inq_Video_GRatio = (double)Inq_Video_GWidth / (double)Inq_Video_GHeight;
    Inq_Video_GInversedRatio = (double)Inq_Video_GHeight / (double)Inq_Video_GWidth;
    Inq_Video_GProportionalWidth = 0;
    for(Inq_Video_GProportionalHeight = 3 ; Inq_Video_GProportionalHeight <= 9 ; Inq_Video_GProportionalHeight++)
    {
        if(SDL_fabs(Inq_Video_GProportionalHeight * Inq_Video_GRatio - SDL_round(Inq_Video_GProportionalHeight * Inq_Video_GRatio)) < SDL_FLT_EPSILON)
        {
            Inq_Video_GProportionalWidth = (Sint64)SDL_round(Inq_Video_GProportionalHeight * Inq_Video_GRatio);
            break;
        }
    }
    Inq_Debug_IAssert(Inq_Video_GProportionalWidth != 0 , "Inq_Video_IInitialize");
    Inq_Video_GCenterX = Inq_Video_IGetSquareCoordinate(Inq_Video_GWidth / 2.0);
    Inq_Video_GCenterY = Inq_Video_IGetSquareCoordinate(Inq_Video_GHeight / 2.0);
}

void Inq_Video_IUpdate(void)
{
    SDL_RenderPresent(Inq_Video_GRenderer);
    SDL_RenderClear(Inq_Video_GRenderer);
}

SDL_Renderer * Inq_Video_IGetRenderer(void)
{
    return(Inq_Video_GRenderer);
}

double Inq_Video_IGetSquareCoordinate(double const APixelCoordinate)
{
    return(APixelCoordinate / Inq_Video_GMinimalDimension);
}

double Inq_Video_IGetPixelCoordinate(double const ASquareCoordinate)
{
    return(Inq_Video_GMinimalDimension * ASquareCoordinate);
}

double Inq_Video_IGetCenterX(void)
{
    return(Inq_Video_GCenterX);
}

double Inq_Video_IGetCenterY(void)
{
    return(Inq_Video_GCenterY);
}

void Inq_Video_IDeinitialize(void)
{
    SDL_DestroyRenderer(Inq_Video_GRenderer);
    SDL_DestroyWindow(Inq_Video_GWindow);
}