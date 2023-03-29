/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml
*/

#include <iostream>
#include "Text.hpp"
#include "Exceptions.hpp"

Arcade::Sfml::TextSystem::TextSystem(sf::RenderWindow &win) : _win(win)
{
}

void Arcade::Sfml::TextSystem::handleComponent(ECS::IComponent &IComp, ECS::IEntity &entity)
{
    Graph::IText &TextComp = static_cast<Graph::IText&>(IComp);

    try {
        entity.addComponent(std::make_shared<SfText>(TextComp.id + "_Sfml", TextComp.fontPath, TextComp.text, TextComp.textColor, TextComp.pos, _win));
    } catch (std::exception &e) {
    }
    ECS::IComponent &comp = entity.getComponents(TextComp.id + "_Sfml");
    if (comp.type != ECS::CompType::SFTEXT) {
        return;
    }
    SfText &text = static_cast<SfText&>(comp);
    text.setPosition(TextComp.pos);
    _win.draw(text.text);
}

void Arcade::Sfml::TextSystem::run(float deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    std::unique_ptr<std::vector<std::shared_ptr<ECS::IEntity>>> _containTextEntities =
        currentEntityManager.getEntitiesByComponentType(ECS::CompType::TEXT);
    std::vector<std::shared_ptr<ECS::IComponent>> _components;

    for (auto const &entity : *(_containTextEntities.get())) {
        _components = entity->getComponents(ECS::CompType::TEXT);
        for (auto const &component : _components) {
            handleComponent(*(component.get()), *(entity.get()));
        }
    }
}

Arcade::Sfml::SfText::SfText(const std::string id, const std::string &path,
    const std::string &text, const Graph::Color &textColor, const Arcade::Vector3f &pos, sf::RenderWindow &win) : _win(win)
{
    this->id = id;
    this->type = ECS::CompType::SFTEXT;
    if (!font.loadFromFile(path)) {
        throw ArcadeExceptions("Wrong path for font : " + path);
    }
    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setCharacterSize(24);
    this->text.setFillColor(sf::Color(textColor.r, textColor.g, textColor.b, textColor.a));
    setPosition(pos);
}

void Arcade::Sfml::SfText::setPosition(const Arcade::Vector3f &pos)
{
    sf::Vector2u size = _win.getSize();
    this->text.setPosition(sf::Vector2f((pos.x / 100) * size.x, (pos.y / 100) * size.y));
}
