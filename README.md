# An elegant simulation of a school of fish 

A personnal project to learn how to simulate behaviour of a group and the basic of C++.

I use the [Boids model](https://en.wikipedia.org/wiki/Boids) to simulate the behaviour of fishs. It use those three rules:

- separation: steer to avoid crowding local flockmates
- alignment: steer towards the average heading of local flockmates
- cohesion: steer to move towards the average position (center of mass) of local flockmates

I have current issue to find good coefficient to have a more realistic result.
