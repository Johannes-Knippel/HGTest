/*
    C++ Question 04
    ---------------

    You are working on a game. For some reason, the player isn't able to move.
    Find and fix the bug(s).
*/



/*
 * We tried to call the init function from the parent class which then tries to call the overriden function from the child class resulting in referencing itself.
 * Instead we want to call the Init() function from our CPlayer that overrides the parents CActors Init() function.
 */

#include <iostream>
#include <vector>

class CActor
{
public:
    //virtual void InitActor(CActor actor)
    //{
    //    actor.Init();
    //}
    virtual void Init() {}
    virtual void Update() {}
};

class CPlayer : public CActor
{
public:
    CPlayer() : movementSpeed(0.0f) {}

    virtual void Init() override
    {
        movementSpeed = 2.4f;
    }

    virtual void Update() override
    {
        std::cout << "Player is moving with " << movementSpeed << " metres per second" << std::endl;
    }

private:
    float movementSpeed;
};

void InitAllActors(std::vector<CActor*> actors)
{
    for (CActor* a : actors)
    {
        a->Init();
    }
}

int main(int argc, char* argv[])
{
    std::vector<CActor*> actors;
    actors.push_back(new CPlayer());

    InitAllActors(actors);
    // Entering the game loop...
    while (true)
    {
        for (CActor* a : actors)
        {
            a->Update();
        }
    }

    return 0;
}