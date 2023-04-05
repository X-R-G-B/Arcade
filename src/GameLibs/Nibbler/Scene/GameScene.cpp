/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** GameScene
*/

#include <memory>
#include <random>
#include <functional>
#include "GameScene.hpp"
#include "Sprite.hpp"
#include "EntityManager.hpp"
#include "MagicValue.hpp"
#include "NibblerCompType.hpp"
#include "NibblerMapComponent.hpp"
#include "NibblerWallComponent.hpp"

Nibbler::Scene::GameScene::GameScene()
    : Arcade::Game::AScene(std::make_unique<Arcade::ECS::EntityManager>())
{
}

void Nibbler::Scene::GameScene::addNibblerHeadSprite(Arcade::ECS::IEntity &head)
{
}

bool Nibbler::Scene::GameScene::checkWallCollision(Arcade::ECS::IEntity &nibblerWalls, const Arcade::Vector3f &pos, std::vector<std::string> &idToIgnore)
{
    const std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &walls = nibblerWalls.getComponents(Arcade::ECS::CompType::SPRITE);

    if (pos.x < NIBBLER_PADDING_WINDOW_X || pos.x >= MAP_RIGHT || pos.y < NIBBLER_PADDING_WINDOW_Y || pos.y >= MAP_BOTTOM) {
        return true;
    }
    if (walls.empty()) {
        return false;
    }
    for (auto &tmp : walls) {
        auto wall = std::static_pointer_cast<Nibbler::Component::NibblerWallComponent>(tmp);
        if (std::find(idToIgnore.begin(), idToIgnore.end(), wall->id) != idToIgnore.end()) {
            continue;
        }
        auto &wallPos = wall->pos;
        if (pos.x >= wallPos.x && pos.x < wallPos.x + PARCELL_SIZE
                && pos.y >= wallPos.y && pos.y < wallPos.y + PARCELL_SIZE) {
            return true;
        }
        // check border right
        if (pos.x + PARCELL_SIZE >= wallPos.x && pos.x + PARCELL_SIZE < wallPos.x + PARCELL_SIZE
                && pos.y >= wallPos.y && pos.y < wallPos.y + PARCELL_SIZE) {
            return true;
        }
        // check broder down
        if (pos.x >= wallPos.x && pos.x < wallPos.x + PARCELL_SIZE
                && pos.y + PARCELL_SIZE >= wallPos.y && pos.y + PARCELL_SIZE < wallPos.y + PARCELL_SIZE) {
            return true;
        }
        // check border left
        if (pos.x - PARCELL_SIZE >= wallPos.x && pos.x - PARCELL_SIZE < wallPos.x + PARCELL_SIZE
                && pos.y >= wallPos.y && pos.y < wallPos.y + PARCELL_SIZE) {
            return true;
        }
        // check border up
        if (pos.x >= wallPos.x && pos.x < wallPos.x + PARCELL_SIZE
                && pos.y - PARCELL_SIZE >= wallPos.y && pos.y - PARCELL_SIZE < wallPos.y + PARCELL_SIZE) {
            return true;
        }
    }
    return false;
}

int Nibbler::Scene::GameScene::generateRandomInt(int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, max);
    return distr(gen);
}

void Nibbler::Scene::GameScene::addNibblerWallSquare(Arcade::ECS::IEntity &nibblerWalls,
    const Arcade::Vector3f &src_pos, const int id)
{
    Arcade::Vector3f pos = src_pos;
    std::vector<std::string> toIgnore;
    std::string wallId;
    int borderToDelete = generateRandomInt(3);

    for (int i = 0; i < 4; i++) {
        if (!checkWallCollision(nibblerWalls, pos, toIgnore) && i != borderToDelete) {
            wallId = std::string(NIBBLER_WALL_ID) + "_" + std::to_string(id) + "_nbr_" + std::to_string(i);
            nibblerWalls.addComponent(std::make_shared<Nibbler::Component::NibblerWallComponent>(wallId, pos));
            toIgnore.push_back(wallId);
        }
        switch (i) {
            case 0:
                pos.x += PARCELL_SIZE;
                break;
            case 1:
                pos.y += PARCELL_SIZE;
                break;
            case 2:
                pos.x -= PARCELL_SIZE;
                break;
            default:
                break;
        }
    }
}

