#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

double objectiveFunction(double x) {
    return -(x - 3) * (x - 3) + 9;
}

double getRandomNeighbor(double x, double step) {
    return x + ((rand() % 2001 - 1000) / 1000.0) * step;
}

double simulatedAnnealing(double start, double step, double temp, double coolingRate, int iterations) {
    double currentX = start;
    double currentValue = objectiveFunction(currentX);

    while (temp > 1) {
        for (int i = 0; i < iterations; i++) {
            double newX = getRandomNeighbor(currentX, step);
            double newValue = objectiveFunction(newX);

            if (newValue > currentValue || exp((newValue - currentValue) / temp) > ((double)rand() / RAND_MAX)) {
                currentX = newX;
                currentValue = newValue;
            }
        }
        temp *= coolingRate;
    }

    return currentX;
}

int main() {
    srand(time(0));

    double start = (rand() % 10) - 5;
    double step = 0.1;
    double temp = 1000;
    double coolingRate = 0.99;
    int iterations = 100;

    double maxX = simulatedAnnealing(start, step, temp, coolingRate, iterations);
    cout << "Optimal x: " << maxX << endl;
    cout << "Maximum value: " << objectiveFunction(maxX) << endl;

    return 0;
}
