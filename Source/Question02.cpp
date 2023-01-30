/*
    C++ Question 02
    ---------------

    Write comments explaining the error(s) in the following code.
    Correct the code so we obtain the expected result.
*/


/*
 * We are trying to print the address of the parameter "value".
 * That is because the function definition takes a pointer of the defined parameter.
 * Instead we can consume a const parameter and define it accordingly. We use a const parameter because we are not assigning the value dynamically.
*/


#include <iostream>

void PrintValuePlus2(const int p)
{
    std::cout << p + 2 << std::endl;
}

int main(int argc, char* argv[])
{
    const int value = 40;
    PrintValuePlus2(value); // Expected result: 42.

    return 0;
}