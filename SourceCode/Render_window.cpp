#include "Render_window.h"

void Render_window::render_start_window(RenderWindow* game_window) {
    game_window->clear(Color::White);
    draw_title_shapes(game_window);
    RectangleShape line(Vector2f(100, 5));
    line.setFillColor(Color::Green);
    line.setPosition(Vector2f((WINDOW_WIDTH - 100) / 2, WINDOW_HEITH / 2));
    game_window->draw(line);
    line.setSize(Vector2f(50, 5));
    line.rotate(-45);
    game_window->draw(line);
    line.rotate(90);
    game_window->draw(line);
    
    line.setPosition((WINDOW_WIDTH - 100) / 2 + 100, WINDOW_HEITH / 2);
    line.rotate(-135);
    game_window->draw(line);
    line.rotate(-90);
    line.move(0, -50);
    game_window->draw(line);
    game_window->display();
}

void Render_window::render_finish_window(RenderWindow* game_window) {
    game_window->clear(Color::White);
    ConvexShape convex;
    convex.setPointCount(6);

    //рисуем галочку
    convex.setPoint(0, Vector2f(200, 400));
    convex.setPoint(1, Vector2f(205, 395));
    convex.setPoint(2, Vector2f(300, 450));
    convex.setPoint(3, Vector2f(395, 300));
    convex.setPoint(4, Vector2f(400, 300));
    convex.setPoint(5, Vector2f(300, 500));

    convex.setFillColor(Color::Green);
    game_window->draw(convex);
    game_window->display();
}

void Render_window::render_field(RenderWindow* game_window, const char field[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {

            char cell = field[j][i];

            //рисуем каждую клетку
            RectangleShape rectangle(Vector2f(cell_size - 2, cell_size - 2));
            rectangle.setOutlineThickness(2);
            rectangle.setOutlineColor(Color(125, 125, 125));
            rectangle.setPosition(50 + cell_size * i, 200 + cell_size * j);
            rectangle.setFillColor(Color::White);
            game_window->draw(rectangle);

            //рисуем состояние клетки
            draw_shape(game_window, cell, 50 + cell_size * i, 200 + cell_size * j);

        }
    }
}

void Render_window::draw_shape(RenderWindow* game_window, char type, int x_pos, int y_pos) {
    switch (type) {
    case RED:
    {

        CircleShape octagon_red((cell_size - padding_cell * 2) / 2);
        CircleShape square_red((cell_size - padding_cell * 2) / 2, 4);

        octagon_red.setPosition(x_pos + padding_cell, y_pos + padding_cell);
        square_red.setPosition(x_pos + padding_cell, y_pos + padding_cell);

        square_red.setFillColor(Color(COLOR_RED));
        octagon_red.setFillColor(Color(SHAPE_BACKGROUND));

        game_window->draw(octagon_red);
        game_window->draw(square_red);
        break;
    }
    case BLUE:
    {
        CircleShape octagon_blue((cell_size - padding_cell * 2) / 2);
        CircleShape square_blue((cell_size - padding_cell * 2) / 2, 4);

        octagon_blue.setPosition(x_pos + padding_cell, y_pos + padding_cell);
        square_blue.setPosition(x_pos + padding_cell, y_pos + padding_cell);

        square_blue.setFillColor(Color(COLOR_BLUE));
        octagon_blue.setFillColor(Color(SHAPE_BACKGROUND));

        game_window->draw(octagon_blue);
        game_window->draw(square_blue);
        break;
    }
    case GREEN:
    {
        CircleShape octagon((cell_size - padding_cell * 2) / 2);
        CircleShape square((cell_size - padding_cell * 2) / 2, 4);

        octagon.setPosition(x_pos + padding_cell, y_pos + padding_cell);
        square.setPosition(x_pos + padding_cell, y_pos + padding_cell);

        square.setFillColor(Color(COLOR_GREEN));
        octagon.setFillColor(Color(SHAPE_BACKGROUND));

        game_window->draw(octagon);
        game_window->draw(square);
        break;
    }
    case BLOCKED:
    {
        RectangleShape rectangle(Vector2f(cell_size - 2 * padding_cell, 
            cell_size - 2 * padding_cell));

        rectangle.setPosition(x_pos + padding_cell, y_pos + padding_cell);

        rectangle.setFillColor(Color::Black);

        game_window->draw(rectangle);
        break;
    }
    case EMPTY:
    {
        break;
    }

    }
}

void Render_window::draw_title_shapes(RenderWindow* game_window) {
    for (int i = 0; i < 3; ++i) {
        RectangleShape rectangle(Vector2f(cell_size, cell_size));
        rectangle.setOutlineThickness(10);
        rectangle.setOutlineColor(Color(121, 201, 153));
        rectangle.setFillColor(Color::White);

        rectangle.setPosition(50 + cell_size * i * 2, 50);
        game_window->draw(rectangle);
    }
    
    draw_shape(game_window, RED, 50, 50);
    draw_shape(game_window, BLUE, 250, 50);
    draw_shape(game_window, GREEN, 450, 50);
}

void Render_window::render_window(RenderWindow* game_window, const char field[5][5]) {
    game_window->clear(Color(155, 112, 212));
    draw_title_shapes(game_window);
    render_field(game_window, field);
    game_window->display();
}

void Render_window::render_move_animation(RenderWindow* game_window, Vector2i moving_cell, Vector2i empty_cell, const char field[5][5]) {
    for (int i = 0; i < 100; i += SPEED_ANIMATION) {

        RectangleShape rectangle(Vector2f(cell_size - 2, cell_size - 2));
        rectangle.setFillColor(Color::White);
        rectangle.setPosition(50 + cell_size * moving_cell.x, 200 + cell_size * moving_cell.y);
        rectangle.setOutlineThickness(2);
        rectangle.setOutlineColor(Color(125, 125, 125));
        game_window->draw(rectangle);
        rectangle.setPosition(50 + cell_size * empty_cell.x, 200 + cell_size * empty_cell.y);
        game_window->draw(rectangle);
        

        Vector2i moving_cell_pos = { 50 + cell_size * moving_cell.x, 200 + cell_size * moving_cell.y };
        int dx = empty_cell.x - moving_cell.x;
        int dy = empty_cell.y - moving_cell.y;
        
        char cell = field[moving_cell.y][moving_cell.x];
        draw_shape(game_window, cell, 50 + cell_size * moving_cell.x + dx * i, 200 + cell_size * moving_cell.y + dy * i);
        
        game_window->display();
    }
}