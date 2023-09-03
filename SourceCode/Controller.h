#pragma once
#include <SFML/Graphics.hpp>
#include "Render_window.h"
#include "symbols.h"
using namespace sf;

static class Controller
{
private:
    //Нажималась ли левая кнопка мыши.
    bool is_clicked;

    //Фишка, на которую нажали.
    Vector2i selected;

    //Координаты нажатия левкой кнопкой мыши.
    Vector2i click_mouse_position;
public:
    //Цикл обработки событий во время игры.
    void poll_event(RenderWindow* game_window, char field[5][5]);

    //Цикл обработки событий на стартовом экране.
    void start_click(RenderWindow* game_window, bool& is_click);

    //Цикл обработки событий на фишишном экране.
    void finish_click(RenderWindow* game_window, bool& is_click);

    //Обработка нажатия по фишке.
    void process_click(Event& event, char field[5][5]);

    //Обработка перетаскивания фишки.
    void process_move(RenderWindow* game_window, Event& event, char field[5][5]);

    // Конструктор
    Controller() {
        is_clicked = false;
    };
};

