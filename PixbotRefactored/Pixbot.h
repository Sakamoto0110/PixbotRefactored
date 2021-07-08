#pragma once
#include "ClientInput.h"
#include "GameIA.h"
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





void Client() {
    printf("Client start\n");
    HWND hwnd = FindWindow(NULL, L"League of Legends");
    SetWindowPos(hwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOSIZE);
    Sleep(2000);
    clickPlay();
    Sleep(2000);
    clickCoopVsIa();
    Sleep(2000);
    clickIntermediate();
    Sleep(2000);
    clickConfirm();
    Sleep(2000);
    
    
	

again:
	clickFindMatch();
    bool result = false;
    int timed_out_limit = 30;
    while (!result) {
        
        clickAcceptMatch();
        Sleep(4000);        

        HDC hdc = GetDC(FindWindow(NULL,L"League of Legends"));

        
        COLORREF color[6];
        int red[6] = { 0,0,0,0,0,0 };
        int green[6] = { 0,0,0,0,0,0 };
        int blue[6] = { 0,0,0,0,0,0 };

        

        color[0] = GetPixel(GetDC(NULL), (int)(CLIENT_WIDTH * 0.352344), (int)(CLIENT_HEIGHT * 0.047222));
        color[1] = GetPixel(GetDC(NULL), (int)(CLIENT_WIDTH * 0.632812), (int)(CLIENT_HEIGHT * 0.036111));
        color[2] = GetPixel(GetDC(NULL), (int)(CLIENT_WIDTH * 0.453906), (int)(CLIENT_HEIGHT * 0.040278));
        color[3] = GetPixel(GetDC(NULL), (int)(CLIENT_WIDTH * 0.367188), (int)(CLIENT_HEIGHT * 0.041667));
        // EXTRA
        color[4] = GetPixel(GetDC(NULL), (int)(CLIENT_WIDTH * 0.405469), (int)(CLIENT_HEIGHT * 0.011111));
        color[5] = GetPixel(GetDC(NULL), (int)(CLIENT_WIDTH * 0.581250), (int)(CLIENT_HEIGHT * 0.015278));
        for (int c = 0; c < 4; c++) {
            red[c] = GetRValue(color[c]);
            green[c] = GetGValue(color[c]);
            blue[c] = GetBValue(color[c]);
            //cout << red[c]  << " " << green[c] << " " << blue[c] << endl;
        }
        if ((red[0] >= 200 && green[0] >= 200 && blue[0] >= 200) ||
            (red[1] >= 200 && green[1] >= 200 && blue[1] >= 200) ||
            (red[2] >= 200 && green[2] >= 200 && blue[2] >= 200) ||
            (red[3] >= 200 && green[3] >= 200 && blue[3] >= 200) ||
            (red[4] == 6 && green[4] == 13 && blue[4] == 17) ||
            (red[5] == 13 && green[5] == 31 && blue[5] == 30)) {
            result = true;

        }










        //result = IsInChampSelect();
        timed_out_limit--;
        if (timed_out_limit <= 0) {
            printf("Timed out\n");
            break;
        }
    }
    // select champ
    printf("Selecting champ\n");
   



    srand(time(NULL));
    
    for (int c = 0; c < 6; c++) {
        int n = rand() % 18;
 
        if (n == 1)  clickChampion1();
        if (n == 2)  clickChampion2();
        if (n == 3)  clickChampion3();
        if (n == 4)  clickChampion4();
        if (n == 5)  clickChampion5();
        if (n == 6)  clickChampion6();
        if (n == 7)  clickChampion7();
        if (n == 8)  clickChampion8();
        if (n == 9)  clickChampion9();
        if (n == 10) clickChampion10();
        if (n == 11) clickChampion11();
        if (n == 12) clickChampion12();
        if (n == 13) clickChampion13();
        if (n == 14) clickChampion14();
        if (n == 15) clickChampion15();
        if (n == 16) clickChampion16();
        if (n == 17) clickChampion17();
        if (n == 18) clickChampion18();
        Sleep(2000);
    }
    //Logger::showEvent("Champ selected\n");
   
    clickConfirmChampion();
    //Logger::showEvent("Match successfully accepted\n");
    Sleep(5000);
    clickOkERROR();
    for (int c = 0; c < 20; c++) {
        mouseMoveTo(1280/2,720/2+c*5);
        Sleep(50);
        mouseLClick();
        Sleep(50);
    }

    // check if dodge
    int dodge_timed_out = 120;
    bool dodge = true;
    while (dodge_timed_out >= 0) {
        if (FindWindow(NULL, L"League of Legends (TM) Client")) {
            // not dodge            
            dodge = false;
            break;
        }        
        dodge_timed_out--;
        Sleep(1000);
    }
    if (dodge) {
        printf("timed out, does someone dodged?\n");
        goto again;
    }

}

