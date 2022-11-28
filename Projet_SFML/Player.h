#include "Entity.h"
#include <string>

class Player :
    public Entity
{
private:


public:
    Player(int height, int width);
    void animationMove(std::string direction);

    



};
