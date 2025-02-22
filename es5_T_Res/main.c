#include <stdio.h>
#include <math.h>

#define R0 10000   // Resistenza a 25°C (10kOhm)
#define BETA 3435  // Beta per il termistore
#define T0 298.15  // Temperatura di riferimento (25°C in Kelvin)

double calculateResistance(double temperatureCelsius) {
    double temperatureKelvin = temperatureCelsius + 273.15;
    return R0 * exp(BETA * (1.0 / temperatureKelvin - 1.0 / T0));
}

int main() {
    printf("Temperatura (°C)  Resistenza (Ohm)\n");

    for (int temp = -40; temp <= 100; temp += 1) {
        double resistance = calculateResistance(temp);
        printf("%+4d               %.2f\n", temp, resistance);
    }

    return 0;
}
