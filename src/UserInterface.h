//
// Created by ilya5 on 05.03.2024.
//

#ifndef UNTITLED_USERINTERFACE_H
#define UNTITLED_USERINTERFACE_H

#include <iostream>
#include <vector>
#include <memory>
#include "Employee.h"
#include "Database.h"

namespace ERS {

    class UserInterface {
    public:
        void displayMainMenu();
        void getMainMenuInput();

        void displayHire();
        void getHireInput();

        void displayFire();
        void getFireInput();

        void displayPromote();
        void getPromoteInput();

        void displayDemote();
        void getDemoteInput();

        void setDatabase(std::shared_ptr<Database> database);

    private:
        std::shared_ptr<Database> m_database;
    };

} // ERS

#endif //UNTITLED_USERINTERFACE_H
