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

bool Nibbler::Scene::GameScene::checkWallCollision(Arcade::ECS::IEntityManager &entityManager, const  Arcade::Vector3f &pos)
{
    std::unique_ptr<std::vector<std::shared_ptr<Arcade::ECS::IEntity>>> walls = entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::FORWARD);

    if (pos.x < 0 || pos.x > SCREEN_WIDTH || pos.y < 0 || pos.y > SCREEN_HEIGHT) {
        return true;
    }
    for (auto tmp : *(walls.get())) {
        auto wall = std::static_pointer_cast</* entiry body */>(tmp);
        auto wallPos = wall->getComponent(Arcade::ECS::CompType::FORWARD);
        if (pos.x >= wallPos->x && pos.x <= wallPos->x + 128 && pos.y >= wallPos->y && pos.y <= wallPos->y + 128) {
            return true;
        }
    }
    return false;
}

void Nibbler::Scene::GameScene::addNibblerWallSquare(Arcade::ECS::IEntityManager &entityManager, const Arcade::Vector3f &src_pos)
{
    Arcade::Vector3f pos = src_pos;

    for (int i = 0; i < 4; i++) {
        if (!checkWallCollision(entityManager, pos)) {
            entityManager.createEntity(NIBBLER_WALL_ID)
                .addComponent(std::make_shared<Nibbler::Component::NibblerWallComponent>(
                    std::string(NIBBLER_WALL_ID) + "_" + std::to_string(pos.x) + "_" + std::to_string(pos.y),
                    pos));
        }
        switch (i) {
            case 0:
                pos.x += 128;
                break;
            case 1:
                pos.y += 128;
                break;
            case 2:
                pos.x -= 128;
                break;
            default:
                break;
        }
    }
}

void Nibbler::Scene::GameScene::addNibblerWall(Arcade::ECS::IEntityManager &entityManager, const Arcade::Vector3f &pos, int nbrOfWalls)
{
    static std::vector<std::function<void (Arcade::ECS::IEntityManager &, const Arcade::Vector3f &)>> addNibblerWallFunctions = {
        std::bind(&Nibbler::Scene::GameScene::addNibblerWallSquare, this, std::placeholders::_1, std::placeholders::_2),
    };
    auto funcNbr = rand() % addNibblerWallFunctions.size();

    addNibblerWallFunctions[funcNbr](entityManager, pos);
}

void Nibbler::Scene::GameScene::addNibblerParcel(Arcade::ECS::IEntityManager &entityManager, const Arcade::Vector3f &pos, int nbrOfParcels)
{
    if (checkWallCollision(entityManager, pos)) {
        return;
    }
    if (pos.x < 0 || pos.x > SCREEN_WIDTH || pos.y < 0 || pos.y > SCREEN_HEIGHT) {
        return;
    }
    entityManager.createEntity(NIBBLER_MAP_ID)
        .addComponent(std::make_shared<Nibbler::Component::NibblerMapComponent>(
            std::string(NIBBLER_MAP_ID) + "_" + std::to_string(pos.x) + "_" + std::to_string(pos.y),
            pos));
}

void Nibbler::Scene::GameScene::addNibblerMap()
{
    Arcade::ECS::IEntityManager &EntityManager = getEntityManager();
    Arcade::ECS::IEntity &nibblerMap = EntityManager.createEntity(NIBBLER_MAP_ID);
    int nibblerMapParcelNbr = 0;

    for (int y = 0; y < NBR_OF_PARCELS_IN_LINE; y++, nibblerMapParcelNbr++) {
        for (int x = 0; x < NBR_OF_PARCELS_IN_LINE; x++, nibblerMapParcelNbr++) {
            if (x == 0 || x == NBR_OF_PARCELS_IN_LINE - 1 || y == 0 || y == NBR_OF_PARCELS_IN_LINE - 1) {
                addNibblerWall(EntityManager, Arcade::Vector3f(NIBBLER_PADDING_WINDOW_X + x * NIBBLER_MAP_SIZE, NIBBLER_PADDING_WINDOW_Y + y * NIBBLER_MAP_SIZE, 0), nibblerMapParcelNbr);
            }
        }
    }
    nibblerMapParcelNbr = 0;
    for (int y = 0; y < NBR_OF_PARCELS_IN_LINE; y++, nibblerMapParcelNbr++) {
        for (int x = 0; x < NBR_OF_PARCELS_IN_LINE; x++, nibblerMapParcelNbr++) {
            addNibblerParcel(EntityManager, Arcade::Vector3f(NIBBLER_PADDING_WINDOW_X + x * NIBBLER_MAP_SIZE, NIBBLER_PADDING_WINDOW_Y + y * NIBBLER_MAP_SIZE, 0), nibblerMapParcelNbr);
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
