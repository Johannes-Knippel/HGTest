/*
    C++ Question 09
    ---------------

    Write a function IsWithinMaxAngle that checks if the angle between two arbitrary vectors is less than MAX_DEGREES.
*/

#include <iostream>
#include <complex>
#include <cmath>

#define MAX_DEGREES 45.0f
#define RAD_TO_DEG 57.295779513f

struct SVector3
{
    float x, y, z;
};

bool IsWithinMaxAngle(const SVector3& v1, const SVector3& v2)
{
	//use dot product of vectors to calculate the angle between them
    const float dotProd = v1.x * v2.x + v1.y * v2.y + v1.z * v1.z;
    const float angle = std::acos(dotProd);

    if (!isnan(angle) && angle * RAD_TO_DEG < MAX_DEGREES) return true;
	
    return false;
}

int main(int argc, char* argv[])
{
    const SVector3 a = { 1.0f, 0.0f, 0.0f };
    const SVector3 b = { 0.0f, 0.0f, 1.0f };
    const SVector3 c = { 1.0f, 0.2f, 0.1f };

    std::cout << std::boolalpha;
    std::cout << IsWithinMaxAngle(a, b) << std::endl;
    std::cout << IsWithinMaxAngle(a, c) << std::endl;
    std::cout << IsWithinMaxAngle(b, c) << std::endl;

    return 0;
}