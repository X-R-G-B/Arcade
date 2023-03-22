#include <iostream>
#include <optional>
#include "EventManager.hpp"
#include "IComponent.hpp"

namespace Arcade {
    namespace ECS {
        enum class CompType {
            SOMETHING
        };
    }
}

class Comp : public Arcade::ECS::IComponent {
    public:
        Comp() {
            _id = "Comp";
        }
        ~Comp() = default;
        Arcade::ECS::CompType getType() const override {
            return Arcade::ECS::CompType::SOMETHING;
        }
        const std::string &getId() const override {
            return _id;
        }
        std::string _id;
};

int main()
{
    Arcade::ECS::EventManager eventManager;

    if (eventManager.eventsIsEmpty() == false) {
        std::cout << "Event manager is not empty. WTF" << std::endl;
        return 1;
    }
    eventManager.addEvent("event1", std::nullopt);
    auto evt1 = eventManager.isEventTriggered("event1");
    if (evt1.first == false) {
        std::cout << "Event manager has not event1. WTF" << std::endl;
        return 1;
    }
    if (evt1.second.has_value() == false || evt1.second.value().size() == 0) {
        std::cout << "That is not right, there is one std::nullopt in the vector" << std::endl;
        return 1;
    }
    if (evt1.second.value()[0] != std::nullopt) {
        std::cout << "That is not right, there is one std::nullopt in the vector" << std::endl;
        return 1;
    }
    eventManager.clearEvents();
    if (eventManager.eventsIsEmpty() == false) {
        std::cout << "I just cleared it, why it is not empty" << std::endl;
        return 1;
    }
    eventManager.addEvent("event2", std::make_optional(std::make_shared<Comp>()));
    auto evt2 = eventManager.isEventTriggered("event2");
    if (evt2.first == false) {
        std::cout << "Event manager has not event2. WTF" << std::endl;
        return 1;
    }
    if (evt2.second.value().size() == 0) {
        std::cout << "That is not right, there is one parameter in the vector" << std::endl;
        return 1;
    }
    if ((*evt2.second.value()[0])->getType() != Arcade::ECS::CompType::SOMETHING ||
            (*evt2.second.value()[0])->getId() != "Comp") {
        std::cout << "That is not right, the parameter is not the good one" << std::endl;
        return 1;
    }
    eventManager.addEvent("event3", std::make_optional(std::make_shared<Comp>()));
    eventManager.addEvent("event2", std::nullopt);
    evt2 = eventManager.isEventTriggered("event2");
    if (evt2.first == false) {
        std::cout << "Event manager has not event2. WTF" << std::endl;
        return 1;
    }
    if (evt2.second.value().size() != 2) {
        std::cout << "That is not right, there is two parameter in the vector" << std::endl;
        return 1;
    }
    if ((evt2.second.value()[0].has_value() == true && evt2.second.value()[1].has_value() == false) ||
        (evt2.second.value()[0].has_value() == false && evt2.second.value()[1].has_value() == true)) {
    } else {
        return 1;
    }
    eventManager.clearEvents();
    if (eventManager.eventsIsEmpty() == false) {
        std::cout << "I just cleared it, why it is not empty" << std::endl;
        return 1;
    }
    return 0;
}
