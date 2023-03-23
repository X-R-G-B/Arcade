/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SceneTest
*/

#include "../../../src/Arcade/Game/SceneManager.hpp"
#include "../../../src/Arcade/Game/IScene.hpp"

class BasicScene : public Arcade::Game::IScene {
    public:
    BasicScene() = default;
    ~BasicScene() = default;
                /**
                 * @brief Create the scene
                 *
                 * It exists because we don't want to create all
                 * entities/component at startup time but when the scene is
                 * activated
                 *
                 * @return True if the scene was created, false otherwise
                 */
                bool init() {}
                /**
                 * @brief Close the scene
                 *
                 * It exists because we don't want to destroy all the scene
                 * (we might still need it, but we want to dealocate some
                 * resource maybe ?)
                 */
                void close() {}
                /**
                 * @brief Get the entity manager of the scene
                 *
                 * @return The entity manager of the scene
                 */
                Arcade::ECS::IEntityManager &getEntityManager() {}
                /**
                 * @brief Get the system manager of the scene
                 *
                 * @return The system manager of the scene
                 */
                Arcade::ECS::ISystemManager &getSystemManager() {}
};

int main()
{
    Arcade::Game::SceneManager scenemanager;
    BasicScene basic;

    scenemanager.registerScene("salut", std::make_unique<BasicScene>());
    scenemanager.changeScene("salut");
    scenemanager.getCurrentScene();
}