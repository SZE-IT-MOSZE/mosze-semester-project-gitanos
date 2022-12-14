#include "functions.h"

class Story {

public:
    std::wstring path;
    std::wstring raw_text;
    std::wstring link;
    std::wstring prev_link;
    std::wstring body;
    std::vector<std::wstring> btn_texts;
    std::vector<std::wstring> btn_links;
    bool is_art = false;


    Story(std::wstring story_path, std::wstring btn_link, std::wstring pr_link) {
        // initialise values
        path = story_path;
        prev_link = pr_link;

        link = btn_link;
        prev_link = pr_link;
        is_art = check_if_art(btn_link);
        raw_text = link_to_raw_text(btn_link);
        split_to_body_and_links(btn_link);
    }

 //private: // for test purposes, methods stay public

    bool check_if_art(std::wstring btn_link) {
        // check if [btn_link] ends with ".art" (given that only one dot is present)
        int pos = btn_link.find(L".");
        if (pos != -1) {
            if (btn_link.substr(pos) == L".art") {
                return true;
            }
            else {
                return false;
            }
        }
        return false;
    }

    std::wstring link_to_raw_text(std::wstring btn_link) {
        // transform the [btn_link].game file to a wstring
        return functions::read_file(path+btn_link+L".game");
    }

    void split_to_body_and_links(std::wstring btn_link) {
        // split raw_text into vectors of wstrings based on a specific rule:
        // | is the beginning of a btn text
        // > follows the btn text, is the beginning of a btn link

        std::vector<std::wstring> text_array = functions::split(raw_text, L"|");
        for (int i = 1; i < text_array.size(); i++) {
            std::vector<std::wstring> btn_parts = functions::split(text_array[i], L">");
            btn_texts.push_back(btn_parts[0]);
            btn_links.push_back(btn_parts[1].erase(btn_parts[1].find_last_not_of(L" \n\r\t") + 1));
        }

        body = text_array[0];

    }

};

class Game_Handler {
public:
    Game_Handler(Story* start_story) { print_story(start_story); }

private:
    void print_story(Story* next_story) {

        std::wcout << next_story->body << std::endl;
        for (short i = 0; i < next_story->btn_texts.size(); i++) {
            std::wcout << i << L": " << next_story->btn_texts[i] << std::endl;
        }
    }

public:
    void run(Story* story) {

        std::map<std::wstring, bool> subjects = {
            {L"01_szgmvizsgajo", false},
            {L"02_kommism_vita", false},
            {L"02_halo", false},
            {L"02_kollab", false},
            {L"02_robot", false},
            {L"05_mosze", false}
        };

        if (story->raw_text != L"") {
            std::wstring input_to_validate;
            short option;
            std::wstring path = story->path;
            std::wstring link = story->link;
            std::wstring prev_link = story->link;



            while ((story->btn_links.size()) || (story->is_art)) {
                if (subjects.find(link) != subjects.end()) {
                    subjects.find(link)->second = true;
                }
                if (!(story->is_art)) {
                    bool valid = false;
                    while (valid == false) {
                        std::wcout << L"Válassz opciót (szám): ";
                        std::wcin >> input_to_validate;
                        valid = functions::input_validation(input_to_validate, &option);

                        try {
                            story->btn_links.at(option); // test if out of range
                            link = story->btn_links[option];
                        }
                        catch (const std::out_of_range& e) {
                            std::wcout << L"Az opció nem létezik! ";
                            valid = false;
                        }
                    }
                }
                else {
                    std::system("PAUSE");
                    link = story->prev_link;
                }
                prev_link = story->link;
                path = story->path;
                delete story;
                story = new Story(path, link, prev_link);
                system("CLS");
                if (story->is_art) { functions::set_console_appearance(5); }
                else { functions::set_console_appearance(20); }
                this->print_story(story);
            }
            std::wcout << L"Köszönjük, hogy velünk játszottál!\n\n"
                L"A következő tantárgyakat sikerült teljesítened: \n";
            for (auto const& x : subjects) {
                if (x.second) {
                    if (x.first == L"01_szgmvizsgajo") { std::wcout << L"Számítógépek működése" << std::endl; }
                    if (x.first == L"02_kommism_vita") { std::wcout << L"Kommunikációs ismeretek" << std::endl; }
                    if (x.first == L"02_halo") { std::wcout << L"Számítógépes hálózatok" << std::endl; }
                    if (x.first == L"02_kollab") { std::wcout << L"Kollaboráció a jövő internetén" << std::endl; }
                    if (x.first == L"02_robot") { std::wcout << L"Robot programozás" << std::endl; }
                    if (x.first == L"05_mosze") { std::wcout << L"Modern szoftverfejlesztési eszközök" << std::endl; }
                }
                
            }

            std::wcout << L"\n\nKészítette: Babos Kristóf, Fazekas Richárd, "
                L"Göntér Mátyás, Lendvai Áron\n\n\n\n\n";
        }
        else { 
            std::wcout << L"Nem sikerült beolvasni a kezdőtörténetet.\n"
                L"Ellenőrizd az elérési útvonalat!\n\n\n"
                L"(game.cpp-hez képest " + story->path + L")\n\n"; }
    }

};
