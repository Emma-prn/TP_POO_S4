#include "NoughtAndCross.h"
#include <p6/p6.h>

void create_window()
{
    auto ctx   = p6::Context{{1280, 720, "Noughts and Crosses"}};
    ctx.update = [&]() {
        ctx.background({0.5f, 0.3f, 0.8f});
        ctx.square(p6::Center{0.f, 0.f}, p6::Radius{0.98f}, p6::Rotation{0.01_turn});
        ctx.circle(p6::Center{ctx.mouse()}, 
                   p6::Radius{0.3f}); };
    ctx.start();
}