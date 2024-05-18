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
        [[nodiscard]] tl::optional<T> get_component() const {
            for (auto const& c : m_components) {
                if (std::holds_alternative<T>(m_components)) {
                    return std::get<T>(m_components);
                }
            }
            return {};
        }

        template<ComponentType T>
        void add(T component) {
            m_components.emplace_back(std::forward<decltype(component)>(component));
        }
    };
} // namespace data
