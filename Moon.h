#ifndef SOLARSYSTEM_MOON_H
#define SOLARSYSTEM_MOON_H

#include "SpaceObject.h"

class Moon : public SpaceObject {
private:
    float p_phi;

public:
    Moon(float radius, SpaceObject* earth, float radius_of_orbit);
    ~Moon();

    void update(sf::Time elapsed);

};

#endif //SOLARSYSTEM_MOON_H
