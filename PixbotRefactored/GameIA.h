#pragma once
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#include "GameInput.h"


static class GameIA {

    typedef struct ChatMsg {
        const char* str;
        bool used = false;
        ChatMsg() {}
        ChatMsg(const char* txt) {
            str = txt;
        }
    }CHATMSG;
    struct MyRGB {

        int r;
        int g;
        int b;

        MyRGB(COLORREF c) {
            r = c & 0xff;
            g = c >> 8 & 0xff;
            b = c >> 16 & 0xff;
        }
        MyRGB(int _r, int _g, int _b) { r = _r; g = _g; b = _b; }

        bool operator ==(const MyRGB& other) {
            return r == other.r && g == other.g && b == other.b;
        }

    };
    // GLOBAL VARS
    
    static void buyFirstItens() {
        Sleep(3000);
        //InputHelper::Input::keyDown(0x11);
        keyDown(0x11);
        Sleep(30);
        //InputHelper::Input::keyPress('Q');
        keyPress('Q');
        Sleep(30);
        //InputHelper::Input::keyUp(0x11);
        keyUp(0x11);
        Sleep(1000);
        //InputHelper::Player::buyFirst();
        buyFirst();
        Sleep(500);
        //InputHelper::Player::buyPot();
        buyPot();
        Sleep(500);

    }

    static int* generateInputStream(int follow, int streamSize) {
        /*
        pre stream:
        0 -> movement
        1 -> attack
        stream:
        moviment:
        0x00 -> follow
        0x01 -> go back
        0x02 -> go front
        Attack:
        0x0A -> cast Q
        0x0B -> cast W
        0x0C -> cast E
        0x0D -> cast R
        0x0E -> cast D
        0x0F -> cast F
        */
        int* precommands = new int[streamSize];
        srand(time(NULL));
        precommands[0] = follow;
        for (int c = 1; c < streamSize; c++) {
            int n = rand() % 5;
            if (n <= 3) {
                precommands[c] = 0;
            }
            else {
                precommands[c] = 1;
            }
        }
        srand(time(NULL));
        int* commands = new int[streamSize];
        commands[0] = precommands[0];
        for (int c = 1; c < streamSize; c++) {
            if (precommands[c] == 0) {
                int r = rand() % 100;
                if (r <= 95) {
                    // follow
                    commands[c] = 0x00;
                }
                if (r > 95 && r <= 97) {
                    // goback
                    commands[c] = 0x01;
                }
                if (r > 97) {
                    // gofront
                    commands[c] = 0x02;
                }

            }
            if (precommands[c] == 1) {
                int r = rand() % 100;
                if (r <= 22) {
                    commands[c] = 0x0A;
                }
                if (r > 22 && r <= 44) {
                    commands[c] = 0x0B;
                }
                if (r > 44 && r <= 66) {
                    commands[c] = 0x0C;
                }
                if (r > 66 && r <= 90) {
                    commands[c] = 0x0D;
                }
                if (r > 94 && r <= 97) {
                    commands[c] = 0x0E;
                }
                if (r > 97) {
                    commands[c] = 0x0F;
                }
            }
        }
        return commands;
    }
    static void processInputStream(int* commandStream, int streamPointer) {
        int command = commandStream[streamPointer];
        srand(time(NULL));
        int dx = rand() % 150 + 100;
        int dy = rand() % 150 + 100;
        dx *= (rand() % 2 == 1) ? 1 : -1;
        dy *= (rand() % 2 == 1) ? 1 : -1;

        printf("[IA] Processing input command stream");
        printf("(%i)-(%X) - ", streamPointer, command);

        switch (command) {
        case 0x00:
            //cout << "Following: " << commandStream[0] << endl;
            //InputHelper::Player::follow(commandStream[0],-150,100);
            printf("Following: %i\n", commandStream[0]);
            follow(commandStream[0], -150, 100);
            break;
        case 0x01:
            //cout << "Going back" << endl;
            //InputHelper::Player::goBack();
            printf("Going back\n");
            goBack();
            break;
        case 0x02:
            //cout << "Going front" << endl;
            //InputHelper::Player::goFront();
            printf("Going front\n");
            goFront();
            break;
        case 0x0A:
            //cout << "Casting Q" << endl;
            //InputHelper::Player::cast('Q',dx,dy);
            printf("Casting Q \n");
            cast('Q', dx, dy);
            break;
        case 0x0B:
            //cout << "Casting W" << endl;
            //InputHelper::Player::cast('W',dx,dy);
            printf("Casting W \n");
            cast('W', dx, dy);
            break;
        case 0x0C:
            //cout << "Casting E" << endl;
            //InputHelper::Player::cast('E',dx,dy);
            printf("Casting E \n");
            cast('E', dx, dy);
            break;
        case 0x0D:
            //cout << "Casting R" << endl;
            //InputHelper::Player::cast('R',dx,dy);
            printf("Casting R \n");
            cast('R', dx, dy);
            break;
        case 0x0E:
            //cout << "Casting D" << endl;
            //InputHelper::Player::cast('D',dx,dy);
            printf("Casting D \n");
            cast('D', dx, dy);
            break;
        case 0x0F:
            //cout << "Casting F" << endl;
            //InputHelper::Player::cast('F',dx,dy);
            printf("Casting F \n");
            cast('F', dx, dy);
            break;
        }
        
    }



