//
// Purpur Tentakel
// 18.05.24
//

#include <data/GameObject.hpp>
#include <gtest/gtest.h>

TEST(Components, Component) {
    auto constexpr space_object = data::SpaceObject{};
    auto constexpr fleet        = data::Fleet{};
    auto const game_object      = data::GameObject{}.add(space_object).add(fleet);

    auto const object_result       = game_object.get_component<data::Fleet>();
    auto const space_object_result = game_object.get_component<data::SpaceObject>();
    auto const random_result       = game_object.get_component<data::Planet>();

    EXPECT_TRUE(object_result.has_value());
    EXPECT_TRUE(space_object_result.has_value());
    EXPECT_FALSE(random_result.has_value());
}

TEST(Components, DoubleComponent) {
    auto constexpr space_object = data::SpaceObject{};

    try {
        auto game_object = data::GameObject{}.add(space_object).add(space_object);
        GTEST_FAIL() << "not thwow while adding same Component twice";
    } catch (data::BadComponentError const& e) { EXPECT_STREQ(e.what(), "add of already existing component"); }
}

TEST(Components, ChangeValue) {
    auto constexpr space_object = data::SpaceObject{};
    auto game_object            = data::GameObject{}.add(space_object);

    auto result = game_object.get_component<data::SpaceObject>();
    ASSERT_TRUE(result.has_value());
    EXPECT_EQ(result.value().id, 0);

    result.value().id = 1;

    result = game_object.get_component<data::SpaceObject>();
    ASSERT_TRUE(result.has_value());
    EXPECT_EQ(result.value().id, 1);
}
