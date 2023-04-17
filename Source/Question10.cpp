/*
    C++ Question 10
    ---------------

    Given 2 points, a and b, in 3D space, write a function to calculate the rotation parameters 
    (in an axis-angle representation) that will rotate point a in the direction of point b about the origin o.
*/

#include <iostream>
#include <complex>
#include <cmath>

#define RAD_TO_DEG 57.295779513f

struct SVector3
{
    friend std::ostream& operator<<(std::ostream& output, const SVector3& v)
    {
        output << v.x << ", " << v.y << ", " << v.z;
        return output;
    }

    float x, y, z;
};

class CMath
{
public: 
    static void CalculateRotation(const SVector3& o, const SVector3& a, const SVector3& b, SVector3& axis, float& angle)
    {
    	//direction vectors from origin to a and b
        const SVector3 dirA = { a.x - o.x, a.y - o.y, a.z - o.z };
		const SVector3 dirB = { b.x - o.x, b.y - o.y, b.z - o.z };

    	//cross product of direction vecs to get rotation axis
        axis = { dirA.y * dirB.z - dirA.z * dirB.y,
                        dirA.z * dirB.x - dirA.x - dirB.z,
                        dirA.x * dirB.y - dirA.y * dirB.x };

    	//normalize axis vec
        const float axisLength = std::sqrt(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
    	if(axisLength > 0.0f)
    	{
            axis.x /= axisLength;
            axis.y /= axisLength;
            axis.z /= axisLength;
    	}

    	//get angle using dot product of direction vectors
        const float dotProd = dirA.x * dirB.x + dirA.y * dirB.y + dirA.z * dirB.z;
        const float checkAngle = std::acos(dotProd);

    	if (!isnan(checkAngle))
    	{
            angle = checkAngle * RAD_TO_DEG;
    	}
    }
};

int main(int argc, char* argv[])
{
    const SVector3 o = { 0.0f, 0.0f, 1.0f };
    const SVector3 a = { 1.0f, 1.0f, 1.0f };
    const SVector3 b = { 0.5f, 0.0f, 1.5f };

    SVector3 axis = {};
    float angle = 0.0f;
    CMath::CalculateRotation(o, a, b, axis, angle);
    std::cout << "Axis: " << axis << " angle: " << angle << std::endl;

    return 0;
}