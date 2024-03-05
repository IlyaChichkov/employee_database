#include <iostream>
#include <vector>
#include <memory>
#include "src/Employee.h"
#include "src/Database.h"
#include "src/UserInterface.h"

using namespace std;

int main() {
    ERS::Database database;
    ERS::UserInterface userInterface;
    userInterface.setDatabase(std::make_shared<ERS::Database>(database));

    userInterface.displayMainMenu();
    userInterface.getMainMenuInput();

    return 0;
}
