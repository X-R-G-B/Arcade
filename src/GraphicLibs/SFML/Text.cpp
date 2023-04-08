/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Sfml
*/

#include "Text.hpp"
#include "Exceptions.hpp"
#include "IEntity.hpp"

Arcade::Sfml::TextSystem::TextSystem(sf::RenderWindow &win, std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &components)
    : _win(win), _components(components)
{
}

std::shared_ptr<Arcade::Sfml::SfText> Arcade::Sfml::TextSystem::getComponent(std::shared_ptr<Graph::IText> TextComp, const std::string &idEntity)
{
    for (auto const &comp : _components) {
        if (comp->id == TextComp->id + idEntity) {
           return std::static_pointer_cast<SfText>(comp);
        }
    }

    std::shared_ptr<SfText> text = std::make_shared<SfText>(TextComp->id + idEntity, TextComp->fontPath, TextComp->text, TextComp->textColor, TextComp->pos, _win);
    _components.push_back(text);
    return text;
}

void Arcade::Sfml::TextSystem::handleComponent(std::shared_ptr<Graph::IText> TextComp, const std::string &idEntity)
{
    std::shared_ptr<SfText> text = getComponent(TextComp, idEntity);
    text->text.setString(TextComp->text);
    text->text.setPosition(sf::Vector2f(TextComp->pos.x, TextComp->pos.y));
    _win.draw(text->text);
}

void Arcade::Sfml::TextSystem::run(double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    std::unique_ptr<std::vector<std::shared_ptr<Arcade::ECS::IEntity>>> entities;
 
    try {
        entities = currentEntityManager.getEntitiesByComponentType(ECS::CompType::TEXT);
    } catch (const std::exception &e) {
        return;
    }
    if (entities.get() == nullptr) {
        return;
    }
    for (auto const &entity : *entities) {
        try {
            const std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &sprites =
                entity->getComponents(Arcade::ECS::CompType::TEXT);
            for (auto const &sprite : sprites) {
                handleComponent(std::static_pointer_cast<Graph::IText>(sprite), entity->getId());
            }
        } catch (...) {
            continue;
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
    this->text.setPosition(sf::Vector2f(pos.x, pos.y));
}
