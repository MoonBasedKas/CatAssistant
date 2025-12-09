#include "inputWizard.hpp"

/**
 * @brief The main function to start the program once its been loaded.
 *
 * @return int
 */
int InputWizard::exec()
{
    unsigned long t = time(0x0);
    KEYSTROKE *temp;
    int x = 0;
    while (1)
    {

        Sleep(rate);

        if (chance < (rand() % 1000) || 1 == 1)
        {
            x = rand() % inputs->size();

            temp = &inputs->at(x);
            std::cout << x << std::endl;
            std::cout << temp->key << std::endl;
            std::cout << temp->inps << std::endl;
            std::cout << SendInput(temp->size, temp->inps, sizeof(INPUT)) << std::endl;
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
    inputs = &k;
    chance = per;
    rate = r;
}