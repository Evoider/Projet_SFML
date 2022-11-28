#include "Entity.h"
#include <string>

class Player :
    public Entity
{
private:
    sf::Clock clock;

public:
    Player(int height, int width);
    void animationMove(std::string direction);
};
