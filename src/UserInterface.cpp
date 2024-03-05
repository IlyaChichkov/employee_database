//
// Created by ilya5 on 05.03.2024.
//

#include "UserInterface.h"

namespace ERS {
    using std::cout;
    using std::cin;
    using std::endl;

    void UserInterface::displayMainMenu() {
        cout << "     Employee Database     " << endl;
        cout << "---------------------------" << endl;
        cout << "1) Hire a new employee     " << endl;
        cout << "2) Fire an employee        " << endl;
        cout << "3) List all employees      " << endl;
        cout << "4) List current employees  " << endl;
        cout << "5) List former employees   " << endl;
        cout << "0) Quit                    " << endl;

        getMainMenuInput();
    }

    void UserInterface::getMainMenuInput() {
        bool isDone = false;
        while (!isDone)
        {
            int selectedOption = -1;
            cin >> selectedOption;
            switch(selectedOption)
            {
                case 0:
                    m_database
                    isDone = true;
                    break;
                case 1:
                    displayHire();
                    isDone = true;
                    break;
                case 2:
                    displayFire();
                    isDone = true;
                    break;
                case 3:
                    m_database->displayAll();
                    displayMainMenu();
                    break;
                case 4:
                    m_database->displayCurrent();
                    displayMainMenu();
                    break;
                case 5:
                    m_database->displayFormer();
                    displayMainMenu();
                    break;
                default:
                    std::cerr << "Unknown command." << endl;
                    break;
            }
        }
    }

    void UserInterface::displayHire() {
        cout << "           Hire            " << endl;
        cout << "---------------------------" << endl;

        getHireInput();
    }

    void UserInterface::getHireInput() {
        std::string firstName;
        std::string lastName;
        int step = 0;
        bool isDone = false;
        while (!isDone)
        {
            switch(step)
            {
                case 0:
                    cout << "Enter first name:" << endl;
                    cin >> firstName;
                    step = 1;
                    break;
                case 1:
                    cout << "Enter last name:" << endl;
                    cin >> lastName;

                    m_database->addEmployee(firstName, lastName);
                    step = 2;
                    break;
                case 2:
                    displayMainMenu();
                    isDone = true;
                    break;
                default:
                    std::cerr << "Unknown step." << endl;
                    break;
            }
        }
    }

    void UserInterface::displayFire() {
        cout << "           Fire            " << endl;
        cout << "---------------------------" << endl;

        getFireInput();
    }

    void UserInterface::getFireInput() {
        int employee_number = 0;
        char confirmInput = 'Y';
        int step = 0;
        bool isDone = false;
        while (!isDone)
        {
            switch(step)
            {
                case 0:
                    cout << "Enter employee number:" << endl;
                    cin >> employee_number;
                    step = 1;
                    break;
                case 1:
                    cout << "Confirm employee firing (Y/n):" << endl;
                    m_database->getEmployee(employee_number).display();
                    cin >> confirmInput;
                    step = 2;
                    break;
                case 2:
                    if(confirmInput == 'Y')
                    {
                        m_database->getEmployee(employee_number).fire();
                    }
                    displayMainMenu();
                    isDone = true;
                    break;
                default:
                    std::cerr << "Unknown step." << endl;
                    break;
            }
        }
    }

    void UserInterface::setDatabase(std::shared_ptr<Database> database) {
        m_database = database;
    }
} // ERS