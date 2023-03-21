//
// EPITECH PROJECT, 2023
// Arcade
// File description:
// Event Manager
//

#pragma once

#include <vector>
#include <map>
#include <memory>
#include "ArcadeStruct.hpp"
#include "IComponent.hpp"
#include "IEventManager.hpp"

namespace Arcade {
    namespace ECS {
        class EventManager : public IEventManager {
            public:
                EventManager() = default;
                ~EventManager() = default;

                bool eventsIsEmpty() const override;
                std::pair<bool, std::vector<std::optional<std::shared_ptr<IComponent>>>>
                    isEventTriggered(const std::string &event) const override;
                void addEvent(const std::string &event,
                    std::optional<std::shared_ptr<IComponent>> component =
                    std::nullopt) override;
                void clearEvents() override;
                const Arcade::Vector2f &getMousePosition() const override;
                void setMousePosition(const Arcade::Vector2f &mousePosition) override;

            private:
                std::map<std::string, std::vector<std::optional<std::shared_ptr<Arcade::ECS::IComponent>>>> _events;
                Arcade::Vector2f _mousePosition;
        };
    }
}
