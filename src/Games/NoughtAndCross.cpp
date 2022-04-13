#include "NoughtAndCross.h"
#include <p6/p6.h>
#include <iostream>
#include <optional>

static float case_radius(const int& board_size)
{
    return 1.f / static_cast<float>(board_size);
}

static glm::vec2 case_bottom_left_corner(case_index case_index, const int& board_size)
{
    const auto index = glm::vec2{static_cast<float>(case_index.y),
                                 static_cast<float>(case_index.x)};
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
    for (int x = 0; x < board_size; x++) {
        for (int y = 0; y < board_size; y++) {
            draw_case({x, y}, board_size, ctx);
        }
    }
}

static std::optional<case_index> case_hovered(glm::vec2 mousse_position, const int& board_size)
{
    const auto position = p6::map(mousse_position, glm::vec2{-1.f}, glm::vec2{1.f}, glm::vec2{0.f},
                                  glm::vec2{static_cast<float>(board_size)});

    const auto index = case_index{static_cast<int>(std::floor(position.x)), static_cast<int>(position.y)};
    if (index.x >= 0 && index.x < board_size && index.y >= 0 && index.y < board_size) {
        return std::make_optional(index);
    }
    else {
        return std::nullopt;
    }
}

void play_nought_and_cross()
{
    auto      ctx        = p6::Context{{1280, 720, "Noughts and Crosses"}};
    const int board_size = 3;
    ctx.update           = [&]() {
        ctx.background({0.2f, 0.8f, 0.2f});
        ctx.stroke_weight = 0.01f;
        ctx.stroke        = {1.f, 1.f, 1.f, 1.f};
        ctx.fill          = {0.f, 0.f, 0.f, 0.f};
        draw_board(board_size, ctx);
        const auto hovered_case = case_hovered(ctx.mouse(), board_size);
        if (hovered_case.has_value()) {
            ctx.fill = {0.f, 1.f, 1.f, 1.f};
            draw_case(*hovered_case, board_size, ctx);
        }
    };
    ctx.start();
}