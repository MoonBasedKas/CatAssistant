#include "inputWizard.hpp"

/**
 * @brief The main function to start the program once its been loaded.
 *
 * @return int
 */
int InputWizard::exec()
{
    KEYSTROKE *temp = NULL;
    while (1)
    {
        Sleep(rate);
        if (chance < (rand() % 1000))
        {
            temp = &inputs.at(rand() % inputs.size());
            SendInput(temp->size, temp->inps, sizeof(INPUT));
        }
    }

    return 0;
}

/**
 * @brief Inserts a new input into the input list.
 *
 * @return int
 */
int InputWizard::insertInput()
{

    return 0;
}

InputWizard::InputWizard(std::vector<KEYSTROKE> k, int per, int r)
{
    srand(time(0x0));
    inputs = k;
    chance = per;
    rate = r;
}