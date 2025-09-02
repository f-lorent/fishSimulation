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
#define SEPARATION_COEFFICIENT 1.5// between 1.5 - 2.5
#define ALIGNMENT_COEFFICIENT 0.01 // between 0.1 - 0.2
#define RESTITATION_COEFFICIENT 1

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
    void adaptPosition(Position &position, Velocity &velocity);
    bool adaptVelocity(Fish &fish);
    std::vector<Fish> fishPerception(Fish &fish);
    Vector2d separationForce(Fish &fish);
    void mean(std::vector<Fish> fishes, double &meanX, double &meanY);
    void meanVelocity(std::vector<Fish> fishes, double &meanX, double &meanY);

    Vector2d cohesion(Fish &fish);
    Vector2d separation(Fish &fish);
    Vector2d alignment(Fish &fish);
};


#endif //FISHSIMULATION_WORLD_H