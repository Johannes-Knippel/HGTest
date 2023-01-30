/*
    C++ Question 09
    ---------------

    Write a function IsWithinMaxAngle that checks if the angle between two arbitrary vectors is less than MAX_DEGREES.
*/

#include <complex.h>
#include <fstream>
#include <iostream>



#define MAX_DEGREES 45.0f
#define RAD_TO_DEG 57.295779513f

struct SVector3
{
    float x, y, z;

    SVector3 operator-(SVector3& v)
    {
        SVector3 vector3;
        vector3.x = this->x - v.x;
        vector3.y = this->y - v.y;
        vector3.z = this->z - v.z;

        return vector3;
    }
};

bool IsWithinMaxAngle(SVector3& v1, SVector3& v2)
{
    double v3 = static_cast<double>(v1.x) * static_cast<double>(v1.x) + static_cast<double>(v1.y) * static_cast<double>(v1.y) + static_cast<double>(v1.z) * static_cast<double>(v1.z); //casting to 8 byte type to avoid overflow
    double v4 = static_cast<double>(v2.x) * static_cast<double>(v2.x) + static_cast<double>(v2.y) * static_cast<double>(v2.y) + static_cast<double>(v2.z) * static_cast<double>(v2.z);
	SVector3 d = v1 - v2;
    float angle = std::acos(std::min(1.0, std::max(-1.0,
        (v3 + v4 - (static_cast<double>(d.x) * static_cast<double>(d.x) + static_cast<double>(d.y) * static_cast<double>(d.y) + static_cast<double>(d.z) * static_cast<double>(d.z))) /
        (2 * std::sqrt(v3) * std::sqrt(v4)))));

    if (angle && angle * RAD_TO_DEG < MAX_DEGREES) return true;
	
    return false;
}

int main(int argc, char* argv[])
{
    SVector3 a = { 1.0f, 0.0f, 0.0f };
    SVector3 b = { 0.0f, 0.0f, 1.0f };
    SVector3 c = { 1.0f, 0.2f, 0.1f };

    std::cout << std::boolalpha;
    std::cout << IsWithinMaxAngle(a, b) << std::endl;
    std::cout << IsWithinMaxAngle(a, c) << std::endl;
    std::cout << IsWithinMaxAngle(b, c) << std::endl;

    return 0;
}