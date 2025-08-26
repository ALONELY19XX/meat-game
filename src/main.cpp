#include "game/game.h"

auto main() -> int {
   meat::Game game{};

   if (game.init()) {
      game.run();
   }

   return 0;
}
