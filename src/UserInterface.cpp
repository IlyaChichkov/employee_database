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
        cout << "3) Promote an employee     " << endl;
        cout << "4) Demote an employee      " << endl;
        cout << "5) List all employees      " << endl;
        cout << "6) List current employees  " << endl;
        cout << "7) List former employees   " << endl;
        cout << "0) Quit                    " << endl;
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
                    isDone = true;
                    break;
                case 1:
                    displayHire();
                    displayMainMenu();
                    break;
                case 2:
                    displayFire();
                    displayMainMenu();
                    break;
                case 3:
                    displayPromote();
                    displayMainMenu();
                    break;
                case 4:
                    displayDemote();
                    displayMainMenu();
                    break;
                case 5:
                    m_database->displayAll();
                    displayMainMenu();
                    break;
                case 6:
                    m_database->displayCurrent();
                    displayMainMenu();
                    break;
                case 7:
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

    void UserInterface::displayPromote() {
        cout << "         Promote           " << endl;
        cout << "---------------------------" << endl;

        getPromoteInput();
    }

    void UserInterface::getPromoteInput() {
        int employee_number = 0;
        int rise_amount = 0;
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
                    cout << "Enter raise amount:" << endl;
                    cin >> rise_amount;
                    step = 2;
                    break;
                case 2:
                    cout << "Confirm employee promote (Y/n):" << endl;
                    m_database->getEmployee(employee_number).display();
                    cin >> confirmInput;
                    step = 3;
                    break;
                case 3:
                    if(confirmInput == 'Y')
                    {
                        m_database->getEmployee(employee_number).promote(rise_amount);
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

    void UserInterface::displayDemote() {
        cout << "          Demote           " << endl;
        cout << "---------------------------" << endl;

        getDemoteInput();
    }

    void UserInterface::getDemoteInput() {
        int employee_number = 0;
        int demote_amount = 0;
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
                    cout << "Enter demote amount:" << endl;
                    cin >> demote_amount;
                    step = 2;
                    break;
                case 2:
                    cout << "Confirm employee demote (Y/n):" << endl;
                    m_database->getEmployee(employee_number).display();
                    cin >> confirmInput;
                    step = 3;
                    break;
                case 3:
                    if(confirmInput == 'Y')
                    {
                        m_database->getEmployee(employee_number).demote(demote_amount);
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
} // ERS