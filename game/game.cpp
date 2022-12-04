#include "classes.h"
#include <cstdio>

#pragma execution_character_set( "utf-8" )
using namespace std;

int main() {
    string link = "_start";

    Story* story = new Story("../story/", link, link);

    SetConsoleOutputCP(65001);
    std::system("CLS");

    Game_Handler* game = new Game_Handler(story);
    game->run(story);

    delete story;
    delete game;
    system("PAUSE");
}