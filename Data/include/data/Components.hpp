//
// Purpur Tentakel
// 18.05.24
//

#pragma once

#include <cpt/Concepts.hpp>
#include <cpt/Types.hpp>
#include <raylib.h>
#include <variant>

namespace data {
    struct SpaceObject final {
        cpt::usize id;
        cpt::usize x, y;
        cpt::usize ships;
        cpt::usize player_id;
    };
    struct Planet final {
        cpt::usize production;
        cpt::usize max_ships;
        cpt::usize production_problem_years;
        bool is_home_planet;
    };
    struct BlackHole final {
        cpt::usize range;
    };
    struct Fleet final {
        cpt::usize target_id;
        cpt::usize engine_problem_years;
    };
    struct TargetPoint final { };

    struct SpriteRenderer final {
        Texture2D texture;
    };

    using Component = std::variant<SpaceObject, Planet, BlackHole, Fleet, TargetPoint, SpriteRenderer>;
    template<typename T>
    concept ComponentType = cpt::IsOneOf<T, SpaceObject, Planet, BlackHole, Fleet, TargetPoint, SpriteRenderer>;
} // namespace data
