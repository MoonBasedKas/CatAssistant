/**
 * @file windowsTrick.hpp
 * @author MBK
 * @brief This is a temp file that holds declarations for
 * windows specific structs/functions.
 * @version 0.1
 * @date 2025-12-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
#ifdef __linux__

unsigned int SendInput(unsigned int cInputs, unsigned int pInputs, int cbSize);

typedef struct tagKEYBDINPUT{
    short wVK;
    short wScan;
    int time;
} KEYBDINPUT;

typedef struct tagINPUT{
    int DWORD;
    KEYBDINPUT ki;
} INPUT;

#endif