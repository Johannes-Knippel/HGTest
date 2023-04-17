/*
    C++ Question 06
    ---------------

    Change the definition of class CObject in such a way that child classes NEED TO override 
    the method GetName, so it returns the correct class name.
*/

// Set it to be a pure virtual function. (pure-specifier is a Microsoft extension tho)

#include <iostream>
#include <string>

using String = std::string;

class CObject
{ 
public:
    virtual ~CObject() = default;
    virtual String GetName() const = 0 { return "Object"; }
};

class CActor : public CObject
{
public:
    String GetName() const override { return "Actor"; }
};

int main(int argc, char* argv[])
{
    const CActor actor;
    std::cout << actor.GetName() << std::endl;
    return 0;
}