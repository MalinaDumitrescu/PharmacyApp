//
// Created by scoti on 14.04.2024.
//

//TODO Presentation Layer: Interaction with the user, which can be a graphical interface or the console

#ifndef LAB4_OOP_USERINTERFACE_H
#define LAB4_OOP_USERINTERFACE_H

#include "C:\Users\Scoti\CLionProjects\Lab4_OOP\Controller\Controller.h"
#include "C:\Users\Scoti\CLionProjects\Lab4_OOP\Repository\Repository.h"

#include <string>

class UserInterface {
private:
    Controller controller;

    void addMedicine();
    void removeMedicine();
    void modifyMedicine();
    void listAllMedicines();
    void searchByName();
    void listInsufficientStock();
    void listByExpirationDate();
    void listFirstTen();

public:
    UserInterface(const Controller& controller);
    void displayMenu();
    void run();
};



#endif //LAB4_OOP_USERINTERFACE_H
