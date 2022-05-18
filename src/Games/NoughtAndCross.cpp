#include "NoughtAndCross.h"
#include <p6/p6.h>
#include <array>
#include <iostream>
#include <optional>

struct case_index {
    int x;
    int y;
};

enum class Player {
    Noughts,
    Crosses,
};

template<int size>
class Board {
private:
    std::array<std::optional<Player>, size * size> _case;

public:
    std::optional<Player>& operator[](case_index case_index)
    {
        assert(case_index.x >= 0 && case_index.x < size &&
               case_index.y >= 0 && case_index.y < size);
        return _case[case_index.x + case_index.y * size];
    }
    const std::optional<Player>& operator[](case_index case_index) const
    {
        assert(case_index.x >= 0 && case_index.x < size &&
               case_index.y >= 0 && case_index.y < size);
        return _case[case_index.x + case_index.y * size];
    }

    auto begin() { return _case.begin(); }
    auto begin() const { return _case.begin(); }
    auto end() { return _case.end() }
    auto end() const { return _case.end(); }
};

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

static glm::vec2 case_center(const int& board_size, case_index case_index)
{
    return case_bottom_left_corner(case_index, board_size) + case_radius(board_size);
}

static void draw_nought(case_index case_index, const int& board_size, p6::Context& ctx)
{
    ctx.stroke        = {1, 0, 0, 0.5};
    ctx.stroke_weight = 0.15f;
    ctx.circle(p6::Center{case_center(board_size, case_index)},
               p6::Radius{0.3f});
}

static void draw_cross(case_index case_index, const int& board_size, p6::Context& ctx)
{
    p6::Angle rotation = 0_turn;
    ctx.stroke         = {1, 0, 0, 0.5};
    ctx.stroke_weight  = 0.15f;
    ctx.square(p6::Center{case_center(board_size, case_index)},
               p6::Radius{0.3f},
               p6::Rotation{rotation});
}

static void draw_player(Player current_player, case_index case_index, int board_size, p6::Context& ctx)
{
    if (current_player == Player::Crosses) {
        draw_cross(case_index, board_size, ctx);
    }
    else {
        draw_nought(case_index, board_size, ctx);
    }
}

template<int size>
void draw_noughts_and_crosses(const Board<size>& board, p6::Context& ctx)
{
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            const auto case_index = board[{x, y}];
            if (case_index.has_value()) {
                draw_player(*case_index, {x, y}, size, ctx);
            }
        }
    }
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

    const auto index = case_index{static_cast<int>(std::floor(position.y)), static_cast<int>(std::floor(position.x))};
    if (index.x >= 0 && index.x < board_size &&
        index.y >= 0 && index.y < board_size) {
        return std::make_optional(index);
    }
    else {
        return std::nullopt;
    }
}

static void change_player(Player& player)
{
    if (player == Player::Crosses) {
        player = Player::Noughts;
    }
    else {
        player = Player::Crosses;
    }
}

template<int size>
void try_to_place_symbol(std::optional<case_index>& case_index, Board<size>& board, Player& current_player)
{
    if (case_index.has_value()) {
        const auto case_is_empty = !board[*case_index].has_value();
        if (case_is_empty) {
            board[*case_index] = current_player;
            change_player(current_player);
        }
    }
}

template<int size>
void draw_symbol_in_hovered_case(Player player, Board<size> board, p6::Context& ctx)
{
    const auto hovered_case = case_hovered(ctx.mouse(), size);
    if (hovered_case.has_value() && !board[*hovered_case].has_value()) {
        draw_player(player, *hovered_case, size, ctx);
    }
}

template<int size>
std::optional<Player> check_for_winner_on_line(const Board<size>& board, std::function<case_index(int)> index_generator)
{
    const bool equal = [&]() {
        for (int position = 0; position < size - 1; position++) {
            if (board[index_generator(position)] != board[index_generator(position + 1)]) {
                return false;
            }
        }
        return true;
    }();
    if (equal && board[index_generator(0)].has_value()) {
        return board[index_generator(0)];
    }
    else {
    }
    return std::nullopt;
}

template<int size>
std::optional<Player> check_for_winner(const Board<size>& board)
{
    std::optional<Player> winner = std::nullopt;
    for (int x = 0; x < size && !winner.has_value(); x++) {
        winner = check_for_winner_on_line(board, [x](int position) {
            return case_index{x, position};
        });
    }
    for (int y = 0; y < size && !winner.has_value(); y++) {
        winner = check_for_winner_on_line(board, [y](int position) {
            return case_index{position, y};
        });
    }
    if (!winner.has_value()) {
        winner = check_for_winner_on_line(board, [](int position) {
            return case_index{position, position};
        });
    }
    if (!winner.has_value()) {
        winner = check_for_winner_on_line(board, [](int position) {
            return case_index{position, size - position - 1};
        });
    }
    return winner;
}

template<int size>
bool board_is_full(const Board<size>& board)
{
    return std::all_of(board.begin(), board.end(), [](const auto& cell) {
        return cell.has_value();
    });
}

template<int size>
bool game_is_finished(const Board<size>& board)
{
    if (auto winner = check_for_winner(board)) {
        if (*winner == Player::Crosses) {
            std::cout << "The Crosses won !" << std::endl;
        }
        else {
            std::cout << "The Noughts won !" << std::endl;
        }
        return true;
    }
    else if (board_is_full(board)) {
        std::cout << "Well...Draw..." << std::endl;
        return true;
    }
    else {
        return false;
    }
}

void play_nought_and_cross()
{
    const int board_size     = 3;
    auto      ctx            = p6::Context{{1280, 720, "Noughts and Crosses"}};
    auto      board          = Board<board_size>{};
    Player    current_player = Player::Crosses;
    ctx.mouse_pressed        = [&](p6::MouseButton event) {
        try_to_place_symbol(case_hovered(event.position, board_size), board, current_player);
    };
    ctx.update = [&]() {
        ctx.background({0.2f, 0.8f, 0.2f});
        ctx.stroke_weight = 0.01f;
        ctx.stroke        = {1.f, 1.f, 1.f, 1.f};
        ctx.fill          = {0.f, 0.f, 0.f, 0.f};
        draw_board(board_size, ctx);
        draw_noughts_and_crosses(board, ctx);
        draw_symbol_in_hovered_case(current_player, board, ctx);
        if (game_is_finished(board)) {
            ctx.stop();
        }
    };
    ctx.start();
}