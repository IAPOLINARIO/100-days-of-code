/**
 * DAY-91 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 * 
 * ATTENTION:
 * It needs at least a C++17 compiler because of the usage of magic_enum
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include "../../../../dependencies/c++/magic_enum.hpp" //https://github.com/Neargye/magic_enum

/**
 * What will be the month of Cyberpunk 2078 launch?
 * @param currentMonth Current Month
 * @param months Months to release
 * @return Name of the Month
 */ 
std::string monthsToCyberpunk2078(std::string currentMonth, int monthsToRelease) {
    const std::string INVALID = "NEVER";
    if (monthsToRelease < 0) { 
        return INVALID; //constraint
    }

    enum MonthsOfTheYear {
        January, February, March, April, May, June, July, August, September, October, November, December
    };

    auto currentMonthAux = magic_enum::enum_cast<MonthsOfTheYear>(currentMonth);
    if (!currentMonthAux.has_value()) {
        return INVALID; //constraint - invalid parameter currentMonth
    }
    
    auto p = (magic_enum::enum_integer(currentMonthAux.value()) + monthsToRelease) % magic_enum::enum_count<MonthsOfTheYear>();
    auto releaseMonth = magic_enum::enum_value<MonthsOfTheYear>(p);
    auto m = magic_enum::enum_name(releaseMonth);

    return std::string(m); //std::string from std::string_view
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(monthsToCyberpunk2078("November", 3) == "February");
    CHECK(monthsToCyberpunk2078("May", 24) == "May");
    CHECK(monthsToCyberpunk2078("May", 0) == "May");
    CHECK(monthsToCyberpunk2078("May", -1) == "NEVER");
    CHECK(monthsToCyberpunk2078("may", 1) == "NEVER");
}











