//
// Created by scoti on 14.04.2024.
//

#include "Test.h"
#include <iostream>

void Test::runAllTests() {
    testAddMedicine();
    testRemoveMedicine();
    testModifyMedicine();
    testGetByName();
    testSortByExpirationDate();
    testShowInsufficientProducts();
    std::cout << "All tests passed successfully!\n";
}

void Test::testAddMedicine() {
    Repository repo;
    Controller ctrl(repo);
    Medicine med1("Aspirin", "MedLife", "2023-11-15", 200, 3);
    Medicine med2("Paracetamol", "PharmaInc", "2024-12-31", 100, 5);

    ctrl.add(med1);
    ctrl.add(med2);

    std::list<Medicine> meds = ctrl.getAll();
    assert(meds.size() == 2);
    assert(meds.front().getName() == "Aspirin");
    assert(meds.back().getName() == "Paracetamol");
}

void Test::testRemoveMedicine() {
    Repository repo;
    Controller ctrl(repo);
    Medicine med("Aspirin", "MedLife", "2023-11-15", 200, 3);

    ctrl.add(med);
    ctrl.remove(med);

    std::list<Medicine> meds = ctrl.getAll();
    assert(meds.size() == 0);
}

void Test::testModifyMedicine() {
    Repository repo;
    Controller ctrl(repo);
    Medicine med("Aspirin", "MedLife", "2023-11-15", 200, 3);
    ctrl.add(med);

    Medicine updatedMed("Aspirin", "MedLife", "2024-11-15", 300, 4);
    ctrl.modify(updatedMed);

    std::list<Medicine> meds = ctrl.getAll();
    assert(meds.size() == 1);
    assert(meds.front().getQuantity() == 300);
    assert(meds.front().getPrice() == 4);
    assert(meds.front().getExpirationDate() == "2024-11-15");
}

void Test::testGetByName() {
    Repository repo;
    Controller ctrl(repo);
    Medicine med1("Aspirin", "MedLife", "2023-11-15", 200, 3);
    Medicine med2("Paracetamol", "PharmaInc", "2024-12-31", 100, 5);

    ctrl.add(med1);
    ctrl.add(med2);

    std::list<Medicine> meds = ctrl.getByName("Aspirin");
    assert(meds.size() == 1);
    assert(meds.front().getName() == "Aspirin");
}

void Test::testSortByExpirationDate() {
    Repository repo;
    Controller ctrl(repo);
    Medicine med1("Aspirin", "MedLife", "2023-11-15", 200, 3);
    Medicine med2("Paracetamol", "PharmaInc", "2024-12-31", 100, 5);

    ctrl.add(med1);
    ctrl.add(med2);

    std::list<Medicine> meds = ctrl.sortByExpirationDate();
    assert(meds.size() == 2);
    assert(meds.front().getExpirationDate() == "2023-11-15");
    assert(meds.back().getExpirationDate() == "2024-12-31");
}

void Test::testShowInsufficientProducts() {
    Repository repo;
    Controller ctrl(repo);
    Medicine med1("Aspirin", "MedLife", "2023-11-15", 200, 3);
    Medicine med2("Paracetamol", "PharmaInc", "2024-12-31", 10, 5);

    ctrl.add(med1);
    ctrl.add(med2);

    std::list<Medicine> meds = ctrl.showInsufficientProducts(50);
    assert(meds.size() == 1);
    assert(meds.front().getName() == "Paracetamol");
}