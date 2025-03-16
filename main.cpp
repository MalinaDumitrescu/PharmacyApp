#include "C:\Users\Scoti\CLionProjects\Lab4_OOP\UI\UserInterface.h"
#include "C:\Users\Scoti\CLionProjects\Lab4_OOP\Test\Test.h"
#include "C:\Users\Scoti\CLionProjects\Lab4_OOP\Domain\Medicine.h"
#include "C:\Users\Scoti\CLionProjects\Lab4_OOP\Controller\Controller.h"
#include "C:\Users\Scoti\CLionProjects\Lab4_OOP\Repository\Repository.h"

//function to create sample data
void createSampleData(Repository& repo) {
    repo.add(Medicine("Paracetamol", "PharmaInc", "2024-12-31", 100, 5));
    repo.add(Medicine("Ibuprofen", "HealthCorp", "2025-05-20", 150, 8));
    repo.add(Medicine("Aspirin", "MedLife", "2023-11-15", 200, 3));
    repo.add(Medicine("Cough Syrup", "WellnessLab", "2024-10-10", 80, 10));
    repo.add(Medicine("Antibiotic", "BioPharm", "2024-06-30", 120, 15));
    repo.add(Medicine("Vitamin C", "NutriPlus", "2025-01-01", 300, 7));
    repo.add(Medicine("Antacid", "DigestiveCare", "2023-09-25", 90, 4));
    repo.add(Medicine("Insulin", "DiabetesCare", "2024-11-30", 50, 50));
    repo.add(Medicine("Pain Relief Gel", "PainAway", "2023-08-20", 60, 12));
    repo.add(Medicine("Allergy Pills", "AllerFree", "2024-03-15", 110, 9));
}

int main() {
    //run tests
    Test test;
    test.runAllTests();

    //create repository and populate with sample data
    Repository repo;
    createSampleData(repo);

    //create controller
    Controller controller(repo);

    //create user interface
    UserInterface ui(controller);

    //run the user interface
    ui.run();

    return 0;
}