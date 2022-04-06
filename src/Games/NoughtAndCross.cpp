#include "NoughtAndCross.h"
#include <p6/p6.h>

void play_nought_and_cross()
{
    auto ctx   = p6::Context{{1280, 720, "Noughts and Crosses"}};
    ctx.update = [&]() {
        ctx.background({0.5f, 0.3f, 0.8f});
        ctx.square(p6::Center{0.f, 0.f}, p6::Radius{0.5f}, p6::Rotation{0.0_turn}); };
    ctx.start();
}