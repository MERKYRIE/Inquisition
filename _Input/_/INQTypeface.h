#pragma once

void Inq_Typeface_IInitialize(void);
TTF_TextEngine * Inq_Typeface_IGetEngine(void);
Inq_Font_SInstance const* Inq_Typeface_ISearch(char const*const APath);
void Inq_Typeface_IDeinitialize(void);