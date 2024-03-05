//
// Created by ilya5 on 05.03.2024.
//

#ifndef UNTITLED_EMPLOYEE_H
#define UNTITLED_EMPLOYEE_H

#include <iostream>
#include <string>

namespace ERS::HR {

    const int c_DefaultStartingSalary = 30'000;
    const int c_DefaultRaiseAndDemeritAmount = 1'000;

    class Employee {
    public:
        Employee(const std::string& firstName,
                 const std::string& lastName);
        void promote(int raiseAmount = c_DefaultRaiseAndDemeritAmount);
        void demote(int demeritAmount = c_DefaultRaiseAndDemeritAmount);
        void hire();
        void fire();
        void display() const;

        void setFirstName(const std::string& firstName);
        const std::string& getFirstName() const;

        void setLastName(const std::string& lastName);
        const std::string& getLastName() const;

        void setEmployeeNumber(int employeeNumber);
        int getEmployeeNumber() const;

        void setSalary(int newSalary);
        int getSalary() const;

        bool isHired() const;

    private:
        std::string m_firstName;
        std::string m_lastName;
        int m_employeeNumber = -1;
        int m_salary = c_DefaultStartingSalary;
        bool m_hired = false;
    };

} // ERS

#endif //UNTITLED_EMPLOYEE_H
