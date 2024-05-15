//
// Purpur Tentakel
// 15.05.24
//

#include <ta/temporary.hpp>
#include <cpt/Strings.hpp>
#include <spdlog/spdlog.h>

void print_split(std::string const& message)
{
    auto const split = cpt::split(message, ",", cpt::SplitBehavior::SkipEmptyParts);
    for (auto const& s : split)
    {
        spdlog::info(s);
    }
}
