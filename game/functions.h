#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <windows.h>
#include <codecvt>

namespace functions {

    std::wstring read_file(std::wstring filename) {
        std::wifstream wif(filename);
        wif.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
        std::wstringstream wss;
        wss << wif.rdbuf();
        std::wstring res = wss.str();
        return res;
    }

    std::vector<std::wstring> split(std::wstring s, std::wstring delimiter) {
        // split the s wstring based on the delimiter

        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        std::wstring token;
        std::vector<std::wstring> res;

        while ((pos_end = s.find(delimiter, pos_start)) != std::wstring::npos) {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(s.substr(pos_start));
        return res;

    }

    bool input_validation(std::wstring input_to_validate, short* res_num) {
        bool res = false;
        try {
            *res_num = stoi(input_to_validate);
            res = true;
        }
        catch (std::exception& err) {
            // cerr << "Conversion failure: " << err.what() << endl; // Note: what() tells the exact error
        }
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
        MoveWindow(console, 50, 25, 1300, 1000, TRUE);
    }
}