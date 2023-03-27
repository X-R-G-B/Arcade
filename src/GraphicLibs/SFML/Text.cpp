/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml
*/

#include "Text.hpp"

void Arcade::Sfml::TextSystem::handleComponent(Graph::IText &comp, ECS::IEntity &entity, SfmlWindow &win)
{
    Text &text;

    try {
        entity.getComponents(comp.id + "_Sfml");
        entity.addComponent(std::make_unique<SfmlText>(comp.id + "_Sfml", comp.fontPath, comp.text, comp.textColor, comp.pos));
    } catch (std::exception &e) {
    }
    text = entity.getComponents(comp.id + "_Sfml");
    win.draw(text.text);
}

Arcade::Sfml::TextSystem::run(float deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    std::unique_ptr<std::vector<std::shared<IEntity>>> _containTextEntities =
        currentEntityManager.getEntitiesByComponentTime(CompType::Text);
    std::vector<std::shared_ptr<IComponent>> _components;
    std::shared_ptr<SfmlWindow> win = currentEntityManager.getEntitiesById("window");

    for (auto const &entity : *(_containTextEntities.get())) {
        _components = entity->getComponents(CompType::Text);
        for (auto const &component : _components) {
            handleComponent(*(component.get()), *(entity.get()), *(win.get()));
        }
    }
}

Arcade::Sfml::Text::Text(const std::string id, const std::string &path,
    const std::string &text, const Graph::Color &textColor, const Arcade::Vector3f &pos)
{
    sf::Font font;

    this->id = id;
    this->type = CompType::SfmlText;
    if (!font.loadFromFile(path)) {
        //TODO put right error type 
        throw std::invalid_argument("Wrong path for font : " + path);
    }
    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setCharacterSize(24);
    this->text.setFillColor(sf::Color::Color(textColor.r, textColor.g, textColor.b, textColor.a));
    this->text.setPosition(sf::Vector2f::Vector2(pos.x, pos.y));
}
