#pragma once
#include "windowsTrick.hpp"
#include <vector>

class InputWizard{
    private:
        std::vector<Input *> inputs;
        

    public:
        int insertInput();
        int exec();
};