#pragma once
#include "Input.h"


int GAME_WIDTH = 1280;
int GAME_HEIGHT = 720;

static void openStore() {
    keyPress('P');
}

void buyFirst() {
    openStore();
    Sleep(800);
    mouseMoveToSlow(0.23203 * GAME_WIDTH, (int)(0.3375 * GAME_HEIGHT));
    Sleep(700);
    mouseRClick();
    Sleep(700);
    openStore();

}
void buyPot() { // 44 82
    openStore();
    Sleep(700);
    mouseMoveTo((int)(0.034375 * GAME_WIDTH), (int)(0.1138 * GAME_HEIGHT));
    Sleep(700);
    for (int c = 0; c < 5; c++) {
        mouseRClick();
        Sleep(700);
    }
    openStore();
}
void buyItem1() {
    openStore();
    Sleep(100);
    mouseMoveTo((int)(0.15703125 * GAME_WIDTH), (int)(0.434722 * GAME_HEIGHT));
    Sleep(50);
    mouseRClick();
    Sleep(100);
    openStore();
}
void buyItem2() {
    openStore();
    Sleep(100);
    mouseMoveTo((int)(0.34921875 * GAME_WIDTH), (int)(0.434722 * GAME_HEIGHT));
    Sleep(50);
    mouseRClick();
    Sleep(100);
    openStore();
}
void buyItem3() {
    openStore();
    Sleep(100);
    mouseMoveTo((int)(0.50625 * GAME_WIDTH), (int)(0.434722 * GAME_HEIGHT));
    Sleep(50);
    mouseRClick();
    Sleep(100);
    openStore();
}
void buyItem4() {
    openStore();
    Sleep(100);
    mouseMoveTo((int)(0.11796875 * GAME_WIDTH), (int)(0.96527 * GAME_HEIGHT));
    Sleep(50);
    mouseRClick();
    Sleep(100);
    openStore();
}
void buyItem5() {
    openStore();
    Sleep(100);
    mouseMoveTo((int)(0.17265625 * GAME_WIDTH), (int)(0.96527 * GAME_HEIGHT));
    Sleep(50);
    mouseRClick();
    Sleep(100);
    openStore();
}
void buyItem6() {
    openStore();
    Sleep(100);
    mouseMoveTo((int)(0.22578125 * GAME_WIDTH), (int)(0.96527 * GAME_HEIGHT));
    Sleep(50);
    mouseRClick();
    Sleep(100);
    openStore();
}
void buyItem7() {
    openStore();
    Sleep(100);
    mouseMoveTo((int)(0.27890625 * GAME_WIDTH), (int)(0.96527 * GAME_HEIGHT));
    Sleep(50);
    mouseRClick();
    Sleep(100);
    openStore();
}
void buyItem8() {
    openStore();
    Sleep(100);
    mouseMoveTo((int)(0.334375 * GAME_WIDTH), (int)(0.96527 * GAME_HEIGHT));
    Sleep(50);
    mouseRClick();
    Sleep(100);
    openStore();
}
void buyItem9() {
    openStore();
    Sleep(100);
    mouseMoveTo((int)(0.38828125 * GAME_WIDTH), (int)(0.96527 * GAME_HEIGHT));
    Sleep(50);
    mouseRClick();
    Sleep(100);
    openStore();
}
void levelUp(char skill) {
    keyDown(0x11);
    Sleep(50);
    keyPress(skill);
    Sleep(50);
    keyUp(0x11);
}
void closeStore() {
    
    mouseMoveTo((int)(0.605468 * GAME_WIDTH), (int)(0.05138 * GAME_HEIGHT));
    Sleep(300);
    mouseLClick();
}
void cast(char skill, int dx, int dy) {
    mouseMoveTo((GAME_WIDTH / 2) + dx, (GAME_HEIGHT / 2) + dy);
    keyPress(skill);
}
void follow(int n, int dx, int dy) {
    keyPress(0x71 + n);
    mouseMoveTo((GAME_WIDTH / 2) + dx, (GAME_HEIGHT / 2) + dy);
    Sleep(10);
    keyPress('A');
    Sleep(10);
    mouseLClick();

}
void goB() {
    for (int c = 0; c < 30; c++) {
        keyPress(0x20);
        mouseMoveTo((GAME_WIDTH / 2) - 400, (GAME_HEIGHT / 2) + 200);
        mouseRClick();
        Sleep(100);
    }
    keyPress('B');
}
static void centralizeCam() {
    keyPress(0x20);
    Sleep(50);
}
void goBack() {
    for (int c = 0; c < 10; c++) {
        keyPress(0x20);
        mouseMoveTo((GAME_WIDTH / 2) - 400, (GAME_HEIGHT / 2) + 200);
        mouseRClick();
        Sleep(200);
    }
}
void goFront() {
    for (int c = 0; c < 10; c++) {
        keyPress(0x20);
        mouseMoveTo((GAME_WIDTH / 2 + 200), (GAME_HEIGHT / 2) - 100);
        mouseRClick();
        Sleep(200);
    }
}
void attackNear() {
    keyPress(0x20);
    mouseMoveTo((GAME_WIDTH / 2) - 200, (GAME_HEIGHT / 2) + 100);
    mouseRClick();
}
static void idle() {
    keyPress('S');
}
static void useItens() {
    for (int c = 1; c <= 7; c++) {
        keyPress((char)c + 48);
    }
}
static void useChat(const char* content) {
    keyPress(0x0D);
    Sleep(500);
    int n = strlen(content);
    for (int c = 0; c < n; c++) {
        char ch = toupper(content[c]);
        if ((int)ch >= 65 && (int)ch <= 90) {
            keyPress(ch);
        }
        else {
            switch (ch) {
            case '<': keyDown(0x10); keyPress(0xBC); keyUp(0x10); break;
            case '>': keyDown(0x10); keyPress(0xBE); keyUp(0x10); break;
            case '(': keyDown(0x10); keyPress(0x39); keyUp(0x10); break;
            case ')': keyDown(0x10); keyPress(0x30); keyUp(0x10); break;
            case '\'': keyPress(0xC0); break;
            case '-': keyPress(0x6D); break;
            case '.': keyPress(0xBE); break;
            case ';': keyPress(0xBF); break;
            case ':': keyDown(0x10);  keyPress(0xBF); keyUp(0x10); break;
            case '?': keyDown(0x12);  keyDown(0x11);  keyPress(0x57); keyUp(0x11); keyUp(0x12); break;
            case ' ': keyPress(0x20); break;
            case '^': keyDown(0x10);  keyPress(0xDE); keyUp(0x10); break;
            }
        }
        Sleep(10);
    }
    Sleep(500);
    keyPress(0x0D);
}

