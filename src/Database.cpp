//
// Created by ilya5 on 05.03.2024.
//

#include "Database.h"

namespace ERS {
    Employee &Database::addEmployee(const std::string &firstName, const std::string &lastName) {
        Employee employee(firstName, lastName);
        employee.setEmployeeNumber(m_nextEmployeeNumber++);
        employee.hire();

        m_employees.push_back(employee);
        return m_employees.back();
    }

    Employee &Database::getEmployee(int employeeNumber) {
        for(auto& employee : m_employees)
        {
            if(employee.getEmployeeNumber() == employeeNumber)
            {
                return employee;
            }
        }
        throw std::logic_error { "No employee found." };
    }

    void Database::displayAll() const {
        for(auto& employee : m_employees)
        {
            employee.display();
        }
    }

    void Database::displayCurrent() const {
        for(auto& employee : m_employees)
        {
            if(employee.isHired())
            {
                employee.display();
            }
        }
    }

    void Database::displayFormer() const {
        for(auto& employee : m_employees)
        {
            if(!employee.isHired())
            {
                employee.display();
            }
        }
    }
} // ERS