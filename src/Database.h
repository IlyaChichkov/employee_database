//
// Created by ilya5 on 05.03.2024.
//

#ifndef UNTITLED_DATABASE_H
#define UNTITLED_DATABASE_H

#include <iostream>
#include <vector>
#include "Employee.h"

namespace ERS {

    const int c_FirstEmployeeNumber = 1'000;

    class Database {
    public:
        Employee& addEmployee(const std::string& firstName, const std::string& lastName);
        Employee& getEmployee(int employeeNumber);

        void displayAll() const;
        void displayCurrent() const;
        void displayFormer() const;

    private:
        std::vector<Employee> m_employees;
        int m_nextEmployeeNumber = c_FirstEmployeeNumber;
    };

} // ERS

#endif //UNTITLED_DATABASE_H