    static bool chkLife1() {
        // use pot
        int x = GAME_WIDTH;
        int y = GAME_HEIGHT;
        COLORREF pixel = GetPixel(GetDC(NULL), (int)(x * 0.541406), (int)(y * 0.959722));
        MyRGB color = MyRGB(pixel);
        return color.r < 15 && color.g < 15 && color.b < 15;
    }
    static bool chkLife2() {
        // go back
        int x = GAME_WIDTH;
        int y = GAME_HEIGHT;
        COLORREF pixel = GetPixel(GetDC(NULL), (int)(x * 0.490625), (int)(y * 0.963889));
        MyRGB color = MyRGB(pixel);
        return color.r < 15 && color.g < 15 && color.b < 15;
    }
    static bool chkLife3() {
        // go to base
        int x = GAME_WIDTH;
        int y = GAME_HEIGHT;
        COLORREF pixel = GetPixel(GetDC(NULL), (int)(x * 0.424219), (int)(y * 0.958333));
        MyRGB color = MyRGB(pixel);
        return color.r < 15 && color.g < 15 && color.b < 15;
    }
    static bool chkLife4() {
        // dead
        int x = GAME_WIDTH;
        int y = GAME_HEIGHT;
        COLORREF pixel = GetPixel(GetDC(NULL), (int)(x * 0.357031), (int)(y * 0.959722));
        MyRGB color = MyRGB(pixel);
        return color.r < 15 && color.g < 15 && color.b < 15;
    }
    static bool chkMana() {
        int x = GAME_WIDTH;
        int y = GAME_HEIGHT;
        COLORREF pixel = GetPixel(GetDC(NULL), (int)(x * 0.392969), (int)(y * 0.977778));
        MyRGB color = MyRGB(pixel);
        return color.r < 15 && color.g < 15 && color.b < 15;
    }

    static bool usesStore() {
        if (!FindWindow(NULL, L"League of Legends (TM) Client")) {            
            return false;
        }
        buyFirst();
        buyItem9();
        Sleep(1000);

        if (!FindWindow(NULL, L"League of Legends (TM) Client")) {           
            return false;
        }

        buyItem8();
        Sleep(1000);

        if (!FindWindow(NULL, L"League of Legends (TM) Client")) {
            return false;
        }
        //InputHelper::Player::buyItem7();
        buyItem7();
        Sleep(1000);

        if (!FindWindow(NULL, L"League of Legends (TM) Client")) {
            return false;
        }
        //InputHelper::Player::buyItem6();
        buyItem6();
        Sleep(1000);

        if (!FindWindow(NULL, L"League of Legends (TM) Client")) {
            return false;
        }
        //InputHelper::Player::buyItem5();
        buyItem5();
        Sleep(1000);

        if (!FindWindow(NULL, L"League of Legends (TM) Client")) {
            return false;
        }
        //InputHelper::Player::buyItem4();
        buyItem4();
        Sleep(1000);

        if (!FindWindow(NULL, L"League of Legends (TM) Client")) {
            return false;
        }
        //InputHelper::Player::buyItem3();
        buyItem3();
        Sleep(1000);

        if (!FindWindow(NULL, L"League of Legends (TM) Client")) {
            return false;
        }
        //InputHelper::Player::buyItem2();
        buyItem2();
        Sleep(1000);

        if (!FindWindow(NULL, L"League of Legends (TM) Client")) {
            return false;
        }
        //InputHelper::Player::buyItem1();
        buyItem1();
        Sleep(1000);
        return true;
    }

