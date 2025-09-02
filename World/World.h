//
// Created by florent on 30/08/2025.
//

#ifndef FISHSIMULATION_WORLD_H
#define FISHSIMULATION_WORLD_H
#include <vector>
#include "../creature/position/Position.h"
#include "../creature/fish/Fish.h"
#include "../vector/Vector2d.h"

#define COHESION_COEFFICIENT 0.005 // between 0.005 - 0.15
#define SEPARATION_COEFFICIENT 1.5 // between 1.5 - 2.5

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
    void separation(Fish &fish);
    Vector2d separationForce(Fish &fish);
    void mean(std::vector<Fish> fishes, double &meanX, double &meanY);
};


#endif //FISHSIMULATION_WORLD_H