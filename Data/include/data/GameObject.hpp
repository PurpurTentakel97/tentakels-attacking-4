//
// Purpur Tentakel
// 18.05.24
//

#pragma once
#include <data/Components.hpp>
#include <tl/optional.hpp>
#include <variant>
#include <vector>

namespace data {
    class GameObject final {
    private:
        std::vector<Component> m_components;

    public:
        template<ComponentType T>
        [[nodiscard]] tl::optional<T const&> get_component() const {
            for (auto const& c : m_components) {
                if (std::holds_alternative<T>(c)) {
                    return std::get<T>(c);
                }
            }
            return {};
        }

        template<ComponentType T>
        [[nodiscard]] tl::optional<T&> get_component() {
            for (auto& c : m_components) {
                if (std::holds_alternative<T>(c)) {
                    return std::get<T>(c);
                }
            }
            return {};
        }

        template<ComponentType T>
        GameObject& add(T component) {
            if (get_component<T>().has_value()) {
                throw BadComponentError("add of already existing component");
            } else {
                m_components.emplace_back(std::forward<decltype(component)>(component));
            }
            return *this;
        }
    };
} // namespace data
