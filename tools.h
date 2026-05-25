// 124033910070 GTY SJTU-CS
// Created on 2025.4.22, Jiangchuan Rd., Minhang

#pragma once  // 头文件开头都要加这个。


/**
 * 清空屏幕。
 */
void clearScreen();


/**
 * 相当于 cout << setw(width) << str; 但是可以避免中文字符显示宽度异常的问题。
 * 
 * @param str   要输出的字符串。
 * @param width 希望显示的宽度。相当于 setw(width)。
 * @param rightAlign 是否要右对齐。设为 false 表示左对齐。设为 true 表示右对齐。
 */
void setwPrint(const char* str, int width, bool rightAlign);

void setwPrint(char c, int width, bool rightAlign);
void setwPrint(double d, int width, bool rightAlign);

// 可自行定义其他需要的工具函数。
