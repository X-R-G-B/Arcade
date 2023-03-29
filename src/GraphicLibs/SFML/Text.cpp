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
    ECS::IComponent comp;
    Graph::IText &TextComp = static_cast<Graph::IText&>(IComp);

    try {
        entity.getComponents(TextComp.id + "_Sfml");
        entity.addComponent(std::make_unique<SfText>(TextComp.id + "_Sfml", TextComp.fontPath, TextComp.text, TextComp.textColor, TextComp.pos));
    } catch (std::exception &e) {
    }
    comp = entity.getComponents(TextComp.id + "_Sfml");
    if (comp.type != ECS::CompType::SFTEXT) {
        return;
    }
    SfText &text = static_cast<SfText&>(comp);
    text->text.setPosition(sf::Vector2f(TextComp.pos.x, TextComp.pos.y));
    _win.draw(text->text);
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
    const std::string &text, const Graph::Color &textColor, const Arcade::Vector3f &pos)
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
    this->text.setPosition(sf::Vector2f(pos.x, pos.y));
}
