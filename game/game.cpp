#include "classes.h"
#include <cstdio>

#include <iostream>
#include <io.h>
#include <fcntl.h>
//#pragma execution_character_set( "utf-8" )
using namespace std;

int wmain() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"Kérlek, sima Command Prompt-ban futtasd a játékot a teljes élményért!" <<endl;
    std::system("PAUSE");
    wstring link = L"_start";
    wstring path = L"../story/";
    Story* story = new Story(path, link, link);

    functions::set_console_appearance(20);
    SetConsoleOutputCP(65001);
    std::system("CLS");

    Game_Handler* game = new Game_Handler(story);
    game->run(story);

    delete story;
    delete game;
    system("PAUSE");
}