bool Nibbler::Scene::GameScene::checkParcelCollision(Arcade::ECS::IEntity &nibblerWalls,
    const Arcade::Vector3f &pos)
{
    const std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &walls = nibblerWalls.getComponents(Arcade::ECS::CompType::SPRITE);

    if (pos.x < NIBBLER_PADDING_WINDOW_X || pos.x >= MAP_RIGHT || pos.y < NIBBLER_PADDING_WINDOW_Y || pos.y >= MAP_BOTTOM) {
        return true;
    }
    for (auto &tmp : walls) {
        auto wall = std::static_pointer_cast<Nibbler::Component::NibblerWallComponent>(tmp);
        auto wallPos = wall->pos;
        if (pos.x >= wallPos.x && pos.x < wallPos.x + PARCELL_SIZE
                && pos.y >= wallPos.y && pos.y < wallPos.y + PARCELL_SIZE) {
            return true;
        }
    }
    return false;
}

void Nibbler::Scene::GameScene::addNibblerWall(Arcade::ECS::IEntity &nibblerWalls, const Arcade::Vector3f &pos, int nbrOfWalls)
{
    std::vector<std::function<void(Nibbler::Scene::GameScene&, Arcade::ECS::IEntity &, const Arcade::Vector3f &, int)>> addNibblerWallFuncs = {
        &Nibbler::Scene::GameScene::addNibblerWallSquare
    };
    auto funcNbr = generateRandomInt(addNibblerWallFuncs.size() - 1);

    addNibblerWallFuncs[funcNbr](*this, nibblerWalls, pos, nbrOfWalls);
    this->addNibblerWallSquare(nibblerWalls, pos, nbrOfWalls);
}

void Nibbler::Scene::GameScene::addNibblerParcel(Arcade::ECS::IEntity &nibblerMap, const Arcade::Vector3f &pos, int id, Arcade::ECS::IEntity &nibblerWalls)
{
    static bool darkColor = true;

    darkColor = !darkColor;
    if (pos.x < NIBBLER_PADDING_WINDOW_X || pos.x > MAP_RIGHT || pos.y < NIBBLER_PADDING_WINDOW_Y || pos.y > MAP_BOTTOM) {
        return;
    }
    if (checkParcelCollision(nibblerWalls, pos)) {
        return;
    }
    nibblerMap.addComponent(std::make_shared<Nibbler::Component::NibblerMapComponent>(
            std::string(NIBBLER_MAP_ID) + "_" + std::to_string(id), pos, darkColor));
}

void Nibbler::Scene::GameScene::addNibblerMap()
{
    Arcade::ECS::IEntityManager &EntityManager = getEntityManager();
    Arcade::ECS::IEntity &nibblerMap = EntityManager.createEntity(NIBBLER_MAP_ID);
    Arcade::ECS::IEntity &nibblerWalls = EntityManager.createEntity(NIBBLER_WALL_ID);
    std::vector<int> wallsPos;

    // generate randoms positions of walls
    for (int i = 0; i < NBR_OF_WALLS; i++) {
        wallsPos.push_back(generateRandomInt(MAP_PARCELLS_X * MAP_PARCELLS_Y));
    }
    // generate walls
    for (int y = 0, nibblerMapParcelNbr = 0; y < MAP_PARCELLS_Y; y++, nibblerMapParcelNbr++) {
        for (int x = 0; x < MAP_PARCELLS_X; x++, nibblerMapParcelNbr++) {
            if (std::find(wallsPos.begin(), wallsPos.end(), nibblerMapParcelNbr) != wallsPos.end()) {
                addNibblerWall(nibblerWalls,
                    Arcade::Vector3f(NIBBLER_PADDING_WINDOW_X + x * PARCELL_SIZE,
                    NIBBLER_PADDING_WINDOW_Y + y * PARCELL_SIZE, 0),
                    nibblerMapParcelNbr);
            }
        }
    }
    // generate map parcels
    for (int y = 0, nibblerMapParcelNbr = 0; y < MAP_PARCELLS_Y; y++, nibblerMapParcelNbr++) {
        for (int x = 0; x < MAP_PARCELLS_X; x++, nibblerMapParcelNbr++) {
            addNibblerParcel(nibblerMap,
                Arcade::Vector3f(NIBBLER_PADDING_WINDOW_X + x * PARCELL_SIZE,
                NIBBLER_PADDING_WINDOW_Y + y * PARCELL_SIZE, 0),
                nibblerMapParcelNbr, nibblerWalls);
        }
    }
}

void Nibbler::Scene::GameScene::createNibbler()
{

}

void Nibbler::Scene::GameScene::createApple()
{

}

bool Nibbler::Scene::GameScene::init()
{
    createApple();
    createNibbler();
    addNibblerMap();
    return (true);
}

void Nibbler::Scene::GameScene::close()
{
    this->getEntityManager().removeAllEntities();
}
