//
// Created by florent on 02/09/2025.
//

#ifndef FISHSIMULATION_CONFIG_H
#define FISHSIMULATION_CONFIG_H

// Boids coefficient
#define COHESION_COEFFICIENT 0.008 // between 0.005 - 0.15
#define SEPARATION_COEFFICIENT 0.05// between 1.5 - 2.5
#define ALIGNMENT_COEFFICIENT 0.1 // between 0.1 - 0.2

//Fish
#define FISH_RADIUS 1
#define PERCEPTION_RADIUS 80 // between 80 - 120 px
#define SEPARATION_RADIUS 20 // between 20 - 30 px
#define MAX_VELOCITY 10.0 // between 120 - 180

//Interface
#define HEIGHT 1080
#define WIDTH 1920
#define RED 10
#define GREEN 43
#define BLUE 88

//World
#define FISH_COUNT 200
#define TIME_COEFFICIENT 50

#define RESTITATION_COEFFICIENT 1

#endif //FISHSIMULATION_CONFIG_H