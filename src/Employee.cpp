//
// Created by ilya5 on 05.03.2024.
//

#include "Employee.h"

namespace ERS::HR {

    Employee::Employee(const std::string &firstName, const std::string &lastName) {
        m_firstName = firstName;
        m_lastName = lastName;
    }

    void Employee::promote(int raiseAmount) {
        setSalary(getSalary() + raiseAmount);
    }

    void Employee::demote(int demeritAmount) {
        setSalary(getSalary() - demeritAmount);
    }

    void Employee::hire() {
        m_hired = true;
    }

    void Employee::fire() {
        m_hired = false;
    }

    void Employee::display() const {
        std::cout << "> Employee:" << std::endl;
        std::cout << "  First name: " << getFirstName() << "  last name: " << getLastName() << std::endl;
        std::cout << "  Employee number: " << getEmployeeNumber() << std::endl;
        std::cout << "  Salary: " << getSalary() << std::endl;
        std::cout << "  Is hired: " << (isHired() ? "True" : "False") << std::endl;
    }

    void Employee::setFirstName(const std::string &firstName) {
        m_firstName = firstName;
    }

    const std::string &Employee::getFirstName() const {
        return m_firstName;
    }

    void Employee::setLastName(const std::string &lastName) {
        m_lastName = lastName;
    }

    const std::string &Employee::getLastName() const {
        return m_lastName;
    }

    void Employee::setEmployeeNumber(int employeeNumber) {
        m_employeeNumber = employeeNumber;
    }

    int Employee::getEmployeeNumber() const {
        return m_employeeNumber;
    }

    void Employee::setSalary(int newSalary) {
        m_salary = newSalary;
    }

    int Employee::getSalary() const {
        return m_salary;
    }

    bool Employee::isHired() const {
        return m_hired;
    }
} // ERS