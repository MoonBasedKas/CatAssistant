#include "inputWizard.hpp"
#include "fileRead.hpp"
#include <iostream>

int main()
{
    FileRead fr("sample.csv");

    InputWizard iw(fr.Inputs, 100, 1000);
    iw.exec();
    return 0;
}