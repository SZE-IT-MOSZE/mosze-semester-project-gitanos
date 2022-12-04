#include "classes.h"
#include <cstdio>

#include <iostream>
#include <io.h>
#include <fcntl.h>
//#pragma execution_character_set( "utf-8" )
using namespace std;

int wmain() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"K�rlek, sima Command Prompt-ban futtasd a j�t�kot a teljes �lm�ny�rt!" <<endl;
    std::system("PAUSE");
    wstring link = L"_start";
    wstring path = L"../story/";
    Story* story = new Story(path, link, link);


    SetConsoleOutputCP(65001);
    std::system("CLS");

    Game_Handler* game = new Game_Handler(story);
    game->run(story);

    delete story;
    delete game;
    system("PAUSE");
}