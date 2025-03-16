//
// Created by scoti on 14.04.2024.
//

//TODO Repository Layer: Managing data access and object persistence

#include "Repository.h"

//function used for adding a new medicine to the repo
//first it checks to see if the medicine exists already
//if it does exist--> it raises the quantity---> if not---> the medicine is added
void Repository::add(const Medicine &medicine) {
    bool found = false;
    for (Medicine &i: container) {      //I iterate the list
        if (i.getName() == medicine.getName() && i.getOrigin() == medicine.getOrigin()) {
            i.setQuantity(i.getQuantity() + medicine.getQuantity());
            found = true;
            break;
        }
    }
    if (!found) {
        container.push_back(medicine);
    }
}

//function that deletes a medicine if it exists already
void Repository::del(const Medicine &medicine) {
    std::list<Medicine> newContainer;                          //I am putting here what I am not deleting
    for (Medicine &i: container) {
        if (!(i.getName() == medicine.getName() && i.getOrigin() == medicine.getOrigin())) {
            newContainer.push_back(i);
        }
    }
    container = newContainer;
}

//function that returns the content of the container
std::list<Medicine> Repository::getAll() const {
    return container;
}

//function that sets the content of the container
void Repository::setAll(const std::list<Medicine> &list) {
    container = list;
}