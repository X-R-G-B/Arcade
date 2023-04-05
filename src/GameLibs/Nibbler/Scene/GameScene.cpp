/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** GameScene
*/

#include <memory>
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

bool Nibbler::Scene::GameScene::checkWallCollision(Arcade::ECS::IEntity &nibblerWalls, const  Arcade::Vector3f &pos)
{
    const std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &walls = nibblerWalls.getComponents(Arcade::ECS::CompType::SPRITE);

    if (walls.size() == 0) {
        return false;
    }
    if (pos.x < 0 || pos.x > MAP_RIGHT || pos.y < 0 || pos.y > MAP_BOTTOM) {
        return true;
    }
    for (auto tmp : walls) {
        auto wall = std::static_pointer_cast<Nibbler::Component::NibblerWallComponent>(tmp);
        auto wallPos = wall->pos;
        if (pos.x >= wallPos.x && pos.x <= wallPos.x + PARCELL_SIZE
                && pos.y >= wallPos.y && pos.y <= wallPos.y + PARCELL_SIZE) {
            return true;
        }
        // check border right
        if (pos.x + PARCELL_SIZE >= wallPos.x && pos.x + PARCELL_SIZE <= wallPos.x + PARCELL_SIZE
                && pos.y >= wallPos.y && pos.y <= wallPos.y + PARCELL_SIZE) {
            return true;
        }
        // check broder down
        if (pos.x >= wallPos.x && pos.x <= wallPos.x + PARCELL_SIZE
                && pos.y + PARCELL_SIZE >= wallPos.y && pos.y + PARCELL_SIZE <= wallPos.y + PARCELL_SIZE) {
            return true;
        }
        // check border left
        if (pos.x - PARCELL_SIZE >= wallPos.x && pos.x - PARCELL_SIZE <= wallPos.x + PARCELL_SIZE
                && pos.y >= wallPos.y && pos.y <= wallPos.y + PARCELL_SIZE) {
            return true;
        }
        // check border up
        if (pos.x >= wallPos.x && pos.x <= wallPos.x + PARCELL_SIZE
                && pos.y - PARCELL_SIZE >= wallPos.y && pos.y - PARCELL_SIZE <= wallPos.y + PARCELL_SIZE) {
            return true;
        }
    }
    return false;
}

bool Nibbler::Scene::GameScene::checkParcelCollision(Arcade::ECS::IEntity &nibblerWalls,
    const Arcade::Vector3f &pos)
{
    const std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &walls = nibblerWalls.getComponents(Arcade::ECS::CompType::SPRITE);

    if (pos.x < 0 || pos.x > PARCELL_SIZE || pos.y < 0 || pos.y > PARCELL_SIZE) {
        return true;
    }
    for (auto tmp : walls) {
        auto wall = std::static_pointer_cast<Nibbler::Component::NibblerWallComponent>(tmp);
        auto wallPos = wall->pos;
        if (pos.x >= wallPos.x && pos.x <= wallPos.x + PARCELL_SIZE
                && pos.y >= wallPos.y && pos.y <= wallPos.y + PARCELL_SIZE) {
            return true;
        }
    }
    return false;
}

void Nibbler::Scene::GameScene::addNibblerWallSquare(Arcade::ECS::IEntity &nibblerWalls,
    const Arcade::Vector3f &src_pos, const int id)
{
    Arcade::Vector3f pos = src_pos;
    int borderTodelete = rand() % 3;

    for (int i = 0; i < 4; i++) {
        if (!checkWallCollision(nibblerWalls, pos) && i != borderTodelete) {
            nibblerWalls.addComponent(std::make_shared<Nibbler::Component::NibblerWallComponent>(NIBBLER_WALL_ID, pos));
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

void Nibbler::Scene::GameScene::addNibblerWall(Arcade::ECS::IEntity &nibblerWalls, const Arcade::Vector3f &pos, int nbrOfWalls)
{
    static std::vector<std::function<void (Arcade::ECS::IEntity &, const Arcade::Vector3f &, int borderToDelete)>> addNibblerWallFunctions = {
        std::bind(&Nibbler::Scene::GameScene::addNibblerWallSquare, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
    };
    auto funcNbr = rand() % (addNibblerWallFunctions.size() - 1);

    addNibblerWallFunctions[funcNbr](nibblerWalls, pos, nbrOfWalls);
}

void Nibbler::Scene::GameScene::addNibblerParcel(Arcade::ECS::IEntity &nibblerMap, const Arcade::Vector3f &pos, int id)
{
    if (checkParcelCollision(nibblerMap, pos)) {
        return;
    }
    if (pos.x < 0 || pos.x > SCREEN_WIDTH || pos.y < 0 || pos.y > SCREEN_HEIGHT) {
        return;
    }
    nibblerMap.addComponent(std::make_shared<Nibbler::Component::NibblerMapComponent>(
            std::string(NIBBLER_MAP_ID), pos));
}

void Nibbler::Scene::GameScene::addNibblerMap()
{
    Arcade::ECS::IEntityManager &EntityManager = getEntityManager();
    Arcade::ECS::IEntity &nibblerMap = EntityManager.createEntity(NIBBLER_MAP_ID);
    Arcade::ECS::IEntity &nibblerWalls = EntityManager.createEntity(NIBBLER_WALL_ID);
    std::vector<int> wallsPos;
    int nibblerMapParcelNbr = 0;

    for (int i = 0; i < NBR_OF_WALLS; i++) {
        wallsPos.push_back(rand() % (MAP_PARCELLS_X * MAP_PARCELLS_Y));
    }
    for (int y = 0; y < MAP_PARCELLS_Y; y++, nibblerMapParcelNbr++) {
        for (int x = 0; x < MAP_PARCELLS_X; x++, nibblerMapParcelNbr++) {
        if (std::find(wallsPos.begin(), wallsPos.end(), nibblerMapParcelNbr) != wallsPos.end()) {
                addNibblerWall(nibblerMap,
                    Arcade::Vector3f(NIBBLER_PADDING_WINDOW_X + x * PARCELL_SIZE,
                    NIBBLER_PADDING_WINDOW_Y + y * MAP_PARCELLS_X, 0),
                    nibblerMapParcelNbr);
            }
        }
    }
    nibblerMapParcelNbr = 0;
    for (int y = 0; y < MAP_PARCELLS_Y; y++, nibblerMapParcelNbr++) {
        for (int x = 0; x < MAP_PARCELLS_X; x++, nibblerMapParcelNbr++) {
            addNibblerParcel(nibblerWalls,
                Arcade::Vector3f(NIBBLER_PADDING_WINDOW_X + x * PARCELL_SIZE,
                NIBBLER_PADDING_WINDOW_Y + y * PARCELL_SIZE, 0),
                nibblerMapParcelNbr);
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
