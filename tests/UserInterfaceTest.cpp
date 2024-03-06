//
// Created by ilya5 on 06.03.2024.
//

#include "catch2/catch_all.hpp"

#include "../src/UserInterface.h"
#include <string>

TEST_CASE( "UserInterfaceTest", "[userInterface]" ) {
    ERS::UserInterface userInterface;

    SECTION( "Check main menu title" ) {
        std::ostringstream oss;
        std::cout.rdbuf(oss.rdbuf());
        userInterface.displayMainMenu();
        REQUIRE(oss.str().substr(0, 28) == "     Employee Database     \n");
    }

}