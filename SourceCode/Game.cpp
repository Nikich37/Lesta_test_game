#include "Game.h"


Game::Game() {
    game_window_ = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEITH), "Lesta RGB Pazzle", Style::Close | Style::Titlebar);
    is_finished_ = false;
    is_started_ = false;
}

Game::~Game() {
    delete game_window_;
}

void Game::generate_field() {
    srand(time(0));
    int x, y;
    char colors[] = { RED, BLUE, GREEN };
    for (int i = 0; i < 3; ++i) {
        char type_cell = colors[i];
        for (int j = 0; j < 5; ++j) {
            do {
                x = (rand() % 3);
                y = (rand() % 5);
            } while (field[y][x * 2] != EMPTY);
            field[y][x * 2] = type_cell;
        }
    }
}

void Game::clear_field() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; j++) {
            field[j][i * 2] = EMPTY;
        }
    }
}

void Game::start_game() {
    
    game_window_->setFramerateLimit(60);
    generate_field();
    while (game_window_->isOpen())
    {
        is_finished_ = is_game_finished();
        if (is_started_ && !is_finished_) {
            game_controller_.poll_event(game_window_, field);
            Render_window::render_window(game_window_, field);
        }
        else if(!is_started_ && !is_finished_) {
            game_controller_.start_click(game_window_, is_started_);
            Render_window::render_start_window(game_window_);
        }
        else {
            is_started_ = false;
            game_controller_.finish_click(game_window_, is_finished_);
            if (!is_finished_) {
                clear_field();
                generate_field();
            }
            Render_window::render_finish_window(game_window_);
        }
    }
}

bool Game::is_game_finished() {
    for (int i = 0; i < 5; i++) {
        if (field[i][0] != RED) return false;
        if (field[i][2] != BLUE) return false;
        if (field[i][4] != GREEN) return false;
    }
    return true;
}