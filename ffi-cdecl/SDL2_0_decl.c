#include <SDL2/SDL.h>

#include "ffi-cdecl.h"

cdecl_type(Uint32)
cdecl_type(Sint32)
cdecl_type(Uint16)
cdecl_type(Sint16)
cdecl_type(Uint8)
cdecl_type(Sint8)

cdecl_struct(SDL_Keysym)

cdecl_type(SDL_EventType)

cdecl_struct(SDL_CommonEvent)
cdecl_struct(SDL_WindowEvent)
cdecl_struct(SDL_KeyboardEvent)
cdecl_struct(SDL_TextEditingEvent)
cdecl_struct(SDL_TextInputEvent)
cdecl_struct(SDL_MouseMotionEvent)
cdecl_struct(SDL_MouseButtonEvent)
cdecl_struct(SDL_MouseWheelEvent)
cdecl_struct(SDL_JoyAxisEvent)
cdecl_struct(SDL_JoyBallEvent)
cdecl_struct(SDL_JoyHatEvent)
cdecl_struct(SDL_JoyButtonEvent)
cdecl_struct(SDL_JoyDeviceEvent)
cdecl_struct(SDL_ControllerAxisEvent)
cdecl_struct(SDL_ControllerButtonEvent)
cdecl_struct(SDL_ControllerDeviceEvent)
cdecl_struct(SDL_QuitEvent)
cdecl_struct(SDL_UserEvent)
cdecl_struct(SDL_SysWMEvent)
cdecl_struct(SDL_TouchFingerEvent)
cdecl_struct(SDL_MultiGestureEvent)
cdecl_struct(SDL_DollarGestureEvent)
cdecl_struct(SDL_DropEvent)
cdecl_union(SDL_Event)

cdecl_struct(SDL_Rect)
cdecl_type(SDL_Rect)
cdecl_struct(SDL_Window)
cdecl_type(SDL_Window)
cdecl_struct(SDL_Renderer)
cdecl_type(SDL_Renderer)
cdecl_struct(SDL_Texture)
cdecl_type(SDL_Texture)

cdecl_func(SDL_Init)
cdecl_func(SDL_WasInit)
cdecl_func(SDL_SetMainReady)
cdecl_func(SDL_Quit)
cdecl_func(SDL_WaitEvent)
cdecl_func(SDL_WaitEventTimeout)
cdecl_func(SDL_PollEvent)
cdecl_func(SDL_GetTicks)
cdecl_func(SDL_Delay)
cdecl_func(SDL_CreateWindow)
cdecl_func(SDL_CreateRenderer)
cdecl_func(SDL_CreateWindowAndRenderer)
cdecl_func(SDL_SetRenderDrawColor)
cdecl_func(SDL_RenderClear)
cdecl_func(SDL_RenderPresent)
cdecl_func(SDL_RenderCopy)
cdecl_func(SDL_CreateTexture)
cdecl_func(SDL_UpdateTexture)
cdecl_func(SDL_SetWindowTitle)

cdecl_const(SDL_INIT_AUDIO)
cdecl_const(SDL_INIT_VIDEO)
cdecl_const(SDL_INIT_EVENTS)
cdecl_const(SDL_WINDOWPOS_UNDEFINED)
cdecl_const(SDL_WINDOW_FULLSCREEN)
cdecl_const(SDL_WINDOW_FULLSCREEN_DESKTOP)
cdecl_const(SDL_TEXTUREACCESS_STREAMING)
cdecl_const(SDL_PIXELFORMAT_ARGB8888)

