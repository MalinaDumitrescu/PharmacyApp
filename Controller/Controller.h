//
// Created by scoti on 14.04.2024.
//

//TODO Controller Layer: Implementing business logic and managing interactions between the presentation layer and the repository layer

#ifndef LAB4_OOP_CONTROLLER_H
#define LAB4_OOP_CONTROLLER_H

#include "C:\Users\Scoti\CLionProjects\Lab4_OOP\Domain\Medicine.h"
#include "C:\Users\Scoti\CLionProjects\Lab4_OOP\Repository\Repository.h"
#include <string>
#include <list>

class Controller {
private:
    Repository repo;  //composition---> controller contains repo object-->list(container)

public:
    Controller(const Repository& repository);

    void add(const Medicine& medicine);
    void remove(const Medicine& medicine);
    std::list<Medicine> getByName(const std::string& name);
    void modify(const Medicine& medicine);
    std::list<Medicine> sortByExpirationDate();
    std::list<Medicine> showInsufficientProducts(int quantity);
    std::list<Medicine> getAll();
    std::list<Medicine> getFirstTenItems();
    void showProducts(const std::list<Medicine>& products);
};

#endif //LAB4_OOP_CONTROLLER_H
