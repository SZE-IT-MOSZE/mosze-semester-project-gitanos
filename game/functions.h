#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

namespace functions {

    vector<string> split(string s, string delimiter) {
        // split the s string based on the delimiter

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
        // set the console font to Consolas and font size to [size]; set console size to 1000x600

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
