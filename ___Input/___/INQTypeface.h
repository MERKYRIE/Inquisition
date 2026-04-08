#pragma once

void Inq_Typeface_IInitialize(char const*const ALocalization);
void Inq_Typeface_IReinitialize(void);
double Inq_Typeface_IGetLineSkip(void);
Inq_Font_SInstance const* Inq_Typeface_ISearch(char const*const APath);
TTF_TextEngine * Inq_Typeface_IGetEngine(void);
void Inq_Typeface_IDeinitialize(void);