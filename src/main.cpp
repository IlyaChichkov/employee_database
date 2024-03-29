#include <memory>
#include "Database.h"
#include "UserInterface.h"

using namespace std;

int main() {
    ERS::Database database;
    ERS::UserInterface userInterface;
    userInterface.setDatabase(std::make_shared<ERS::Database>(database));

    userInterface.displayMainMenu();
    userInterface.getMainMenuInput();

    return 0;
}
