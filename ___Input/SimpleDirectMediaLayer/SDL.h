/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2025 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

/**
 * Main include header for the SDL library, version 3.2.22
 *
 * It is almost always best to include just this one header instead of
 * picking out individual headers included here. There are exceptions to
 * this rule--SDL_main.h is special and not included here--but usually
 * letting SDL.h include the kitchen sink for you is the correct approach.
 */

#ifndef SDL_h_
#define SDL_h_

#include <../SimpleDirectMediaLayer/SDL_stdinc.h>
#include <../SimpleDirectMediaLayer/SDL_assert.h>
#include <../SimpleDirectMediaLayer/SDL_asyncio.h>
#include <../SimpleDirectMediaLayer/SDL_atomic.h>
#include <../SimpleDirectMediaLayer/SDL_audio.h>
#include <../SimpleDirectMediaLayer/SDL_bits.h>
#include <../SimpleDirectMediaLayer/SDL_blendmode.h>
#include <../SimpleDirectMediaLayer/SDL_camera.h>
#include <../SimpleDirectMediaLayer/SDL_clipboard.h>
#include <../SimpleDirectMediaLayer/SDL_cpuinfo.h>
#include <../SimpleDirectMediaLayer/SDL_dialog.h>
#include <../SimpleDirectMediaLayer/SDL_endian.h>
#include <../SimpleDirectMediaLayer/SDL_error.h>
#include <../SimpleDirectMediaLayer/SDL_events.h>
#include <../SimpleDirectMediaLayer/SDL_filesystem.h>
#include <../SimpleDirectMediaLayer/SDL_gamepad.h>
#include <../SimpleDirectMediaLayer/SDL_gpu.h>
#include <../SimpleDirectMediaLayer/SDL_guid.h>
#include <../SimpleDirectMediaLayer/SDL_haptic.h>
#include <../SimpleDirectMediaLayer/SDL_hidapi.h>
#include <../SimpleDirectMediaLayer/SDL_hints.h>
#include <../SimpleDirectMediaLayer/SDL_init.h>
#include <../SimpleDirectMediaLayer/SDL_iostream.h>
#include <../SimpleDirectMediaLayer/SDL_joystick.h>
#include <../SimpleDirectMediaLayer/SDL_keyboard.h>
#include <../SimpleDirectMediaLayer/SDL_keycode.h>
#include <../SimpleDirectMediaLayer/SDL_loadso.h>
#include <../SimpleDirectMediaLayer/SDL_locale.h>
#include <../SimpleDirectMediaLayer/SDL_log.h>
#include <../SimpleDirectMediaLayer/SDL_messagebox.h>
#include <../SimpleDirectMediaLayer/SDL_metal.h>
#include <../SimpleDirectMediaLayer/SDL_misc.h>
#include <../SimpleDirectMediaLayer/SDL_mouse.h>
#include <../SimpleDirectMediaLayer/SDL_mutex.h>
#include <../SimpleDirectMediaLayer/SDL_pen.h>
#include <../SimpleDirectMediaLayer/SDL_pixels.h>
#include <../SimpleDirectMediaLayer/SDL_platform.h>
#include <../SimpleDirectMediaLayer/SDL_power.h>
#include <../SimpleDirectMediaLayer/SDL_process.h>
#include <../SimpleDirectMediaLayer/SDL_properties.h>
#include <../SimpleDirectMediaLayer/SDL_rect.h>
#include <../SimpleDirectMediaLayer/SDL_render.h>
#include <../SimpleDirectMediaLayer/SDL_scancode.h>
#include <../SimpleDirectMediaLayer/SDL_sensor.h>
#include <../SimpleDirectMediaLayer/SDL_storage.h>
#include <../SimpleDirectMediaLayer/SDL_surface.h>
#include <../SimpleDirectMediaLayer/SDL_system.h>
#include <../SimpleDirectMediaLayer/SDL_thread.h>
#include <../SimpleDirectMediaLayer/SDL_time.h>
#include <../SimpleDirectMediaLayer/SDL_timer.h>
#include <../SimpleDirectMediaLayer/SDL_tray.h>
#include <../SimpleDirectMediaLayer/SDL_touch.h>
#include <../SimpleDirectMediaLayer/SDL_version.h>
#include <../SimpleDirectMediaLayer/SDL_video.h>
#include <../SimpleDirectMediaLayer/SDL_oldnames.h>

#endif /* SDL_h_ */