void PreGame() {
    Sleep(15000);
    printf("Pre game start\n");
    
    int max_width = 1280;
    int max_height = 720;
    HWND hwnd = FindWindow(NULL, L"League of Legends (TM) Client");
    SetWindowPos(hwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOSIZE);
    HDC hdc = GetDC(NULL);
    MyRGB cColor = MyRGB(GetPixel(hdc, 100, 100));
    
    int n = 0;
    int c = 0;
    do {
        printf("Trying to know if game started\n");
        Sleep(2000);
        switch (n) {
        case 1: mouseMoveTo( 0 + 5, 0 + 5 ); break;
        case 2: mouseMoveTo( 1280 - 5, 0 + 5 ); break;
        case 3: mouseMoveTo( 1280 - 5, 720 - 5 ); break;
        case 4: mouseMoveTo( 0 + 5, 720 - 5 ); break;
        }
        mouseLClick();
        
        MyRGB nColor = MyRGB(GetPixel(hdc, 100, 100));
        if (cColor.r == nColor.r && cColor.g == nColor.g && cColor.b == nColor.b) {
            c = 0;
                
        }
        else {
            c++;
            
        }
        if (c >= 10) {
            break;
        }
        n = n >= 4 ? 0 : n + 1;
    } while (1);
}

void Game() {
    printf("Game start\n");
    GameIA::Run();
}

void PosGame() {
    printf("Pos game start\n");
    //Logger::showEvent("Waiting 20000ms\n");
    Sleep(20000);
    HWND client;
    if ((client = FindWindow(NULL, L"League of Legends"))) {
        SetWindowPos(client, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE);
    }
    //Logger::showEvent("Waiting more 20000ms\n");
    Sleep(20000);

    for (int c = 0; c < 5; c++) {
        //InputHelper::Input::mouseMoveTo(1280/2,(720/2)+(c*5));
        //inputHelper.client.clickOkERROR();
        //Sleep(50);
        //InputHelper::Input::mouseLClick();
        //Sleep(10);
    }
    Sleep(2000);
    //InputHelper::Client::clickCancel();

    bool finished = false;
    int clicks = 0;
    do {
        // 470 708 - 9 30 43
        // 542 69  - 10 23 40
        // 442 798 - 12 29 45

        //px1 332 333   8  19 37
        //px2  21  18   7  17 29

        //px3 623  45   9  21 37
        //px4 346 570   9  28 42


        //Logger::showEvent("Resolving quests and trying to go to main page\n");
        //COLORREF color1 = GetPixel(GetDC(NULL),332, 333);
        COLORREF color1 = GetPixel(GetDC(NULL), 0, 0);
        int r1 = GetRValue(color1);
        int g1 = GetGValue(color1);
        int b1 = GetBValue(color1);

        //COLORREF color2 = GetPixel(GetDC(NULL),21, 18);
        COLORREF color2 = GetPixel(GetDC(NULL), 0, 0);
        int r2 = GetRValue(color2);
        int g2 = GetGValue(color2);
        int b2 = GetBValue(color2);

        //COLORREF color3 = GetPixel(GetDC(NULL),623, 45);
        COLORREF color3 = GetPixel(GetDC(NULL), 0, 0);
        int r3 = GetRValue(color3);
        int g3 = GetGValue(color3);
        int b3 = GetBValue(color3);

        //COLORREF color4 = GetPixel(GetDC(NULL),346, 570);
        COLORREF color4 = GetPixel(GetDC(NULL), 0, 0);
        int r4 = GetRValue(color4);
        int g4 = GetGValue(color4);
        int b4 = GetBValue(color4);


        if ((r1 == 8 && g1 == 19 && b1 == 37) ||
            (r2 == 7 && g2 == 17 && b2 == 29) ||
            (r3 == 9 && g3 == 21 && b3 == 37) ||
            (r4 == 9 && g4 == 28 && g4 == 42)) {
            //InputHelper::Client::clickCancel();
            clickCancel();
            finished = true;
        }
        else {
            if (clicks == 0) {
                //InputHelper::Client::clickCancel();
                clickCancel();
                Sleep(2000);
                //InputHelper::Client::skipHonror();
                skipHonror();
            }
            if (clicks == 1) {
                //InputHelper::Client::clickCancel();
                clickCancel();
                Sleep(2000);
                //InputHelper::Client::levelUp();
                levelUp();
            }
            if (clicks == 2) {
                //InputHelper::Client::clickCancel();
                clickCancel();
                Sleep(2000);
                //InputHelper::Client::selectQuestChamp();
                clickSelectQuestChamp();
                Sleep(2000);
                //InputHelper::Client::confirmQuestChamp();
                clickConfirmQuestChamp();
            }
            if (clicks == 3) {
                for (int c = 0; c < 1; c++) {
                    //InputHelper::Client::clickCancel();
                    clickCancel();
                    Sleep(1000);
                    //InputHelper::Client::clickOK();
                    clickOK();
                    Sleep(1000);
                }
            }
        }
        clicks++;
        if (clicks > 5) {
            break;
        }
        Sleep(1000);
        mouseClickAt(0.948958 * 1920, 0.005555 * 1080, 1000);
    } while (!finished);
    //InputHelper::Client::clickCancel();
    clickCancel();

}