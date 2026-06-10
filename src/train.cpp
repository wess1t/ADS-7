// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Car* newCar = new Car{light, nullptr, nullptr};
    if (!first) {
        first = newCar;
        newCar->next = newCar;
        newCar->prev = newCar;
    } else {
        Car* last = first->prev;
        last->next = newCar;
        newCar->prev = last;
        newCar->next = first;
        first->prev = newCar;
    }
}

int Train::getLength() {
    if (!first) return 0;
    bool originalLight = first->light;
    first->light = true;
    countOp = 0;
    int length = 0;
    Car* current = first;
    do {
        current = current->next;
        countOp++;
        length++;
    } while (current != first);
    current = first;
    bool allOn = true;
    for (int i = 0; i < length; i++) {
        if (!current->light) {
            allOn = false;
            break;
        }
        current = current->next;
    }
    if (allOn) {
        length = measureWithAllOn();
    } else {
        first->light = originalLight;
    }
    return length;
}

int Train::measureWithAllOn() {
    first->light = false;
    countOp++;
    int steps = 0;
    Car* current = first;
    do {
        current = current->next;
        steps++;
        countOp++;
    } while (current->light);
    current = first;
    for (int i = 0; i < steps; i++) {
        current->light = true;
        current = current->next;
    }
    return steps;
}

int Train::getOpCount() const {
    return countOp;
}
