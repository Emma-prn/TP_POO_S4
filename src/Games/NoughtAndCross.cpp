#include "NoughtAndCross.h"
#include <p6/p6.h>

static void draw_board(const int& size, p6::Context& ctx)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            ctx.square(p6::BottomLeftCorner{p6::map(glm::vec2{static_cast<float>(i), static_cast<float>(j)},
                                                    glm::vec2{0.f}, glm::vec2{static_cast<float>(size)},
                                                    glm::vec2{-1.f}, glm::vec2{1.f})},
                       p6::Radius{1.f / static_cast<float>(size)});
        }
    }
}

void play_nought_and_cross()
{
    auto ctx   = p6::Context{{1280, 720, "Noughts and Crosses"}};
    ctx.update = [&]() {
        ctx.background({0.5f, 0.3f, 0.8f});
        draw_board(3, ctx);
    };
    ctx.start();
}