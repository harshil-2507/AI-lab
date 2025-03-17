#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

double objectiveFunction(double x) {
    return -(x - 3) * (x - 3) + 9;
}

double hillClimb(double start, double step, int maxIterations) {
    double currentX = start;
    double currentValue = objectiveFunction(currentX);

    for (int i = 0; i < maxIterations; i++) {
        double newX1 = currentX + step;
        double newX2 = currentX - step;
        double newValue1 = objectiveFunction(newX1);
        double newValue2 = objectiveFunction(newX2);

        if (newValue1 > currentValue) {
            currentX = newX1;
            currentValue = newValue1;
        } 
        else if (newValue2 > currentValue) {
            currentX = newX2;
            currentValue = newValue2;
        } 
        else {
            break;
        }
    }

    return currentX;
}

int main() {
    srand(time(0));
    double start = (rand() % 10) - 5; 
    double step = 0.1;  
    int maxIterations = 100;  
    double maxX = hillClimb(start, step, maxIterations);
    cout << "Optimal x: " << maxX << endl;
    cout << "Maximum value: " << objectiveFunction(maxX) << endl;

    return 0;
}
