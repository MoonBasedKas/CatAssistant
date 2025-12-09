#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <regex>
#include <iostream>
#include "Windows.h"

typedef struct keyStroketag
{
    int size; // no inputs;
    char key; // char or int
    bool text;
    bool shift;
    std::vector<INPUT> *ip;
    INPUT *inps;
} KEYSTROKE;

class FileRead
{
private:
    KEYSTROKE *generateKeystroke(std::string inp, std::string c, std::string shift);
    void generateInputs();

public:
    FileRead(std::string fileLoc);
    std::vector<KEYSTROKE> Inputs; // kind of lazy.
};