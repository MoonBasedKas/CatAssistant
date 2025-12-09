#include "fileRead.hpp"

/**
 * @brief Construct a new File Read:: File Read object
 *
 * @param fileLoc
 */
FileRead::FileRead(std::string fileLoc)
{
    std::regex rg(",");
    std::string text;
    std::ifstream file(fileLoc);
    std::getline(file, text); // skips the first line due to being a csv.
    while (std::getline(file, text))
    {
        std::vector<std::string> parts(std::sregex_token_iterator(text.begin(), text.end(), rg, -1), std::sregex_token_iterator());
        Inputs.push_back(*generateKeystroke(parts.at(0), parts.at(1), parts.at(2)));
    }

    generateInputs();
}

/**
 * @brief Generates the keystroke struct for a read in input.
 *
 * @param inp
 * @param c
 * @param shift
 * @return KEYSTROKE*
 */
KEYSTROKE *FileRead::generateKeystroke(std::string inp, std::string c, std::string shift)
{
    KEYSTROKE *temp = (KEYSTROKE *)malloc(sizeof(KEYSTROKE));
    memset(temp, 0x0, sizeof(KEYSTROKE));

    temp->key = inp.at(0);
    temp->shift = (c == "true");
    temp->text = (c == "true");

    return temp;
}

/**
 * @brief Finishes filling out the KEYSTROKE struct by converting the keystroke into INPUTs.
 *
 */
void FileRead::generateInputs()
{
    INPUT *temp = NULL;
    KEYSTROKE *pt = NULL;
    int slide = 0;
    for (int i = 0; i < Inputs.size(); i++)
    {
        temp = (INPUT *)malloc(sizeof(INPUT));
        memset(temp, 0x0, sizeof(INPUT));
        temp->type = INPUT_KEYBOARD;
        temp->ki.wVk = VkKeyScan(Inputs.at(i).key);
        Inputs.at(i).ip.push_back(*temp);

        temp = (INPUT *)malloc(sizeof(INPUT));
        memset(temp, 0x0, sizeof(INPUT));
        temp->type = INPUT_KEYBOARD;
        temp->ki.wVk = VkKeyScan(Inputs.at(i).key);
        temp->ki.dwFlags = KEYEVENTF_KEYUP;
        Inputs.at(i).ip.push_back(*temp);

        Inputs.at(i).size = 2;
        // slide = 1;
        // pt = &Inputs.at(i);
        // // pt->size = (pt->shift) ? 2 : 4;
        // pt->size = 2;
        // pt->inps = (INPUT *)malloc(sizeof(INPUT) * pt->size);
        // memset(pt->inps, 0x0, sizeof(INPUT) * pt->size);

        // pt->inps[0].type = INPUT_KEYBOARD;
        // // pt->inps[0].ki.wVk = (pt->text) ? VkKeyScan(pt->key) : pt->key;
        // pt->inps[0].ki.wVk = VkKeyScan(pt->key);
        // std::cout << pt->key << std::endl;

        // if (pt->shift)
        // {
        //     pt->inps[1].type = INPUT_KEYBOARD;
        //     pt->inps[1].ki.wVk = VK_SHIFT;
        //     memcpy(&pt->inps[1], &pt->inps[3], sizeof(INPUT));
        //     pt->inps[3].ki.dwFlags = KEYEVENTF_KEYUP;
        //     slide = 2;
        // }
        // memcpy(&pt->inps[0], &pt->inps[slide], sizeof(INPUT));
        // pt->inps[slide].ki.dwFlags = KEYEVENTF_KEYUP;
        // Inputs.at(i) = *pt;
    }
}