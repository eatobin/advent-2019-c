#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fuelValue(int mass);
int recFuelValue(int mass);

int main(void) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    int mass;
    int tot_fuel = 0;
    int tot_fuel_rec = 0;
    size_t chars_read;

    fp = fopen("day01.txt", "r");

    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    while ((getline(&line, &len, fp)) != -1) {
        mass = (atoi(line));
        tot_fuel += fuelValue(mass);
    }

    printf("Part a: %i\n", tot_fuel);// 3337766

    rewind(fp);

    while ((getline(&line, &len, fp)) != -1) {
        mass = (atoi(line));
        tot_fuel_rec += recFuelValue(mass);
    }

    printf("Part b: %i\n\n", tot_fuel_rec);// 5003788

    free(line);
    fclose(fp);

    exit(EXIT_SUCCESS);
}

int fuelValue(int mass) {
    return (mass / 3) - 2;
}

int recFuelValue(int mass) {
    int sum = 0;
    int fuel = fuelValue(mass);

    while (fuel > 0) {
        sum += fuel;
        fuel = fuelValue(fuel);
    }

    return sum;
}
