//
// Created by scoti on 14.04.2024.
//

//TODO Domain Layer: Definition of entities and business objects

#ifndef LAB4_OOP_MEDICINE_H
#define LAB4_OOP_MEDICINE_H

#include <string>
#include <iostream>

class Medicine {
private:
    std::string name;
    std::string origin;
    std::string expirationDate;
    int quantity;
    int price;

public:
    //constructor
    Medicine(const std::string& name, const std::string& origin, const std::string& expirationDate, int quantity, int price);

    //getters
    std::string getName() const;
    int getPrice() const;
    std::string getOrigin() const;
    std::string getExpirationDate() const;
    int getQuantity() const;

    //setters
    void setPrice(int p);
    void setQuantity(int q);
    void setOrigin(const std::string& o);
    void setName(const std::string& n);
    void setExpirationDate(const std::string& e);

    //utility methods
    void showProduct() const;
    bool operator< (const Medicine& other) const;

    //comparison method---> static
    static bool compareByExp(const Medicine& medicine1, const Medicine& medicine2);
};

#endif //LAB4_OOP_MEDICINE_H
