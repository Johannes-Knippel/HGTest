/*
	C++ Question 08
	---------------

	The method CActor::PerceptSurroundings() runs slower than it should.  Fix the performance problems.
	Hint: There are 5 problems in total, of which 2 are logical, 2 are language specific and 1 is mathematical.
*/

// orig time 3148 ms

#include <iostream>
#include <vector>
#include <random>

#pragma region Profiling Stats (Can be ignored)

#include <chrono>

class CSimpleStatScope
{
public:
	CSimpleStatScope()
	{
		startTimePoint = std::chrono::high_resolution_clock::now();
	}

	~CSimpleStatScope()
	{
		auto endTimePoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTimePoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

		auto duration = end - start;

		std::cout << "Operation took " << duration * 0.001f << "ms" << std::endl;
	}

	std::chrono::time_point<std::chrono::high_resolution_clock> startTimePoint;
};

#define SCOPE_CYCLE_COUNTER \
	CSimpleStatScope statScope;

#pragma endregion

template <typename T> T sqr(T a)
{
	return a * a;
}

class CActor
{
public:
	CActor(float in_x, float in_y, float in_z, bool bIsActorPerceptible, bool bCanActorPercept)
		: x(in_x), y(in_y), z(in_z), bIsPerceptible(bIsActorPerceptible), bCanPercept(bCanActorPercept) { m_perceptedObjects.reserve(50);} // we can reserve the size of the vector ahead before filling it. 

	static const float PERCEPTION_RANGE;

	float DistanceTo(CActor& other);
	void PerceptSurroundings(std::vector<CActor*> allObjects);

	inline std::vector<CActor*>& GetPerceptedObjects() { return m_perceptedObjects; }

private:
	float x, y, z;
	bool bIsPerceptible;
	bool bCanPercept;

	std::vector<CActor*> m_perceptedObjects;
};

/*static*/ const float CActor::PERCEPTION_RANGE = 20.0f;

float CActor::DistanceTo(CActor& other)
{
	return sqrt(sqr(x - other.x) + sqr(y - other.y) + sqr(z - other.z));
}

void CActor::PerceptSurroundings(std::vector<CActor*> allObjects)
{
	m_perceptedObjects.clear();

	for (int i = 0; i < allObjects.size(); ++i)
	{
		CActor objectToCheck = *allObjects[i];
		if (bCanPercept)
		{
			float distance = DistanceTo(objectToCheck);

			if (distance < PERCEPTION_RANGE && objectToCheck.bIsPerceptible)
			{
				m_perceptedObjects.emplace_back(allObjects[i]); //instead of using push_back we can use emplace_back. There is a small performance boost behind this plus, if we wish, we could pass in differing types that are held by the vector.
			}
		}
	}
}

int main(int argc, char* argv[])
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> randBool(0, 1);
	std::uniform_real_distribution<float> randCoord(-20.0f, 20.0f);

	std::vector<CActor*> objects;
	objects.reserve(50); // we can reserve the size of the vector ahead before filling it. 
	for (int i = 0; i < 50; ++i)
	{
		objects.push_back(new CActor(randCoord(rng), randCoord(rng), randCoord(rng), randBool(rng) != 0, randBool(rng) != 0));
	}

	CActor player(10.f, 10.f, 10.f, true, true);

	{
		SCOPE_CYCLE_COUNTER

		//for (int i = 0; i < 10000; ++i) // why use 10thsd repetitions when there is only 1 player that needs to check on its surroundings.
		//{
			player.PerceptSurroundings(objects);
		//}
	}

	std::cout << "Number of objects the player can see: " << player.GetPerceptedObjects().size() << std::endl;

	for (int i = 0; i < 50; ++i)
	{
		delete objects[i];
	}

	//objects.clear(); 
	objects.shrink_to_fit(); // instead of clear() we can use _shrink_to_fit() to actually release memory.

	return 0;
}