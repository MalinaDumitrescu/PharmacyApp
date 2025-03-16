//
// Created by scoti on 14.04.2024.
//

//TODO Domain Layer: Definition of entities and business objects

#include "Medicine.h"

//constructor
Medicine::Medicine(const std::string& name, const std::string& origin, const std::string& expirationDate, int quantity, int price) {
    this->name = name;
    this->origin = origin;
    this->expirationDate = expirationDate;
    this->quantity = quantity;
    this->price = price;
}

//getter for name
std::string Medicine::getName() const {
    return name;
}

//getter for origin
std::string Medicine::getOrigin() const {
    return origin;
}

//getter for price
int Medicine::getPrice() const {
    return price;
}

//getter for quantity
int Medicine::getQuantity() const {
    return quantity;
}

//getter for expiration date
std::string Medicine::getExpirationDate() const {
    return expirationDate;
}

//setter for quantity
void Medicine::setQuantity(int q) {
    quantity = q;
}

//setter for price
void Medicine::setPrice(int p) {
    price = p;
}

//setter for expiration date
void Medicine::setExpirationDate(const std::string& e) {
    expirationDate = e;
}

//setter for name
void Medicine::setName(const std::string& n) {
    name = n;
}

//setter for origin
void Medicine::setOrigin(const std::string& o) {
    origin = o;
}

//function that shows the product and his info
void Medicine::showProduct() const {
    std::cout << "Name: " << name << ", Origin: " << origin << ", Expiration Date: " << expirationDate << ", Quantity: " << quantity << ", Price: " << price << std::endl;
}

//function used for the comparison of names
bool Medicine::operator<(const Medicine& other) const {
    return this->getName() < other.getName();
}

//function used for the comparison of expiration dates
bool Medicine::compareByExp(const Medicine& medicine1, const Medicine& medicine2) {
    return medicine1.getExpirationDate() < medicine2.getExpirationDate();
}