    public:
        

    static void Run() {
        
       

        Sleep(3000);
        
        HWND game;
        if (FindWindow(NULL, L"League of Legends (TM) Client")) {
            game = FindWindow(NULL, L"League of Legends (TM) Client");
            SetWindowPos(game, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE);
        }
        else
        {
            printf("win not found");
        }
        HWND hwnd = GetConsoleWindow();
        SetWindowPos(hwnd, HWND_TOPMOST, 1300, 10, 0, 0, SWP_NOSIZE);
       
       
        bool goBackCD = false;
        int maxCD = 40;
        int cd = 0;
        bool itemCD = false;
        int cd1 = 0;
        int maxItemCD = 40;
        bool usesMana = true;

        bool firstBuy = true;
        bool ended = false;
        int streamSize = 64;
        int streamPointer = 0;
        int* commandStream = new int[streamSize];

        CHATMSG emote[8];
        emote[0] = ChatMsg("'-'");
        emote[1] = ChatMsg(">.<");
        emote[2] = ChatMsg(";-;");
        emote[3] = ChatMsg(":)");
        emote[4] = ChatMsg(":(");
        emote[5] = ChatMsg(":'(");
        emote[6] = ChatMsg(":D");
        emote[7] = ChatMsg("^-^");

        CHATMSG cry[2];
        cry[0] = ChatMsg("aaaaaaaaaaaaaaaaaaaaaaa");
        cry[1] = ChatMsg("mds vei, q q eu to fazendo");

        CHATMSG lag[7];
        lag[0] = ChatMsg("aaa mano, ta lagando muito");
        lag[1] = ChatMsg("q isso vei, q lag e esse");
        lag[2] = ChatMsg("q q aconteceu? travou tudo aq ;-------;");
        lag[3] = ChatMsg("maaano do ceu, q lag infernal");
        lag[4] = ChatMsg("vsf, nunca mais jogo isso");
        lag[5] = ChatMsg("olha isso, ta tudo teleportando");
        lag[6] = ChatMsg("gg lag");

        CHATMSG bug[3];
        bug[0] = ChatMsg("???? jogo travou e voltou, q");
        bug[1] = ChatMsg("q jogo bugado, pqp");
        bug[2] = ChatMsg("lel, tela travou por alguns segundos");

        CHATMSG noob[6];
        noob[0] = ChatMsg("gente, to comecando a jogar agora, entao perdao qualquer coisa >.<");
        noob[1] = ChatMsg("gente, to comecando a jogar agora, entao peguem leve, por favor >.<");
        noob[2] = ChatMsg("gente, to comecando a jogar agora, entao nao me xinguem, por favor >.<");
        noob[3] = ChatMsg("q isso, como eu morri");
        noob[4] = ChatMsg("q jogo sem graca");
        noob[5] = ChatMsg("alguem me ensina a jogar? >.<");

        do {
            srand(time(NULL));
            if (firstBuy) {
                printf("Making first buy and waiting 30000ms\n");
                int msg = rand() % 3;
                //InputHelper::Player::useChat(noob[msg].str);
                useChat(noob[msg].str);
                noob[0].used = true;
                noob[1].used = true;
                noob[2].used = true;
                Sleep(1000);
                buyFirstItens();


                


                
                Sleep(30000);
                int x = GAME_WIDTH;
                int y = GAME_HEIGHT;
                COLORREF pixel = GetPixel(GetDC(NULL), (int)(x * 0.392969), (int)(y * 0.977778));                
                MyRGB color = pixel;
                int b = color.b;
                usesMana = b > 100;
                //cout << "Uses mana: " << usesMana << endl;
                firstBuy = false;
                
            }
            if (streamPointer == 0) {
                //Logger::showEvent("Generating input command stream: \n");
                printf("Generating input command stream: \n");
                srand(time(NULL));
                int f = rand() % 4;
                commandStream = generateInputStream(f, streamSize);
                commandStream[0] = f;
                for (int c = 0; c < streamSize; c++) {
                    if (c % (streamSize / 4) == 0) {
                        printf("\n  ");
                    }
                    printf("%X", commandStream[c]);
                }
                printf("\n");
                //Logger::showEvent("\nDone. \n");
                streamPointer++;
            }

            // STORE HANDLE
            Sleep(200);
            //InputHelper::Player::closeStore();
            closeStore();
            Sleep(200);

            // LEVEL UP HANDLE
            //InputHelper::Player::levelUp('R');
            //InputHelper::Player::levelUp('W');
            //InputHelper::Player::levelUp('E');
            //InputHelper::Player::levelUp('Q');
            levelUp('R');
            levelUp('W');
            levelUp('E');
            levelUp('Q');
            Sleep(100);

            if (usesMana && chkMana()) {
                //cout << "Mana low, return base" << endl;
                //InputHelper::Player::goB();
                goB();
            }

            // LIFE HANDLE
            if (chkLife1()) {
                // damaged
                if (!itemCD) {
                    //cout << "time to use itens?" << endl;
                    
                    //InputHelper::Player::useItens();
                    printf("time to use itens?\n");
                    useItens();
                    itemCD = true;
                }
            
            }
            if (chkLife2()) {
                // life ok

                if (!goBackCD) {
                    //cout << "time to step back?" << endl;
                    //InputHelper::Player::goBack();
                    printf("time to step back?\n");
                    goBack();
                    goBackCD = true;
                }
               
            }
            if (chkLife3()) {
                // life low
                //cout << "Life low?" << endl;
                //InputHelper::Player::goB();
                goB();
                for (int c = 0; c < 10; c++) {
                    if (!FindWindow(NULL, L"League of Legends (TM) Client"))
                        ended = true;
                    Sleep(1000);
                }
                if (!usesStore())
                    ended = true;
            }
            if (chkLife4()) {
                // dead
                //cout << "Dead?" << endl;
                int chatType = rand() % 4;
                if (chatType == 0) {
                    // cry 2
                    int msg = rand() % 2;
                    if (!cry[msg].used) {
                        cry[msg].used = true;
                        //InputHelper::Player::useChat(cry[msg].str);
                        useChat(cry[msg].str);
                    }
                }
                if (chatType == 0) {
                    // lag 7
                    int msg = rand() % 7;
                    if (!lag[msg].used) {
                        lag[msg].used = true;
                        //InputHelper::Player::useChat(lag[msg].str);
                        useChat(lag[msg].str);
                    }
                }
                if (chatType == 0) {
                    // bug 3
                    int msg = rand() % 3;
                    if (!bug[msg].used) {
                        bug[msg].used = true;
                        //InputHelper::Player::useChat(bug[msg].str);
                        useChat(bug[msg].str);
                    }
                }
                if (chatType == 0) {
                    // noob 4
                    int msg = rand() % 4;
                    if (!noob[msg].used) {
                        noob[msg].used = true;
                        //InputHelper::Player::useChat(noob[msg].str);
                        useChat(noob[msg].str);
                    }
                }
                if (!usesStore())
                    ended = true;
            }

            // COOLDOWNS HANDLE
            if (goBackCD) {
                cd++;
                if (cd > maxCD) {
                    cd = 0;
                    goBackCD = false;
                }
            }
            if (itemCD) {
                cd1++;
                if (cd1 > maxItemCD) {
                    cd1 = 0;
                    itemCD = false;
                }
            }
            Sleep(100);





            // COMMAND STREAM HANDLE
            if (streamPointer < streamSize) {
                processInputStream(commandStream, streamPointer);
                streamPointer++;
            }
            else {
                streamPointer = 0;
            }

            if (!FindWindow(NULL, L"League of Legends (TM) Client"))
                ended = true;

            if (GetAsyncKeyState(0x7A)) {
                system("pause");
            }
            if (ended) {
                //Logger::showEvent("Game ended \n");
            }

          
        } while (!ended);
        
        delete[] commandStream;







    }


};