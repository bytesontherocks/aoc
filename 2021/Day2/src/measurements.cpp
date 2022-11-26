#include "measurements.hpp"

int64_t measurements::calculatePosition(const std::vector<std::pair<direction, int32_t>>& v)
{
    int32_t x = 0;
    int32_t y = 0;

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        auto dir = it->first;
        auto val = it->second;

        switch (dir)
        {
            case direction::forward:
                x += val;
            break;
            case direction::up:
                y -= val;
            break;
            case direction::down:
                y += val;
            break;
            default:
            break;

        }
    }

    return x*y;
}

int64_t measurements::calculatePositionWithAim(const std::vector<std::pair<direction, int32_t>>& v)
{
    int32_t x = 0;
    int32_t y = 0;
    int32_t aim= 0;

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        auto dir = it->first;
        auto val = it->second;

        switch (dir)
        {
            case direction::forward:
                x += val;
                y += (aim*val);
            break;
            case direction::up:
                aim -= val;
            break;
            case direction::down:
                aim += val;
            break;
            default:
            break;

        }
    }

    return x*y;
}
