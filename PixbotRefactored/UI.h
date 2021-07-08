#pragma once
#include <Windows.h>
#include <stdio.h>
enum Color {
    Blue = 1,
    Green,
    Aqua,
    Red,
    Purple,
    Yellow,
    White,
    Gray,
    LightBlue,
    Black,
    LightGreen,
    LightAqua,
    LightRed,
    LightPurple,
    LightYellow,
    BrightWhite
};

void adjustConsole(int n) {
    HWND console = GetConsoleWindow();
    if (n == 1) {
        // client adjust
        SetWindowPos(console, HWND_TOPMOST, 100, 900 + 10, 600, 150, SWP_SHOWWINDOW);
    }
    if (n == 2) {
        // Ingame "overlay"
        SetWindowPos(console, HWND_TOPMOST, 1920 - 600 - 20, 100, 600, 150, SWP_SHOWWINDOW);

    }
    if (n == 4) {
        // right align
        SetWindowPos(console, HWND_TOPMOST, 1280 + 10, 50, 550, 800, SWP_SHOWWINDOW);

    }

}

void adjustConsole(int n, int resX, int resY) {
    HWND console = GetConsoleWindow();
    if (n == 3) {
        // center
        SetWindowPos(console, HWND_TOPMOST, (resX / 2) - (550 / 2), (resY / 2) - (550 / 2), 550, 550, SWP_SHOWWINDOW);
    }
}

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void ShowConsoleCursor(bool showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void showLogo() {
    //line1
    int color1 = LightRed;
    int color2 = Purple;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("   $$$$$$$");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("\\  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("\\                 ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("\\                  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("\\     \n");

    //line2
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("   $$  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("__");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("\\ \\__|                ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("|                 ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("|    \n");

    //line3
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("   $$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("|  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("|");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("\\ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf(" $$");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("\\   ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("\\      ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$$$$$$");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("\\   ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$$$$$");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("\\ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$$$$$");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("\\   \n");

    //line4
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("   $$$$$$$  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("|");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf(" |\\");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("\\ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("|      ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("__");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("\\ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("__");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("\\\\_");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("_|  \n");

    //line5
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("   $$  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("____/ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("| \\");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$$$  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("/       ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("|  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("|");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("/  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("| ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("|    \n");

    //line6
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("   $$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("|      ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("| ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$  $$");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("<        ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("|  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("|");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("|  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("| ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("|");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("\\ \n");

    //line7
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("   $$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("|      ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$ ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("|");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("/\\");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("\\       ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$$$$$$  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("|\\");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$$$$$  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("| \\");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    printf("$$$$  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("|\n");

    //line8
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
    printf("   \\__|      \\__|\\__/  \\__|      \\_______/  \\______/   \\____/ \n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);

}
