/*
	C++ Question 05
	---------------

	Explain the output of the program using comments.
*/


/*
 * The Output says:
 * Calling Object::Init()
 * Calling Object::Update()
 * Calling Object::Init()
 * Calling Actor::Update()
 *
 * When calling the Init() function on a CActor the program automatically calls the Init() function of the parent class CObject
 * because the function void CActor::Init() hides the non-virtual function void CObject::Init() from class CObject.
 */


#include <iostream>

class CObject
{
public:
	void Init() { std::cout << "Calling Object::Init() " << std::endl; }
	virtual void Update() { std::cout << "Calling Object::Update() " << std::endl; }
};

class CActor : public CObject
{
public:
	void Init() { std::cout << "Calling Actor::Init() " << std::endl; }
	virtual void Update() { std::cout << "Calling Actor::Update() " << std::endl; }
};

void InitAndUpdate(CObject* obj)
{
	if (obj)
	{
		obj->Init();
		obj->Update();
	}
}

int main(int argc, char* argv[])
{
	CObject object;
	CActor actor;

	InitAndUpdate(&object);
	InitAndUpdate(&actor);

	return 0;
}