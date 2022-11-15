#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

// misc functions to shorten code
namespace functions {

    vector<string> split(string s, string delimiter) {

        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(s.substr(pos_start));
        return res;

    }

    void set_console_appearance(short size) {

        CONSOLE_FONT_INFOEX cfi;
        cfi.cbSize = sizeof cfi;
        cfi.nFont = 0;
        cfi.dwFontSize.X = 0;
        cfi.dwFontSize.Y = size;
        cfi.FontFamily = FF_DONTCARE;
        cfi.FontWeight = FW_NORMAL;
        wcscpy_s(cfi.FaceName, L"Consolas");
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

        HWND console = GetConsoleWindow();
        MoveWindow(console, 100, 100, 1000, 600, TRUE);

    }
}

class Story {

public:
    string body;
    vector<string> btn_texts;
    vector<string> btn_links;
    bool is_art = false;

    Story(string btn_link) { open_link(btn_link); }

    void open_link(string btn_link) {
        int pos = btn_link.find(".");
        if (pos != -1) {
            if (btn_link.substr(pos) == ".art") {
                is_art = true;
            }
            else {
                is_art = false;
            }
        }
        std::ifstream in_file;
        in_file.open("../story/" + btn_link + ".game"); // open the input file
        std::stringstream str_stream;
        str_stream << in_file.rdbuf(); // read the file

        // convert std::string to System::String
        string raw_text = str_stream.str(); // str holds the content of the file

        vector<string> text_array = functions::split(raw_text, "|");
        for (int i = 1; i < text_array.size(); i++) {
            vector<string> btn_parts = functions::split(text_array[i], ">");
            btn_texts.push_back(btn_parts[0]);
            btn_links.push_back(btn_parts[1].erase(btn_parts[1].find_last_not_of(" \n\r\t") + 1));
        }

        body = text_array[0];

    }

};

class Game_Handler {

public:
    Game_Handler(Story start_story) { next_story(start_story); }
    void next_story(Story next_story) {

        cout << next_story.body << endl;
        for (short i = 0; i < next_story.btn_texts.size(); i++) {
            cout << i << ": " << next_story.btn_texts[i] << endl;
        }

    }

};


int main() {
    system("utf8");
    system("CLS");
    short option;
    string link = "_start";

    Story* s = new Story(link);
    functions::set_console_appearance(20);

    Game_Handler* g = new Game_Handler(*s);
    while (link != "") {
        cin >> option;
        link = s->btn_links[option];
        delete s;

        system("CLS");

        s = new Story(link);
        if (s->is_art) { functions::set_console_appearance(5); }
        else { functions::set_console_appearance(20); }
        g->next_story(*s);
    }
    delete s;
    delete g;
    system("PAUSE");
}