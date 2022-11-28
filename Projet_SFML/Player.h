#include "Entity.h"
#include <string>

class Player :
    public Entity
{
private:
    sf::Clock clock;

public:
    Player();
    void animationMove(std::string direction);
};
