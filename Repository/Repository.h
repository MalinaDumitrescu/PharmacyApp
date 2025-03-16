//
// Created by scoti on 14.04.2024.
//

//TODO Repository Layer: Managing data access and object persistence

#ifndef LAB4_OOP_REPOSITORY_H
#define LAB4_OOP_REPOSITORY_H

#include <iostream>
#include <list>
#include "C:\Users\Scoti\CLionProjects\Lab4_OOP\Domain\Medicine.h"

class Repository {
private:
    std::list<Medicine> container;

public:
    void add(const Medicine& medicine);
    void del(const Medicine& medicine);
    std::list<Medicine> getAll() const;
    void setAll(const std::list<Medicine>& list);
};

#endif //LAB4_OOP_REPOSITORY_H
