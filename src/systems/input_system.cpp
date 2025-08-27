#include "input_system.h"
#include <SDL3/SDL.h>

namespace meat::systems {
   auto InputSystem::handle_events() -> void {
      while (SDL_PollEvent(&m_event)) {
         switch (m_event.type) {
         case SDL_EVENT_QUIT:
            m_should_quit = true;
            break;
         default:
            // pass
            break;
         }
      }
   }

   auto InputSystem::should_quit() const -> bool {
      return m_should_quit;
   }
}
