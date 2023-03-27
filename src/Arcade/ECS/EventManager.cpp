/*
** EPITECH PROJECT, 2023
** Arcade Promo 2026 Toulouse
** File description:
** Event Manager
*/

#include "EventManager.hpp"
#include <optional>

bool Arcade::ECS::EventManager::eventsIsEmpty() const
{
    return _events.empty();
}

std::pair<bool,
std::optional<std::vector<std::optional<std::shared_ptr<Arcade::ECS::IComponent>>>>>
Arcade::ECS::EventManager::isEventTriggered(const std::string &event) const
{
    auto it = _events.find(event);
    if (it == _events.end()) {
        return std::make_pair(false, std::nullopt);
    }
    return std::make_pair(true, it->second);
}


void Arcade::ECS::EventManager::addEvent(const std::string &event,
std::optional<std::shared_ptr<Arcade::ECS::IComponent>> component)
{
    auto it = _events.find(event);
    if (it == _events.end()) {
        _events[event] = {component};
    } else {
        it->second.push_back(component);
    }
}

void Arcade::ECS::EventManager::clearEvents()
{
    _events.clear();
}
