#include "window.h"

using namespace meat;


Window::Window() : properties{"MEAT", 1000, 800, SDL_WINDOW_RESIZABLE} {}

auto Window::destroy() -> void {
   m_window.reset();
}

auto Window::set_window(SDL_Window* window) -> void {
   m_window.reset(window);
}
