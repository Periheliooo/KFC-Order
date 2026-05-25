// 124033910070 GTY SJTU-CS
// Created on 2025.4.22, Jiangchuan Rd., Minhang

#include <iostream>
#include <iomanip>
#include <cstring>
#include "tools.h"
#include "alloc-monitor.h"

using namespace std;


void clearScreen() {
    cout << "\033[2J\033[H";
}


void setwPrint(const char* str, int width, bool rightAlign) {
    bool isGB = strlen("孙") == 2;

    cout << (rightAlign ? right : left);
    if (isGB) {
        cout << setw(width);
        cout << str;
        return;
    }

    int nChnCh = 0; // counts how many Chinese characters
    const char* p = str;

    while (*p) {
        if (*p > 0) {
            p++;
        }
        else {  // Non-ASCII detected!
            p += 2 + !isGB;
            nChnCh ++;
        }
    }

    cout << setw(width + nChnCh);
    cout << str;
}


void setwPrint(char c, int width, bool rightAlign) {
    cout << (rightAlign ? right : left) << setw(width) << c;
}


void setwPrint(double d, int width, bool rightAlign) {
    cout << (rightAlign ? right : left) << setw(width) << d;
}




// 可自行实现其他需要的工具函数。
