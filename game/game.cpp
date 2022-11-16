#include "classes.h"

int main() {
    system("utf8");
    system("CLS");
    short option;
    string link = "_start";

    Story* story = new Story(link);
    functions::set_console_appearance(20);

    Game_Handler* game = new Game_Handler(*story);
    while (link != "") {
        cin >> option;
        link = story->btn_links[option];
        delete story;

        system("CLS");

        story = new Story(link);
        if (story->is_art) { functions::set_console_appearance(5); }
        else { functions::set_console_appearance(20); }
        game->print_story(*story);
    }
    delete story;
    delete game;
    system("PAUSE");
}