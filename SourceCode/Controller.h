#pragma once
#include <SFML/Graphics.hpp>
#include "Render_window.h"
#include "symbols.h"
using namespace sf;

static class Controller
{
private:
    //���������� �� ����� ������ ����.
    bool is_clicked;

    //�����, �� ������� ������.
    Vector2i selected;

    //���������� ������� ������ ������� ����.
    Vector2i click_mouse_position;
public:
    //���� ��������� ������� �� ����� ����.
    void poll_event(RenderWindow* game_window, char field[5][5]);

    //���� ��������� ������� �� ��������� ������.
    void start_click(RenderWindow* game_window, bool& is_click);

    //���� ��������� ������� �� �������� ������.
    void finish_click(RenderWindow* game_window, bool& is_click);

    //��������� ������� �� �����.
    void process_click(Event& event, char field[5][5]);

    //��������� �������������� �����.
    void process_move(RenderWindow* game_window, Event& event, char field[5][5]);

    // �����������
    Controller() {
        is_clicked = false;
    };
};

