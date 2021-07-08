#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <conio.h>

#include "UI.h"
#include "Pixbot.h"

const char* dirExists(const char* path)
{
    struct stat info;
   
    if (stat(path, &info) != 0)
        return "DIR_NOT_FOUND";
    else if (info.st_mode & S_IFDIR)
        return "OK";
    else
        return "DIR_NOT_FOUND";
}
int dirExistsTwo(const char* path)
{
    struct stat info;

    if (stat(path, &info) != 0)
        return 0;
    else if (info.st_mode & S_IFDIR)
        return 1;
    else
        return 0;
}
const char* fileExists(const char* path) {
    if (FILE* file = fopen(path, "r")) {
        
        fclose(file);
        return "OK";
    }
    else {
        return "NOT_FOUND";
    }
}
bool chkFiles() {

    if (dirExistsTwo("Game_config")) {
        
        if (dirExistsTwo("Game_config/Config")) {
            return true;
        }
    }    
    return false;
}


int Run(int op) {
    system("cls");
    switch (op) {
    case 0:
        adjustConsole(4, 1920, 1080);
        Client();        
        return ++op;
    case 1:
        adjustConsole(4, 1920, 1080);
        PreGame();
        return ++op;
    case 2:
        adjustConsole(4, 1920, 1080);
        Game();
        return ++op;
    case 3:
        adjustConsole(4, 1920, 1080);
        PosGame();
        return 0;        
    }

    return -1;
}
const wchar_t* GetWC(const char* c)
{
    const size_t cSize = strlen(c) + 1;
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs(wc, c, cSize);

    return wc;
}

int main() {  
        static const char* LEAGUE_PATH = "C:\\Riot Games\\League of Legends\\";
    static const wchar_t* cTITLE = L"Pixbot 1.3";
	clock_t sTime = clock();
	SetConsoleTitle(cTITLE);
	HWND hConsole = GetConsoleWindow();
	
    // Check files
    if (!chkFiles()) {
        printf("missing files");
        system("pause");
        exit(1);
    }
    

    // Config backup and injection

    char command[512] = "xcopy ";
    char arg1[128] = "\"";
    char arg2[128] = "\"";
    char fullName[32] = "Config";

    char number[2];
    int m = 0;

    strcat(arg1, LEAGUE_PATH);
    strcat(arg1, "\\Config");
    strcat(arg1, "\"");
    do {

        char number[2];
        sprintf(number, "%d", m);
        strcpy(fullName, "Config");
        strcat(fullName, number);
        strcpy(arg2, "\"Config_old\\");
        strcat(arg2, fullName);
        strcat(arg2, "\"");
        strcpy(command, "xcopy ");
        strcat(command, arg1);
        strcat(command, " ");
        strcat(command, arg2);
        char tmp[64] = "Config_old\\";
        strcat(tmp, fullName);
        if (dirExistsTwo(tmp) == 0) {            
            CreateDirectoryW(GetWC(tmp), NULL);
            strcat(command, "/e /y");
            system(command);
            break;
        }
        m++;
    } while (1);
    Sleep(1000);


    // CONFIG INJECTION
    int i = strlen(arg1);
    char tmpStr[128] = " ";
    for (int c = 0; c < i - 1; c++) {
        tmpStr[c] = arg1[c];
    }
    tmpStr[strlen(tmpStr)] = '\"';
    strcpy(command, "xcopy ");
    strcpy(arg1, "\"");
    strcat(arg1, "Game_config\\");
    strcat(arg1, "Config\\*\"");
    strcpy(arg2, tmpStr);
    strcat(command, arg1);
    strcat(command, " ");
    strcat(command, arg2);
    strcat(command, " /i /y");
    system(command);


    // Launch game


    // Menu loop
    system("cls");
    printf("\n\n\n");
    showLogo();
    while (1) {
        SetConsoleTitle(cTITLE);
        adjustConsole(4);

        bool hasUpdate = true;
        bool apply = false;
        int selected = 16;
        while (!apply) {
            ShowConsoleCursor(false);
            if (hasUpdate) {
                //show menu
                int x = 27;
                int y = 16;

                gotoxy(x - 7, y);
                printf("       ");
                gotoxy(x + 6, y);
                printf("       ");
                gotoxy(x, y);
                printf("Start");
                y += 4;

                gotoxy(x - 7, y);
                printf("       ");
                gotoxy(x + 6, y);
                printf("       ");
                gotoxy(x, y);
                printf("Help");
                y += 4;

                gotoxy(x - 7, y);
                printf("       ");
                gotoxy(x + 6, y);
                printf("       ");
                gotoxy(x, y);
                printf("Exit");

                gotoxy(x - 6, selected);
                printf("-->");
                gotoxy(x + 7, selected);
                printf("<--");

                gotoxy(0, y + 4);
                printf("       ");
                printf("Use W / S or UP / DOWN keys to change option\n\n");
                printf("       ");
                printf("Use SPACEBAR / ENTER to confirm option");
                hasUpdate = false;
            }
            if (_kbhit()) {
                // w     -> 119
                // s     -> 115
                // enter -> 13
                // up    -> 72
                // down  -> 80
                // left  -> 75
                // right -> 77
                // space -> 32
                int key = _getch();
                if (key == 72 || key == 80 || key == 32 || key == 119 || key == 115 || key == 13) {
                    if (key == 72 || key == 119)
                        if (selected > 16) {
                            selected -= 4;
                            hasUpdate = true;
                        }
                    if (key == 80 || key == 115)
                        if (selected < 24) {
                            hasUpdate = true;
                            selected += 4;
                        }
                    if (key == 32 || key == 13) {
                        apply = true;
                    }
                }
            }
        }
        switch (selected) {
        case 16:
        {
            for (int c = 0; c < 44; c++) {
                printf("\n");
                Sleep(75);
            }
            gotoxy(0, 25);
            // RUNNING
            int op = 0;
            while( (op = Run(op)) != -1){}
            
            
        }break;
        case 20:
        {
            gotoxy(0, 16);
            for (int c1 = 16; c1 < 28; c1++) {
                for (int c = 0; c < 40; c++) {
                    gotoxy(c, c1);
                    printf(" ");
                }
            }
            gotoxy(0, 14);
            printf("             ");
            printf("Pixbot will autorun as you press start\n\n\n");
            printf("             ");
            printf("Most of loops can be paused with ESC key,\n");
            printf("     ");
            printf("so if the mouse get stuck by some macro, just press ESC\n\n\n");

            printf("          ");                                    
            printf("of the actual state (in case of problem)\n\n\n");
            printf("                   ");
            printf("Press any key to return");
            do {

            } while (!_kbhit());
            _getch();
            gotoxy(0, 12);
            for (int c1 = 12; c1 < 28; c1++) {
                for (int c = 0; c < 60; c++) {
                    gotoxy(c, c1);
                    printf(" ");
                }
            }

        }break;
        case 24:
        {
            printf("Pixbot terminated.");
            exit(1);
        }break;

        }

    }

    


	return 0;
}
