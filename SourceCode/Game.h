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

    //������� ����.
    char field[5][5] = { 
        {EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY}
    };

    //��������� �� ����.
    bool is_finished_;
    //�������� �� ����.
    bool is_started_;
public:

    Game();
    ~Game();

    //������� ������� ����.
    void start_game();

    //�������, ������������ ��������� ����� �� ����.
    void generate_field();

    //�������, ��������� ���� �� �����.
    void clear_field();

    //�������, ������� ���������, ����������� �� ����.
    bool is_game_finished();

};

