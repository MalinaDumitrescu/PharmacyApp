//
// Created by scoti on 14.04.2024.
//


#ifndef LAB4_OOP_TEST_H
#define LAB4_OOP_TEST_H

#include "C:\Users\Scoti\CLionProjects\Lab4_OOP\Repository\Repository.h"
#include "C:\Users\Scoti\CLionProjects\Lab4_OOP\Controller\Controller.h"


#include <cassert>

class Test {
public:
    void runAllTests();

private:
    void testAddMedicine();
    void testRemoveMedicine();
    void testModifyMedicine();
    void testGetByName();
    void testSortByExpirationDate();
    void testShowInsufficientProducts();
};

#endif //LAB4_OOP_TEST_H
