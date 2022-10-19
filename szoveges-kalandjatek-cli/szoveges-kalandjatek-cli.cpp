#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

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
}

class Story {

public:
    string title;
    string body;
    vector<string> btn_links;
    short option;

    Story(vector<string> btn_links, short option = 0) { open_link(btn_links[option]); }

    void open_link(string btn_link) {
        std::ifstream in_file;
        in_file.open("../story/" + btn_link); // open the input file
        std::stringstream str_stream;
        str_stream << in_file.rdbuf(); // read the file

        // convert std::string to System::String
        string raw_text = str_stream.str(); // str holds the content of the file

        vector<string> text_array = functions::split(raw_text, "|");
        for (short i = 1; i < text_array.size(); i++) {
            btn_links.push_back(text_array[i]);
        }

        body = text_array[0];

    }

};

class Game {

public:
    Game(Story start_story) { next_story(start_story); }
    void next_story(Story next_story) {
        cout << next_story.title << endl;
        cout << next_story.body << endl;
        for (short i = 0; i < next_story.btn_links.size(); i++) {
            cout << i << ": " << next_story.btn_links[i];
        }

    }

};


int main() {
    vector<string> v = { "_start.game", "", "" };
    Story* s = new Story(v);
    Game* g = new Game(*s);
    delete s;
    delete g;

}