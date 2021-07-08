#pragma once
#include <Windows.h>

static void keyDown(int key) {
    INPUT input;
    WORD vkey = key;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = MapVirtualKey(vkey, MAPVK_VK_TO_VSC);
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;
    input.ki.wVk = vkey;
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));
}
static void keyUp(int key) {
    INPUT input;
    WORD vkey = key;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = MapVirtualKey(vkey, MAPVK_VK_TO_VSC);
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;
    input.ki.wVk = vkey;
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}
static void keyPress(int key) {
    keyDown(key);
    Sleep(50);
    keyUp(key);
}
static void mouseMoveTo(int x, int y) {
    SetCursorPos(x, y);
}
static void mouseMoveToSlow(int x, int y) {
    POINT lpPoint;
    GetCursorPos(&lpPoint);
    int dx = x - lpPoint.x;
    int dy = y - lpPoint.y;
    int _dx = dx < 0 ? -1 : 1;
    int _dy = dy < 0 ? -1 : 1;

    
    do {                
        if (lpPoint.x != x && lpPoint.y == y) {
            SetCursorPos(lpPoint.x + _dx, lpPoint.y);
        }
        if (lpPoint.y != y && lpPoint.x == x) {
            SetCursorPos(lpPoint.x, lpPoint.y+ _dy);
        }
        if (lpPoint.y != y && lpPoint.x != x) {
            SetCursorPos(lpPoint.x + _dx, lpPoint.y + _dy);
        }

        GetCursorPos(&lpPoint);
        
        Sleep(1);
    } while(lpPoint.x != x || lpPoint.y != y);

}

static void mouseClick(int dir) {
    INPUT Inputs[2] = { 0 };

    switch (dir)
    {
    case 1:
        Inputs[0].type = INPUT_MOUSE;
        Inputs[0].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
        Inputs[1].type = INPUT_MOUSE;        
        Inputs[1].mi.dwFlags = MOUSEEVENTF_RIGHTUP;
        break;
    case -1:
        Inputs[0].type = INPUT_MOUSE;
        Inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        Inputs[1].type = INPUT_MOUSE;
        Inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
        break;
    }
    SendInput(1, &Inputs[0], sizeof(INPUT));
    Sleep(100);
    SendInput(1, &Inputs[1], sizeof(INPUT));
    //SendInput(3, Inputs, sizeof(INPUT));
}
static void mouseLClick() {
    mouseClick(-1);
}
static void mouseRClick() {
    mouseClick(1);
}
static void mouseClickAt(int x, int y, int delay) {
    mouseMoveTo(x, y);
    Sleep(delay);
    mouseLClick();
}

static void resetKeys() {
    keyDown(0x10);
    Sleep(10);
    keyUp(0x10);
    Sleep(10);
    keyDown(0x11);
    Sleep(10);
    keyUp(0x11);
}
