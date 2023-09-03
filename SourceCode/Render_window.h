#pragma once
#include <SFML/Graphics.hpp>
#include "symbols.h"
using namespace sf;

static class Render_window
{
private:
    const static int cell_size = CELL_SIZE;
    const static int padding_cell = PADDING_CELL;

public:
    // Отрисовка поля.
    static void render_field(RenderWindow* game_window, const char field[5][5]);

    //Отрисовка трех фишек над полем.
    static void draw_title_shapes(RenderWindow* game_window);

    //Отрисовка игрового окна.
    static void render_window(RenderWindow* game_window, const char field[5][5]);

    //Анимация передвижения фишки.
    static void render_move_animation(RenderWindow* game_window, Vector2i moving_cell, Vector2i empty_cell, const char field[5][5]);

    //Отрисовка отдельной фишки.
    static void draw_shape(RenderWindow* game_window, char type, int i, int j);

    //Отрисовка стартогово окна.
    static void render_start_window(RenderWindow* game_window);

    //Отрисовка финишного окна.
    static void render_finish_window(RenderWindow* game_window);
};

