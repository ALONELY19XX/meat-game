#pragma once

#include <SDL3/SDL_events.h>

namespace meat::systems {
   class InputSystem {
   public:
      InputSystem() = default;
      ~InputSystem() = default;

      auto handle_events() -> void;
      [[nodiscard]] auto should_quit() const -> bool;

   private:
      SDL_Event m_event{};
      bool m_should_quit{};
   };
}
