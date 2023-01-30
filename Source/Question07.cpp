/*
    C++ Question 07
    ---------------

    Extend the CVector3 class in a way that will make the template math library work for objects of type CVector3.
*/

#include <iostream>

// Awesome template math library :)
class CMath
{
public:
    template<typename T>
    static T Add(T a, T b)
    {
        return a + b;
    }
};

class CVector3
{
public:
    CVector3() : CVector3(0.0f, 0.0f, 0.0f) {}
    CVector3(float inX, float inY, float inZ) : x(inX), y(inY), z(inZ) {}

    float x, y, z;

	//using a very simple linear addition
	CVector3 operator+(CVector3& v)
	{
		CVector3 vector3;
        vector3.x = this->x + v.x;
        vector3.y = this->y + v.y;
        vector3.z = this->z + v.z;
		
		return vector3;
	}
};

int main(int argc, char* argv[])
{
    CVector3 a(2.3f, 0.1f, 9.0f), b(14.8f, 65.1f, 106.6f);

    // Uncomment to test your solution
    CVector3 c = CMath::Add<CVector3>(a, b);
    std::cout << c.x << ", " << c.y << ", " << c.z << std::endl;

    return 0;
}