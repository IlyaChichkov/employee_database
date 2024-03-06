//
// Created by ilya5 on 06.03.2024.
//

#include "catch2/catch_all.hpp"

#include <iostream>
#include <sstream>
#include "../src/Employee.h"
#include "../src/Database.h"


TEST_CASE( "DatabaseTest", "[database]" ) {
    ERS::Database database;

    SECTION( "Check new employee adding" ) {
        database.addEmployee("Tom", "Brown");
        int employeeNumber = ERS::c_FirstEmployeeNumber;
        ERS::HR::Employee employee = database.getEmployee(employeeNumber);

        REQUIRE( employee.getFirstName() == "Tom" );
        REQUIRE( employee.getLastName() == "Brown" );
        REQUIRE( employee.getSalary() == ERS::HR::c_DefaultStartingSalary );
        REQUIRE( employee.getTitle() == ERS::HR::Title::None );
        REQUIRE( employee.getEmployeeNumber() == 1000 );
    }

    SECTION( "Check empty database display all message" ) {
        auto stdoutBuffer = std::cout.rdbuf();
        std::ostringstream oss;
        std::cout.rdbuf(oss.rdbuf());
        database.displayAll();
        std::cout.rdbuf(stdoutBuffer);
        REQUIRE(oss.str() == "Database is empty.\n");
    }

    SECTION( "Check empty database display current message" ) {
        auto stdoutBuffer = std::cout.rdbuf();
        std::ostringstream oss;
        std::cout.rdbuf(oss.rdbuf());
        database.displayCurrent();
        std::cout.rdbuf(stdoutBuffer);
        REQUIRE(oss.str() == "Empty display result.\n");
    }

    SECTION( "Check empty database display former message" ) {
        auto stdoutBuffer = std::cout.rdbuf();
        std::ostringstream oss;
        std::cout.rdbuf(oss.rdbuf());
        database.displayFormer();
        std::cout.rdbuf(stdoutBuffer);
        REQUIRE(oss.str() == "Empty display result.\n");
    }
}
