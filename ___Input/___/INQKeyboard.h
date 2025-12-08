#pragma once

void Inq_Keyboard_IInitialize(void);
void Inq_Keyboard_IUpdate(void);
Inq_Key_SInstance const* Inq_Keyboard_IGetKey(SDL_Scancode const AScancode);
void Inq_Keyboard_IDeinitialize(void);