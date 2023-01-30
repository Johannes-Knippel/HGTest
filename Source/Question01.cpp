/*
    C++ Question 01
    ---------------

    Unify the definitions of the two functions into one.
*/

#include <iostream>

#define COUNT_OF(x) (sizeof(x) / sizeof(x[0]))

//float GetAverage(int* a, int count)
//{
//    float sum = 0;
//    for (int i = 0; i < count; ++i)
//    {
//        sum += a[i];
//    }
//
//    return sum / count;
//}
//
//float GetAverage(float* a, int count)
//{
//    float sum = 0.0f;
//    for (int i = 0; i < count; ++i)
//    {
//        sum += a[i];
//    }
//
//    return sum / count;
//}

template<typename k> float GetAverage(k* num, int count)
{
    float sum = 0.0f;
        for (int i = 0; i < count; ++i)
        {
            sum += num[i]; //conversion from int to float may result in some loss of precision
        }
    
        return sum / count;
};

int main(int argc, char* argv[])
{
    int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    float b[5] = { 0.0f, 0.1f, 0.2f, 0.3f, 0.4f };

    std::cout << GetAverage(a, COUNT_OF(a)) << " " << GetAverage(b, COUNT_OF(b)) << std::endl;

    return 0;
}