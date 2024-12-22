#include <stdio.h>
#include "stats.h"

#define SIZE 40

unsigned char test[SIZE] = {34, 201, 190, 154, 8, 194, 2, 6, 114, 88, 45, 76, 123, 87, 25, 23, 200, 122, 150, 90,
                            92, 87, 177, 244, 201, 6, 12, 60, 8, 2, 5, 67, 7, 87, 250, 230, 99, 3, 100, 90};

int find_mean(unsigned char *array, unsigned int size) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i < size; i++) {
        sum += array[i];
    }
}

int find_median(unsigned char *array, unsigned int size) {
    sort_array(array, size); 
    if (size % 2 == 0) {
        return (array[size / 2 - 1] + array[size / 2]) / 2;  
    } else {
        return array[size / 2]; 
    }
}

int find_maximum(unsigned char *array, unsigned int size) {
    int max = array[0];
    for (unsigned int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int find_minimum(unsigned char *array, unsigned int size) {
    int min = array[0];
    for (unsigned int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

void sort_array(unsigned char *array, unsigned int size) {
    for (unsigned int i = 0; i < size - 1; i++) {
        for (unsigned int j = i + 1; j < size; j++) {
            if (array[i] < array[j]) { 
                unsigned char temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void print_statistics() {
    printf("Mean: %d\n", find_mean(test, SIZE));
    printf("Median: %d\n", find_median(test, SIZE));
    printf("Maximum: %d\n", find_maximum(test, SIZE));
    printf("Minimum: %d\n", find_minimum(test, SIZE));
}

int main() {
    sort_array(test, SIZE); 
    print_statistics();      
    return 0;
}
