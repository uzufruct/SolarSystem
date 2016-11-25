#include "SolarSystem.h"

SolarSystem::SolarSystem(sf::Vector2u space_size) {
    // create Sun
    spaceObjects.push_back(new Sun(90.f, sf::Vector2f(space_size.x / 2, space_size.y / 2)));
    SpaceObject* sun = spaceObjects.at(0);
    spaceObjects.push_back(new Mercury(2.5f, sun, 100.f));
    spaceObjects.push_back(new Venus(4.5f, sun, 110.f));
    spaceObjects.push_back(new Earth(5.f, sun, 130.f));
    SpaceObject* earth = spaceObjects.at(3);
    spaceObjects.push_back(new Moon(1.f, earth, 6.5f));
    spaceObjects.push_back(new Mars(3.f, sun, 150.f));
    spaceObjects.push_back(new Jupiter(13.f, sun, 175.f));
    spaceObjects.push_back(new Saturn(11.f, sun, 220.f));
    spaceObjects.push_back(new Uranus(9.f, sun, 250.f));
    spaceObjects.push_back(new Neptune(8.f, sun, 270.f));

    // add background stars in system
    for (int i = 0; i < 60; ++i) {
        spaceObjects.push_back(new Star(0.5f, sf::Vector2f((std::rand() % space_size.x), (std::rand() % space_size.y))));
    }
}

SolarSystem::~SolarSystem() {
    for (auto it = spaceObjects.begin(); it < spaceObjects.end(); ++it)
        delete (*it);
}

std::vector<SpaceObject*> *SolarSystem::getSpaceObjects() {
    return &spaceObjects;
}

void SolarSystem::update(sf::Time elapsed) {
    for (auto it = spaceObjects.begin(); it < spaceObjects.end(); ++it)
        (*it)->update(elapsed);
}