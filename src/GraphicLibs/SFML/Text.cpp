/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml
*/

#include "Text.hpp"

void Arcade::Sfml::TextSystem::handleComponent(Graph::IText &comp, ECS::IEntity &entity, Window &win)
{
    try {
        entity.getComponents(comp.id + "_Sfml");
        entity.addComponent(std::make_unique<Text>(comp.id + "_Sfml", comp.fontPath, comp.text, comp.textColor, comp.pos));
    } catch (std::exception &e) {
    }
    ECS::IComponent &comp = entity.getComponents(comp.id + "_Sfml");
    win.draw(text.text);
}

void Arcade::Sfml::TextSystem::run(float deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    std::unique_ptr<std::vector<std::shared_ptr<IEntity>>> _containTextEntities =
        currentEntityManager.getEntitiesByComponentTime(CompType::Text);
    std::vector<std::shared_ptr<IComponent>> _components;
    std::shared_ptr<Window> win = currentEntityManager.getEntitiesById("window");

    for (auto const &entity : *(_containTextEntities.get())) {
        _components = entity->getComponents(CompType::Text);
        for (auto const &component : _git components) {
            handleComponent(*(component.get()), *(entity.get()), *(win.get()));
        }
    }
}

Arcade::Sfml::Text::Text(const std::string id, const std::string &path,
    const std::string &text, const Graph::Color &textColor, const Arcade::Vector3f &pos)
{
    sf::Font font;

    this->id = id;
    this->type = ECS::CompType::SFTEXT;
    if (!font.loadFromFile(path)) {
        //TODO put right error type 
        throw std::invalid_argument("Wrong path for font : " + path);
    }
    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(24);
    this->text.setColor(sf::Color(textColor.r, textColor.g, textColor.b, textColor.a));
    this->text.setPosition(sf::Vector2f(pos.x, pos.y));
}
