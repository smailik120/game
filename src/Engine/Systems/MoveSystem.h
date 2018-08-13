#ifndef _MOVESYSTEM_CPP
#define _MOVESYSTEM_CPP
#include <map>
#include <list>
#include <cstring>
#include <utility>
#include <string>
#include <cmath>
#include "../Entity/Engine.h"
#include "../Systems/System.h"
#include "../Entity/Entity.h"
#include "../Collisions/Collision.h"
#include "../Collisions/CollisionPlayerHelmet.h"
#include "../Collisions/CollisionPlayerChest.h"
#include "../Collisions/CollisionTowerTower.h"
#include "../Collisions/CollisionPlayerArmor.h"
#include "../Collisions/CollisionPlayerPants.h"
#include "../Collisions/CollisionPlayerLevel.h"
#include "../Collisions/CollisionPlayerBrick.h"
#include "../Collisions/CollisionPlayerMoney.h"
#include "../Collisions/CollisionPlayerTower.h"
#include "../Collisions/CollisionTowerPlayer.h"
#include "../Collisions/CollisionTowerBrick.h"
#include "../Collisions/CollisionPlayerSword.h"
#include "../Components/Position.h"
#include "../Components/Velocity.h"
using namespace std;
class MoveSystem : public System {
 private:
    map<pair<string, string>, Collision*>* collisions;
    Position* position;
    Velocity* velocity;
 public:
    MoveSystem();
    void update();
    bool validate(Entity* entity);
    void create();
    void move(Entity* player, Entity* another);
    void collideAfterMove();
    bool distance(int distanceX, int distanceY, Entity* entity);
    void collide();
};
#endif