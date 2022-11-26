#include <utility>
#include <vector>
#include <cinttypes>

enum class direction {
    forward, 
    down, 
    up
};
namespace measurements {

    int64_t calculatePosition(const std::vector<std::pair<direction, int32_t>>& v);
    int64_t calculatePositionWithAim(const std::vector<std::pair<direction, int32_t>>& v);
}