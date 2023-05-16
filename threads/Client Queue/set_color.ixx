#include <Windows.h>
export module set_color;

export class consol_color {
public:
    static void SetColor(int text_color, int background_color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        int color_code = background_color * 16 + text_color;
        SetConsoleTextAttribute(hConsole, color_code);
    }
};
