#pragma once

void Inq_Video_IInitialize(void);
void Inq_Video_IUpdate(void);
SDL_Renderer * Inq_Video_IGetRenderer(void);
double Inq_Video_IGetSquareCoordinate(double const APixelCoordinate);
double Inq_Video_IGetPixelCoordinate(double const ASquareCoordinate);
double Inq_Video_IGetCenterX(void);
double Inq_Video_IGetCenterY(void);
void Inq_Video_IDeinitialize(void);