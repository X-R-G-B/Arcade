/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Events
*/

#include <curses.h>
#include <memory>
#include <string>
#include "EVENTS.hpp"

static const std::map<int, std::string> keyMap = {
    {KEY_UP, "KEY_UP_PRESSED"},
    {KEY_DOWN, "KEY_DOWN_PRESSED"},
    {KEY_LEFT, "KEY_LEFT_PRESSED"},
    {KEY_RIGHT, "KEY_RIGHT_PRESSED"},
    {KEY_ENTER, "KEY_ENTER_PRESSED"},
    {KEY_BACKSPACE, "KEY_BACKSPACE_PRESSED"},
    {' ', "KEY_SPACE_PRESSED"},
    {'0', "KEY_0_PRESSED"},
    {'1', "KEY_1_PRESSED"},
    {'2', "KEY_2_PRESSED"},
    {'3', "KEY_3_PRESSED"},
    {'4', "KEY_4_PRESSED"},
    {'5', "KEY_5_PRESSED"},
    {'6', "KEY_6_PRESSED"},
    {'7', "KEY_7_PRESSED"},
    {'8', "KEY_8_PRESSED"},
    {'9', "KEY_9_PRESSED"},
    {'a', "KEY_A_PRESSED"},
    {'b', "KEY_B_PRESSED"},
    {'c', "KEY_C_PRESSED"},
    {'d', "KEY_D_PRESSED"},
    {'e', "KEY_E_PRESSED"},
    {'f', "KEY_F_PRESSED"},
    {'g', "KEY_G_PRESSED"},
    {'h', "KEY_H_PRESSED"},
    {'i', "KEY_I_PRESSED"},
    {'j', "KEY_J_PRESSED"},
    {'k', "KEY_K_PRESSED"},
    {'l', "KEY_L_PRESSED"},
    {'m', "KEY_M_PRESSED"},
    {'n', "KEY_N_PRESSED"},
    {'o', "KEY_O_PRESSED"},
    {'p', "KEY_P_PRESSED"},
    {'q', "KEY_Q_PRESSED"},
    {'r', "KEY_R_PRESSED"},
    {'s', "KEY_S_PRESSED"},
    {'t', "KEY_T_PRESSED"},
    {'u', "KEY_U_PRESSED"},
    {'v', "KEY_V_PRESSED"},
    {'w', "KEY_W_PRESSED"},
    {'x', "KEY_X_PRESSED"},
    {'y', "KEY_Y_PRESSED"},
    {'z', "KEY_Z_PRESSED"},
    {KEY_DC, "KEY_DEL_PRESSED"},
    {KEY_EXIT, "QUIT"},
    {KEY_BREAK, "QUIT"},
    {KEY_CLOSE, "QUIT"},
    {KEY_END, "QUIT"},
    {KEY_RESIZE, "WINDOW_RESIZE"},
    {CTRL('c'), "QUIT"},
    {27, "KEY_ESC_PRESSED"},
};

void Ncurses::System::EventsSystem::run(double deltaTime, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager)
{
    int c;

    do {
        c = getch();
        if (c == ERR) {
            continue;
        }
        auto found = keyMap.find(c);
        if (found != keyMap.end()) {
            eventManager.addEvent(found->second);
        }
    } while (c != ERR);
}
