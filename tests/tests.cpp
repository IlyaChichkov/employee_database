//
// Created by ilya5 on 05.03.2024.
//

#include "../lib/catch2/catch.hh"
#include <iostream>
#include <sstream>
#include <Employee.h>
#include <Database.h>


TEST_CASE( "EmployeeTest", "[employee]" ) {
    ERS::HR::Employee employee("Tom", "Brown");

    SECTION( "Check object getters" ) {
        REQUIRE( employee.getFirstName() == "Tom" );
        REQUIRE( employee.getLastName() == "Brown" );
        REQUIRE( employee.getSalary() == ERS::HR::c_DefaultStartingSalary );
        REQUIRE( employee.getTitle() == ERS::HR::Title::None );
        REQUIRE( employee.getEmployeeNumber() == -1 );
    }

    SECTION( "Check object setters" ) {
        employee.setFirstName("Bob");
        REQUIRE( employee.getFirstName() == "Bob" );
        employee.setLastName("Smith");
        REQUIRE( employee.getLastName() == "Smith" );
        employee.setSalary(54'120);
        REQUIRE( employee.getSalary() == 54'120 );
        employee.setTitle(ERS::HR::Title::Manager);
        REQUIRE( employee.getTitle() == ERS::HR::Title::Manager );
        employee.setEmployeeNumber(1012);
        REQUIRE( employee.getEmployeeNumber() == 1012 );
    }

}

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

    SECTION( "Check new employee adding" ) {
        auto stdoutBuffer = std::cout.rdbuf();
        std::ostringstream oss;
        std::cout.rdbuf(oss.rdbuf());
        database.displayAll();
        std::cout.rdbuf(stdoutBuffer);
        REQUIRE(oss.str() == "Database is empty.\n");

    }
}
