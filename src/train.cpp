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
    Car* start = first;
    start->light = true;
    int length = 1;

    while (true) {
        Car* current = start;
        for (int i = 0; i < length; i++) {
            current = current->next;
            countOp++;
        }

        int steps = 0;
        while (!current->light) {
            current = current->next;
            countOp++;
            steps++;
        }

        if (steps == length && current == start) {
            break;
        }

        current->light = true;
        length++;

        for (int i = 0; i < length + steps; i++) {
            current = current->prev;
            countOp++;
        }
        start = current;
    }

    return length;
}
