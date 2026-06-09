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
    first->light = true;
    Car* current = first;
    int length = 1;

    while (true) {
        Car* walker = current;
        for (int i = 0; i < length; i++) {
            walker = walker->next;
            countOp++;
        }

        int checked = 0;
        while (!walker->light) {
            walker = walker->next;
            countOp++;
            checked++;
        }

        if (checked == length && walker == current) {
            return length;
        }

        walker->light = false;
        countOp++;

        for (int i = 0; i < length + checked; i++) {
            walker = walker->prev;
            countOp++;
        }

        current = walker;
        length++;
    }
}
