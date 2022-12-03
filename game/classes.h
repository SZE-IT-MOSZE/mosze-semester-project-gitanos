#include "functions.h"

class Story {

public:
    std::string raw_text;
    std::string link;
    std::string body;
    std::vector<std::string> btn_texts;
    std::vector<std::string> btn_links;
    bool is_art = false;

    Story(std::string btn_link) {
        // initialise values
        link = btn_link;
        is_art = check_if_art(btn_link);
        raw_text = link_to_raw_text(btn_link);
        split_to_body_and_links(btn_link);
    }

    //private: // for test purposes, methods stay public

    bool check_if_art(std::string btn_link) {
        // check if [btn_link] ends with ".art" (given that only one dot is present)
        int pos = btn_link.find(".");
        if (pos != -1) {
            if (btn_link.substr(pos) == ".art") {
                return true;
            }
            else {
                return false;
            }
        }
        return false;
    }

    std::string link_to_raw_text(std::string btn_link) {
        // transform the [btn_link].game file to a string
        std::ifstream in_file;

        in_file.open("../story/" + btn_link + ".game"); // open the input file

        std::stringstream str_stream;
        str_stream << in_file.rdbuf(); // read the file

        return str_stream.str(); // str holds the content of the file
    }

    void split_to_body_and_links(std::string btn_link) {
        // split raw_text into vectors of strings based on a specific rule:
        // | is the beginning of a btn text
        // > follows the btn text, is the beginning of a btn link

        std::vector<std::string> text_array = functions::split(raw_text, "|");
        for (int i = 1; i < text_array.size(); i++) {
            std::vector<std::string> btn_parts = functions::split(text_array[i], ">");
            btn_texts.push_back(btn_parts[0]);
            btn_links.push_back(btn_parts[1].erase(btn_parts[1].find_last_not_of(" \n\r\t") + 1));
        }

        body = text_array[0];

    }

};

class Game_Handler {
    // on second thought, this can be replaced with a basic function

public:
    Game_Handler(Story* start_story) { print_story(start_story); }
    void print_story(Story* next_story) {

        std::cout << next_story->body << std::endl;
        for (short i = 0; i < next_story->btn_texts.size(); i++) {
            std::cout << i << ": " << next_story->btn_texts[i] << std::endl;
        }

    }
    void run(Story* story) {

        std::string input_to_validate;
        short option;

        std::string link = story->link;

        functions::set_console_appearance(20);

        while (link != "") {

            bool valid = false;
            while (valid == false) {
                std::cout << "Please choose an option (integer): ";
                std::cin >> input_to_validate;
                valid = functions::input_validation(input_to_validate, &option);

                try {
                    story->btn_links.at(option); // test if out of range
                    link = story->btn_links[option];
                }
                catch (const std::out_of_range& e) {
                    std::cout << "Option not valid. ";
                    valid = false;
                }
            }
            delete story;

            system("CLS");

            story = new Story(link);
            if (story->is_art) { functions::set_console_appearance(5); }
            else { functions::set_console_appearance(20); }
            this->print_story(story);
        }
    }

};
