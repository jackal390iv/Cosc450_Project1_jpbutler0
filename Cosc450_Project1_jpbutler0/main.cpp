/* 
 * File:   main.cpp
 * Author: Jonathan Butler
 * Class: COSC 450- Project 1
 *
 */

#include <cstdlib>
#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    FILE *file = NULL;

    char location[256];
    //printf("Please input the location of the data.txt file: ");
    //fgets(location, 256, stdin);
    strcpy(location, "/home/alfred/Desktop/data.txt");
    //printf("You have entered: %s \n", location);
    file = fopen(location, "r");

    if (file == NULL) {
        printf("ERROR: failed to find data.txt file, please try again. \n");
        exit(0);
    } else {
        printf("PASS: data.txt file has been found. \n");

        struct stat st;
        stat(location, &st);
        int size = st.st_size;
        char bef[size];

        int array[size];

        int k = 0;
        while (!feof(file)) {
            fscanf(file, "%d", &array[k]);
            k++;
        }

        int length = 0;
        int count = 0;
        while ((count < 2)) {
            if (array[length] == 0) {
                count++;
            } else {
                count = 0;
            }
            length++;
        }

        size = length - 2;

        int fixed[size];
        for (k = 0; k < size; k++) {
            int tmp = array[k];
            fixed[k] = tmp;
        }

        /*for (k = 0; k < size; k++) {
            printf("%d\n", fixed[k]);
        }*/

        if (!(size % 10 == 0)) {
            printf("ERROR: number of integers are not a multiple of 10, please try again.\n");
            exit(0);
        } else {
            printf("PASS: number of integers is a multiple of 10.\n");
        }
        fclose(file);

        length = size / 2;
        int x = length / 5;
        int matrix_A[5][x];
        int matrix_B[x][5];

        int f;
        int tr = 0;
        for (f = 0; f < 5; f++) {
            for (k = 0; k < x; k++) {
                matrix_A[f][k] = fixed[tr];
                tr++;
            }
        }

        tr = length;
        for (f = 0; f < x; f++) {
            for (k = 0; k < 5; k++) {
                matrix_B[f][k] = fixed[tr];
                tr++;
            }
        }

        printf("\n MATRIX A \n");
        for (f = 0; f < 5; f++) {
            for (k = 0; k < x; k++) {
                printf("%d \t", matrix_A[f][k]);
            }
            printf("\n");
        }

        printf("\n MATRIX B \n");
        for (f = 0; f < x; f++) {
            for (k = 0; k < 5; k++) {
                printf("%d \t", matrix_B[f][k]);
            }
            printf("\n");
        }

    }

    return 0;
}

