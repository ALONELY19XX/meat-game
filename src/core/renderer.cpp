#include "renderer.h"

using namespace meat::core;

auto Renderer::destroy() -> void {
   m_renderer.reset();
}

auto Renderer::set_renderer(SDL_Renderer* renderer) -> void {
   m_renderer.reset(renderer);
}

auto Renderer::clear_background() const -> void {
   SDL_SetRenderDrawColor(m_renderer.get(), 0x00, 0x00, 0x00, 0xFF);
   SDL_RenderClear(m_renderer.get());
}

auto Renderer::present() const -> void {
   SDL_RenderPresent(m_renderer.get());
}
