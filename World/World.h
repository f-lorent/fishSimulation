//
// Created by florent on 30/08/2025.
//

#ifndef FISHSIMULATION_WORLD_H
#define FISHSIMULATION_WORLD_H
#include <vector>
#include "../creature/position/Position.h"
#include "../creature/fish/Fish.h"


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
};


#endif //FISHSIMULATION_WORLD_H