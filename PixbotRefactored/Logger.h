#pragma once
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <stdio.h>



static void showEvent(char* content) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
    printf("[Event] %s", content);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
}

static void showMacro(char* content) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Gray);
    printf("[Macro] %s", content);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
}

static void showWarning(char* content) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Yellow);
    printf("[Warning] %s", content);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
}
static void showError(char* content) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Red);
    printf("[Error] %s", content);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
}
static void showSystem(char* content) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Green);
    printf("[System] %s", content);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);

}
