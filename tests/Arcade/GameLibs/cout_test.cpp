#include <iostream>
#include "../../../src/Api.hpp"
#include "../../../src/Arcade/ECS/EntityManager.hpp"
#include "../../../src/Arcade/ECS/SystemManager.hpp"
#include "../../../src/Arcade/Game/AScene.hpp"
#include "../../../src/Arcade/Game/IGameModule.hpp"
#include "../../../src/Arcade/Graph/Sprite.hpp"

namespace Arcade {
    namespace ECS {
        /**
         * @brief The components types enum
         *
         * defaultComponent type to implement: TEXT, SPRITE, MUSIC
         */
        enum class CompType : int {
            TEXT = 0,
            SPRITE = 1,
            MUSIC = 2,
            POSITION = 3,
        };
    } // namespace ECS
};    // namespace Arcade

class test_game : public Arcade::Game::IGameModule {
    public:
        test_game();
        ~test_game() = default;
        void update(float deltaTime, Arcade::ECS::IEventManager &eventManager);
        Arcade::ECS::IEntityManager &getCurrentEntityManager();

    private:
        Arcade::ECS::SystemManager _systemManager;
        std::vector<std::unique_ptr<Arcade::Game::IScene>> _scenes;
};

// ------------------------- Component -------------------------
namespace Arcade::ECS {
    class PositionComponent : public Arcade::ECS::IComponent {
        public:
            PositionComponent(int x, int y) : _x(x), _y(y)
            {
                this->type = Arcade::ECS::CompType::POSITION;
                this->id = "position";
            }
            ~PositionComponent() = default;
            int getX() const
            {
                return _x;
            }
            int getY() const
            {
                return _y;
            }
            void setX(int x)
            {
                _x = x;
            }
            void setY(int y)
            {
                _y = y;
            }

        private:
            int _x;
            int _y;
    };
} // namespace Arcade::ECS

namespace Arcade::ECS {
    class PlayerSprite : public Arcade::Graph::Sprite {
        public:
            PlayerSprite(const std::string &id) :
            Arcade::Graph::Sprite(id) {}
            ~PlayerSprite() = default;
    };
} // namespace Arcade::ECS

// ---------------------------------------------------------

// ------------------------- Scene -------------------------
class test_scene : public Arcade::Game::AScene {
    public:
        test_scene()
            : Arcade::Game::AScene(
            std::make_unique<Arcade::ECS::EntityManager>())
        {
        }
        ~test_scene() = default;
        bool init() final;
        void close() final;
};

bool test_scene::init()
{
    std::cout << "test_scene::init" << std::endl;

    this->getEntityManager().createEntity("player");
    this->getEntityManager().getEntitiesById("player")->addComponent(
    std::make_shared<Arcade::ECS::PositionComponent>(0, 0));
    this->getEntityManager().getEntitiesById("player")->addComponent(
    std::make_shared<Arcade::ECS::PlayerSprite>("player sprite"));
    Arcade::Graph::Sprite &sprite_player = static_cast<Arcade::Graph::Sprite &>(
    this->getEntityManager().getEntitiesById("player")->getComponents(
    "player sprite"));
    sprite_player.path = "/assets/leplayer.png";
    sprite_player.pos = {0, 10, 15};
    sprite_player.rect = {10, 10, 80, 80};
    sprite_player.ttyData = {"@", {1, 2, 3, 4}};
    sprite_player.type = Arcade::ECS::CompType::SPRITE;

    this->getEntityManager().createEntity("enemy");
    this->getEntityManager().getEntitiesById("enemy")->addComponent(
    std::make_shared<Arcade::ECS::PositionComponent>(
    Arcade::ECS::PositionComponent(100, 100)));
    this->getEntityManager().getEntitiesById("enemy")->addComponent(
    std::make_shared<Arcade::ECS::PlayerSprite>("Enemy sprite"));
    Arcade::Graph::Sprite &sprite_enemy = static_cast<Arcade::Graph::Sprite &>(
    this->getEntityManager().getEntitiesById("enemy")->getComponents(
    "Enemy sprite"));
    sprite_enemy.path = "/assets/leennemy.png";
    sprite_enemy.pos = {0, 10, 15};
    sprite_enemy.rect = {10, 10, 80, 80};
    sprite_enemy.ttyData = {"@", {1, 2, 3, 4}};
    sprite_enemy.type = Arcade::ECS::CompType::SPRITE;

    return true;
}

