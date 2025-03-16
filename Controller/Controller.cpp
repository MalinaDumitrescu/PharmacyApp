//
// Created by scoti on 14.04.2024.
//

//TODO Controller Layer: Implementing business logic and managing interactions between the presentation layer and the repository layer

#include "Controller.h"

#include <algorithm>
#include <iostream>

Controller::Controller(const Repository& repository) : repo(repository) {}  //like this because shit repo does not have a default constructor

//function for adding a medicine
void Controller::add(const Medicine& medicine) {
    repo.add(medicine);
}

//function for removing a medicine
void Controller::remove(const Medicine& medicine) {
    repo.del(medicine);
}

//function for searching for a medicine with a letter sequence
std::list<Medicine> Controller::getByName(const std::string& name) {
    std::list<Medicine> result;
    std::list<Medicine> repository = repo.getAll();
    if (name == "~") {     //shortcut return the entire list
        return repository;
    }
    for (const Medicine& i : repository) {  //two checks
        if (i.getName().find(name) != std::string::npos || i.getOrigin().find(name) != std::string::npos) {
            result.push_back(i);
        }
    }
    return result;
}

//function for sorting the medicine by their expiration date
std::list<Medicine> Controller::sortByExpirationDate() {
    std::list<Medicine> repository = repo.getAll();
    repository.sort(Medicine::compareByExp);
    return repository;
}

//function which compares the quantity of all products with the one given and returns the ones that are not enought
std::list<Medicine> Controller::showInsufficientProducts(int quantity) {
    std::list<Medicine> result;
    std::list<Medicine> repository = repo.getAll();
    for (const Medicine& i : repository) {
        if (i.getQuantity() < quantity) {
            result.push_back(i);
        }
    }
    return result;
}

//function that deals with the modification of a medicine
void Controller::modify(const Medicine& medicine) {
    std::list<Medicine> repository = repo.getAll();
    for (Medicine& i : repository) {
        if (i.getName() == medicine.getName() && i.getOrigin() == medicine.getOrigin()) {
            i = medicine;  //add methode from repo.cpp
        }
    }
    repo.setAll(repository);
}

//function that returns all medicine
std::list<Medicine> Controller::getAll() {
    return repo.getAll();
}

//function that returns the first 10 medicines---> for menu
std::list<Medicine> Controller::getFirstTenItems() {
    std::list<Medicine> repository = repo.getAll();
    std::list<Medicine> firstTen;
    int count = 0;
    for (const Medicine& i : repository) {
        if (count >= 10) {
            break;
        }
        firstTen.push_back(i);
        count++;
    }
    return firstTen;
}

//function to show products
void Controller::showProducts(const std::list<Medicine>& products) {
    for (const Medicine& i : products) {
        i.showProduct();
        std::cout << "\n";
    }
}