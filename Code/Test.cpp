#include <iostream>
#include <windows.h>

enum class TextColor {
    RED = 12,
    GREEN = 10,
    BLUE = 9,
    DEFAULT = 7
};

class ColorText {
public:
    void setColor(TextColor color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, static_cast<int>(color));
    }

    void resetColor() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, static_cast<int>(TextColor::DEFAULT));
    }
};

int main() {
    ColorText text;

    text.setColor(TextColor::RED);
    std::cout << "This text is red." << std::endl;

    text.setColor(TextColor::GREEN);
    std::cout << "This text is green." << std::endl;

    text.resetColor();
    std::cout << "This text is default color." << std::endl;

    return 0;
}
