#include "Controller.h"

void Controller::start_click(RenderWindow* game_window, bool& is_click) {
    Event event;
    while (game_window->pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            game_window->close();
        }
        if (event.type == Event::MouseButtonPressed)
        {
            if (event.key.code == Mouse::Left)
            {
                is_click = true;
            }
        }
    }
}

void Controller::poll_event(RenderWindow* game_window, char field[5][5]) {
    Event event;
    while (game_window->pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            game_window->close();
        }
        if (event.type == Event::MouseButtonPressed)
        {
            if (event.key.code == Mouse::Left)
            {
                process_click(event, field);

            }
        }
        if (event.type == Event::MouseButtonReleased) {
            if (event.key.code == Mouse::Left) {
                is_clicked = false;
            }
        }
        if (event.type == Event::MouseMoved)
        {

            if (is_clicked)
            {
                process_move(game_window, event, field);
            }
            break;
        }

    }

}

void Controller::process_click(Event& event, char field[5][5]) {
    auto mb = event.mouseButton;
    if (mb.x > 50 && mb.x < 50 + CELL_SIZE * 5 && mb.y > 200 && mb.y < WINDOW_HEITH - 50) {
        click_mouse_position = { mb.x, mb.y };
        int x = (click_mouse_position.x - 50) / CELL_SIZE;
        int y = (click_mouse_position.y - 200) / CELL_SIZE;
        if (field[y][x] != EMPTY && field[y][x] != BLOCKED) {
            is_clicked = true;
            selected = { x, y };
        }
    }
}

void Controller::process_move(RenderWindow* game_window, Event& event, char field[5][5]) {
    auto mn = event.mouseMove;
    int dx = mn.x - click_mouse_position.x;
    int dy = mn.y - click_mouse_position.y;
    int dx_pos = 0;
    int dy_pos = 0;
    if (dx > 25) {
        dx_pos = 1;
        dy_pos = 0;
    }
    else if (dx < -25) {
        dx_pos = -1;
        dy_pos = 0;
    }
    else if (dy > 25) {
        dx_pos = 0;
        dy_pos = 1;
    }
    else if (dy < -25) {
        dx_pos = 0;
        dy_pos = -1;
    }
    if (field[selected.y + dy_pos][selected.x + dx_pos] == EMPTY) {
        is_clicked = false;
        Render_window::render_move_animation(game_window, selected,
            { selected.x + dx_pos, selected.y + dy_pos }, field);

        char temp = field[selected.y][selected.x];
        field[selected.y][selected.x] = field[selected.y + dy_pos][selected.x + dx_pos];
        field[selected.y + dy_pos][selected.x + dx_pos] = temp;
        click_mouse_position.x = 0;
        click_mouse_position.y = 0;

        
    }
}

void Controller::finish_click(RenderWindow* game_window, bool& is_click) {
    Event event;
    while (game_window->pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            game_window->close();
        }
        if (event.type == Event::MouseButtonPressed)
        {
            if (event.key.code == Mouse::Left)
            {
                is_click = false;
            }
        }
    }
}

