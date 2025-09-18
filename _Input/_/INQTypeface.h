#pragma once

void Inq_Typeface_IInitialize(void);
Inq_Font_SInstance const* Inq_Typeface_ISearch(char const*const APath);
TTF_TextEngine * Inq_Typeface_IGetEngine(void);
void Inq_Typeface_IDeinitialize(void);