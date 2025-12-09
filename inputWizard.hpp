#pragma once
#include "windowsTrick.hpp"
#include "fileRead.hpp"
#include <Windows.h>
#include <vector>
#include <cstdlib>

class InputWizard
{
private:
    std::vector<KEYSTROKE> inputs;
    int rate;   // how often in ms a event will trigger.
    int chance; // x/1000 chance a keystroke event will trigger.

public:
    int insertInput();
    int exec();
    InputWizard(std::vector<KEYSTROKE> k, int per, int r);
};