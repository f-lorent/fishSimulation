//
// Created by florent on 30/08/2025.
//

#ifndef FISHSIMULATION_WORLD_H
#define FISHSIMULATION_WORLD_H
#include <vector>
#include "../creature/position/Position.h"
#include "../creature/fish/Fish.h"
#include "../vector/Vector2d.h"

#define COHESION_COEFFICIENT 0.00001

class World {
    private:
    int fishCount;
    std::vector<Fish> fishes;
    std::vector<Position> fishesPositions;

    public:
    World(int fishCount) {
        this->fishCount = fishCount;
    };
    void initWorld();
    std::vector<Fish> getFishs();
    void worldUpdate(double deltaTime);

    private:
    void createFishs();
    void generatePositionOfFishs();
    bool controlPositionX(Fish &fish);
    bool controlPositionY(Fish &fish);
    void adaptPosition(Fish &fish);
    std::vector<Fish> fishPerception(Fish &fish);
    void cohesion(Fish &fish);
    void mean(std::vector<Fish> fishes, double &meanX, double &meanY);
    void maxVelocity(Fish &fish);
};


#endif //FISHSIMULATION_WORLD_H