// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Car* newCar = new Car;
    newCar->light = light;

    if (!first) {
        first = newCar;
        first->next = first;
        first->prev = first;
    } else {
        Car* last = first->prev;
        last->next = newCar;
        newCar->prev = last;
        newCar->next = first;
        first->prev = newCar;
    }
}

int Train::getOpCount() {
    return countOp;
}

int Train::getLength() {
    if (!first) return 0;
    
    countOp = 0;
    
    for (int n = 1; n <= 10000; n++) {
        first->light = true;
        Car* current = first;
        
        for (int i = 0; i < n; i++) {
            current = current->next;
            countOp++;
        }
        
        bool all_on = true;
        for (int i = 0; i < n; i++) {
            if (!current->light) {
                all_on = false;
                break;
            }
            current = current->next;
            countOp++;
        }
        
        if (all_on && current == first) {
            return n;
        }
    }
    
    return 0;
}