void test_scene::close()
{
    std::cout << "test_scene::close" << std::endl;
    this->getEntityManager().removeAllEntities();
}
// ---------------------------------------------------------

// ------------------------- System -------------------------
class test_system : public Arcade::ECS::ISystem {
    public:
        test_system() = default;
        ~test_system() = default;
        void run(float deltaTime, Arcade::ECS::IEventManager &eventManager,
        Arcade::ECS::IEntityManager &currentScene);
};

void test_system::run(float deltaTime, Arcade::ECS::IEventManager &eventManager,
Arcade::ECS::IEntityManager &entityManager)
{
    int xPos = 0;
    int yPos = 0;
    std::cout << "test_system::update" << std::endl;
    auto entities =
    entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::POSITION);

    for (auto &entity : *entities) {
        auto &components =
        entity->getComponents(Arcade::ECS::CompType::POSITION);
        if (entity->getId() == "player") {
            std::cout << "player" << std::endl;
            for (int i = 0; i < components.size(); i++) {
                auto *position = static_cast<Arcade::ECS::PositionComponent *>(
                components[i].get());
                xPos = position->getX();
                yPos = position->getY();
                std::cout << "x: " << xPos << " y: " << yPos << std::endl;
                xPos = (xPos < 100) ? xPos + 1 : 0;
                yPos = (yPos < 100) ? yPos + 1 : 0;
                position->setX(xPos);
                position->setY(yPos);
            }
        } else {
            std::cout << "enemy" << std::endl;
            for (int i = 0; i < components.size(); i++) {
                auto *position = static_cast<Arcade::ECS::PositionComponent *>(
                components[i].get());
                xPos = position->getX();
                yPos = position->getY();
                std::cout << "x: " << xPos << " y: " << yPos << std::endl;
                xPos = (xPos > 0) ? xPos - 1 : 100;
                yPos = (yPos > 0) ? yPos - 1 : 100;
                position->setX(xPos);
                position->setY(yPos);
            }
        }
    }
}
// ---------------------------------------------------------

// ------------------------- Game -------------------------
test_game::test_game()
{
    std::cout << "test_game::test_game" << std::endl;
    _systemManager.addSystem("Player", std::make_unique<test_system>());
    _systemManager.addSystem("Enemy", std::make_unique<test_system>());
    auto scene = std::make_unique<test_scene>();
    scene->init();
    _scenes.push_back(std::move(scene));
}

void test_game::update(
float deltaTime, Arcade::ECS::IEventManager &eventManager)
{
    std::cout << "test_game::update" << std::endl;

    for (auto &scene : _scenes) {
        _systemManager.update(
        deltaTime, eventManager, scene->getEntityManager());
    }
}

Arcade::ECS::IEntityManager &test_game::getCurrentEntityManager()
{
    std::cout << "test_game::getCurrentEntityManager" << std::endl;
    return _scenes[0]->getEntityManager();
}
// ---------------------------------------------------------

// ------------------------- API -------------------------
LibType getType()
{
    return LibType::GAME;
}

void destroyGameModule(Arcade::Game::IGameModule *gameModule)
{
    if (gameModule)
        delete gameModule;
}

Arcade::Game::IGameModule *getGameModule()
{
    Arcade::Game::IGameModule *gameModule = new test_game();

    return gameModule;
}

const char *getName()
{
    return "LE JEU DE QUALITE";
}
