#include "NoughtAndCross.h"
#include <p6/p6.h>
#include <iostream>

static float case_radius(const int& board_size)
{
    return 1.f / static_cast<float>(board_size);
}

static glm::vec2 case_bottom_left_corner(case_index case_index, const int& board_size)
{
    const auto index = glm::vec2{static_cast<float>(case_index.row),
                                 static_cast<float>(case_index.column)};
    return p6::map(index, glm::vec2{0.f}, glm::vec2{static_cast<float>(board_size)},
                   glm::vec2{-1.f}, glm::vec2{1.f});
}

static void draw_case(case_index case_index, const int& board_size, p6::Context& ctx)
{
    ctx.square(p6::BottomLeftCorner{case_bottom_left_corner(case_index, board_size)},
               p6::Radius{case_radius(board_size)});
}

static void draw_board(const int& board_size, p6::Context& ctx)
{
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            draw_case({i, j}, board_size, ctx);
        }
    }
}

void play_nought_and_cross()
{
    auto      ctx        = p6::Context{{1280, 720, "Noughts and Crosses"}};
    const int board_size = 3;
    ctx.update           = [&]() {
        ctx.background({0.2f, 0.8f, 0.2f});
        draw_board(board_size, ctx);
    };
    ctx.start();
}