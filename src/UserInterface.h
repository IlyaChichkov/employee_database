//
// Created by ilya5 on 05.03.2024.
//

#ifndef UNTITLED_USERINTERFACE_H
#define UNTITLED_USERINTERFACE_H

#include <iostream>
#include <vector>
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
    };

} // ERS

#endif //UNTITLED_USERINTERFACE_H
