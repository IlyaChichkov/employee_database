//
// Created by ilya5 on 06.03.2024.
//

#include "catch2/catch_all.hpp"

#include <iostream>
#include "../src/Employee.h"

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