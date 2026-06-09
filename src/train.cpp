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

    if (!first->light) {
        first->light = true;
    }

    int length = 1;
    Car* current = first;

    while (true) {
        for (int i = 0; i < length; i++) {
            current = current->next;
            countOp++;
        }

        if (current->light) {
            current->light = false;

            for (int i = 0; i < length; i++) {
                current = current->prev;
                countOp++;
            }

            if (!first->light) {
                first->light = true;
                return length;
            } else {
                length++;
            }
        } else {
            length++;
        }
    }
}
