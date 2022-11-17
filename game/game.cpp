#include "classes.h"
#include <cstdio>

#pragma execution_character_set( "utf-8" )

int main() {
    SetConsoleOutputCP(65001);
    system("CLS");

    string input_to_validate;
    short option;

    string link = "_start";

    Story* story = new Story(link);
    functions::set_console_appearance(20);

    Game_Handler* game = new Game_Handler(*story);
    while (link != "") {

        bool valid = false;
        while (not valid) {
            cout << "Please choose an option (integer): ";
            cin >> input_to_validate;
            valid = functions::input_validation(input_to_validate, &option);

            try {
                story->btn_links.at(option); // test if out of range
                link = story->btn_links[option];
            }
            catch (const std::out_of_range& e) {
                cout << "Option not valid. ";
                valid = false;
            }
        }
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