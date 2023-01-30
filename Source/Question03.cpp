/*
    C++ Question 03
    ---------------

    You are working on a game. For some reason, enemies in the game are sometimes failing to die although 
    sometimes it works correctly.  You can be sure that the method CEnemy::TakeDamage is properly called 
    with the correct damage.  Find and fix the bug(s).
*/


/*
 * We should not use an unsigned int for subtractions that can end in negative results. Negative results cannot be represented as an unsigned number.
 * Let's use a float instead for the variable health and as an input parameter for TakeDamage(float damage).
 * We also need to initialize the health variable, let's set it to be 100.f.
 * To avoid negative health we could clamp the variable between 0 and max_health. 
 * Let's say his maximum health is 100.f
 * To use std::clamp we have to set the compiler switch to /std:c++17 and include algorithm lib.
 */

 // important to include algorithm library 
#include <algorithm>

class CEnemy
{
public:
    CEnemy() :health(100.f), max_health(100.f) {}

    void TakeDamage(float damage)
    {
        health = std::clamp(health - damage, 0.f, max_health);
        if (health == 0.f)
        {
            Destroy();
        }
    }

protected:
    void Destroy()
    {
        bIsAlive = false;
    }

private:
    bool bIsAlive = true;
    float health;
    float max_health;
};

int main(int argc, char* argv[])
{
    // Game code goes here...

    return 0;
}
