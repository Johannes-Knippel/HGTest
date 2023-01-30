/*
    C++ Question 10
    ---------------

    Given 2 points, a and b, in 3D space, write a function to calculate the rotation parameters 
    (in an axis-angle representation) that will rotate point a in the direction of point b about the origin o.
*/

#include <iostream>
#include <complex>

#define RAD_TO_DEG 57.295779513f

struct SVector3
{
    friend std::ostream& operator<<(std::ostream& output, const SVector3& v)
    {
        output << v.x << ", " << v.y << ", " << v.z;
        return output;
    }

    float x, y, z;
    SVector3 operator-(SVector3& v)
    {
        SVector3 vector3;
        vector3.x = this->x - v.x;
        vector3.y = this->y - v.y;
        vector3.z = this->z - v.z;

        return vector3;
    }
    SVector3 operator*(SVector3& v)
    {
        SVector3 vector3;
        vector3.x = this->x * v.x;
        vector3.y = this->y * v.y;
        vector3.z = this->z * v.z;

        return vector3;
    }
};

class CMath
{
public: // haven't had much time to think about that unfortunately, had a lot of parallel meetings today. 
    static void CalculateRotation(SVector3& o, SVector3& a, SVector3& b, SVector3& axis, float& angle)
    {
        // angle between oa and ob
        SVector3 oa = o - a;
        SVector3 ob = o - b;
        double v3 = static_cast<double>(oa.x) * static_cast<double>(oa.x) + static_cast<double>(oa.y) * static_cast<double>(oa.y) + static_cast<double>(oa.z) * static_cast<double>(oa.z); //casting to 8 byte type to avoid overflow
        double v4 = static_cast<double>(ob.x) * static_cast<double>(ob.x) + static_cast<double>(ob.y) * static_cast<double>(ob.y) + static_cast<double>(ob.z) * static_cast<double>(ob.z);
        SVector3 d = oa - ob;
        angle = std::acos(std::min(1.0, std::max(-1.0,
            (v3 + v4 - (static_cast<double>(d.x) * static_cast<double>(d.x) + static_cast<double>(d.y) * static_cast<double>(d.y) + static_cast<double>(d.z) * static_cast<double>(d.z))) /
            (2 * std::sqrt(v3) * std::sqrt(v4))))) * RAD_TO_DEG;

        std::cout << "Angle: " << angle << std::endl;

    	// find axis
        axis = oa * ob;
    }
};

int main(int argc, char* argv[])
{
    SVector3 o = { 2.0f, 2.0f, 2.0f };
    SVector3 a = { 1.0f, 1.0f, 1.0f };
    SVector3 b = { 0.5f, 0.0f, 1.5f };

    SVector3 axis = {};
    float angle = 0.0f;
    CMath::CalculateRotation(o, a, b, axis, angle);
    std::cout << "Axis: " << axis << " angle: " << angle << std::endl;

    return 0;
}