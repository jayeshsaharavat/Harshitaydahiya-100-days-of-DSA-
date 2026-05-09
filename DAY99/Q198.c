
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int speed;
} Car;


int compare(const void *a, const void *b) {
    Car *carA = (Car *)a;
    Car *carB = (Car *)b;

    return carA->position - carB->position;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {

    
    Car cars[positionSize];

    for (int i = 0; i < positionSize; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    
    qsort(cars, positionSize, sizeof(Car), compare);

    int fleets = 0;

    
    double lastTime = 0.0;

    
    for (int i = positionSize - 1; i >= 0; i--) {

        double time = (double)(target - cars[i].position) / cars[i].speed;

        
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    return fleets;
}
