#pragma once
#include <SFML/Graphics.hpp>
#include "Render_window.h"
#include "Controller.h"
#include "symbols.h"
using namespace sf;



class Game
{
private:


    RenderWindow* game_window_;
    Controller game_controller_;

    //Игровое поле.
    char field[5][5] = { 
        {EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY}
    };

    //Закончена ли игра.
    bool is_finished_;
    //Началась ли игра.
    bool is_started_;
public:

    Game();
    ~Game();

    //Функция запуска игры.
    void start_game();

    //Функция, генерирующая случайные фишки на поле.
    void generate_field();

    //Функция, очищающая поле от фишек.
    void clear_field();

    //Функция, которая проверяет, завершилась ли игры.
    bool is_game_finished();

};

