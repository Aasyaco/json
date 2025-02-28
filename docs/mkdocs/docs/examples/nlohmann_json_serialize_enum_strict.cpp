#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace ns
{
enum class Color
{
    red, green, blue, pink
};

NLOHMANN_JSON_SERIALIZE_ENUM_STRICT(Color,
{
    { Color::red, "red" },
    { Color::green, "green" },
    { Color::blue, "blue" },
})
}

int main()
{
    // serialization
    try
    {
        json j_red = ns::Color::pink;
        auto color = j_red.get<ns::Color>();
        std::cout << static_cast<int>(color) << " -> " << j_red << std::endl;
    }
    catch (const nlohmann::json::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
