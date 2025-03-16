//
// Created by scoti on 14.04.2024.
//

//TODO Presentation Layer: Interaction with the user, which can be a graphical interface or the console

#include "UserInterface.h"
#include <string>

//constructor
UserInterface::UserInterface(const Controller& ctrl) : controller(ctrl) {}

//method to display the menu
void UserInterface::displayMenu() {
    std::cout << "Pharmacy Management System\n";
    std::cout << "1. Add Medicine\n";
    std::cout << "2. Remove Medicine\n";
    std::cout << "3. Modify Medicine\n";
    std::cout << "4. List All Medicines\n";
    std::cout << "5. Search Medicine by Name\n";
    std::cout << "6. List Medicines with Insufficient Stock\n";
    std::cout << "7. List Medicines by Expiration Date\n";
    std::cout << "8. List First 10 Medicines\n";
    std::cout << "0. Exit\n";
}

//method to run the interface
void UserInterface::run() {
    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                removeMedicine();
                break;
            case 3:
                modifyMedicine();
                break;
            case 4:
                listAllMedicines();
                break;
            case 5:
                searchByName();
                break;
            case 6:
                listInsufficientStock();
                break;
            case 7:
                listByExpirationDate();
                break;
            case 8:
                listFirstTen();
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

//method to add a new medicine
void UserInterface::addMedicine() {
    std::string name, origin, expirationDate;
    int quantity, price;
    std::cout << "Enter medicine name: ";
    std::getline(std::cin, name);
    std::cout << "Enter medicine origin: ";
    std::getline(std::cin, origin);
    std::cout << "Enter expiration date: ";
    std::getline(std::cin, expirationDate);
    std::cout << "Enter quantity: ";
    std::cin >> quantity;
    std::cout << "Enter price: ";
    std::cin >> price;
    Medicine medicine(name, origin, expirationDate, quantity, price);
    controller.add(medicine);
    std::cout << "Medicine added successfully.\n";
}

//method to remove a medicine
void UserInterface::removeMedicine() {
    std::string name, origin;
    std::cout << "Enter medicine name to remove: ";
    std::getline(std::cin, name);
    std::cout << "Enter medicine origin to remove: ";
    std::getline(std::cin, origin);
    Medicine medicine(name, origin, "", 0, 0);  //expiration date quantity price are irrelevant for removal!!!!!
    controller.remove(medicine);
    std::cout << "Medicine removed successfully.\n";
}

//method to modify a medicine
void UserInterface::modifyMedicine() {
    std::string name, origin, expirationDate;
    int quantity, price;
    std::cout << "Enter medicine name to modify: ";
    std::getline(std::cin, name);
    std::cout << "Enter medicine origin to modify: ";
    std::getline(std::cin, origin);
    std::cout << "Enter new expiration date: ";
    std::getline(std::cin, expirationDate);
    std::cout << "Enter new quantity: ";
    std::cin >> quantity;
    std::cout << "Enter new price: ";
    std::cin >> price;
    Medicine medicine(name, origin, expirationDate, quantity, price);
    controller.modify(medicine);
    std::cout << "Medicine modified successfully.\n";
}

//method to list all medicines
void UserInterface::listAllMedicines() {
    std::list<Medicine> medicines = controller.getAll();
    controller.showProducts(medicines);
}

//method to search for medicines by name
void UserInterface::searchByName() {
    std::string name;
    std::cout << "Enter medicine name or origin to search: ";
    std::getline(std::cin, name);
    std::list<Medicine> medicines = controller.getByName(name);
    controller.showProducts(medicines);
}

//method to list medicines with insufficient stock
void UserInterface::listInsufficientStock() {
    int quantity;
    std::cout << "Enter the threshold quantity: ";
    std::cin >> quantity;
    std::list<Medicine> medicines = controller.showInsufficientProducts(quantity);
    controller.showProducts(medicines);
}

//method to list medicines by expiration date
void UserInterface::listByExpirationDate() {
    std::list<Medicine> medicines = controller.sortByExpirationDate();
    controller.showProducts(medicines);
}

//method to list the first 10 medicines
void UserInterface::listFirstTen() {
    std::list<Medicine> medicines = controller.getFirstTenItems();
    controller.showProducts(medicines);
}