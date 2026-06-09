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
    int n = 0;
    Car* current = first;

    while (true) {
        current->light = true;
        Car* walker = current;
        n++;

        for (int i = 0; i < n; i++) {
            walker = walker->next;
            countOp++;
        }

        if (walker == current) {
            return n;
        }

        for (int i = 0; i < n; i++) {
            walker = walker->prev;
            countOp++;
        }
        current = walker;
    }
}
