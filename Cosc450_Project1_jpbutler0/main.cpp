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
        //printf("PASS: data.txt file has been found. \n");

        struct stat st;
        stat(location, &st);
        long int size = st.st_size;
        char bef[size];

        long int array[size];

        long int k = 0;
        while (!feof(file)) {
            fscanf(file, "%d", &array[k]);
            k++;
        }

        long int length = 0;
        long int count = 0;
        while ((count < 2)) {
            if (array[length] == 0) {
                count++;
            } else {
                count = 0;
            }
            length++;
        }

        size = length - 2;

        long int fixed[size];
        for (k = 0; k < size; k++) {
            int tmp = array[k];
            fixed[k] = tmp;
        }

        if (!(size % 10 == 0)) {
            printf("ERROR: number of integers are not a multiple of 10, please try again.\n");
            exit(0);
        } else {
            //printf("PASS: number of integers is a multiple of 10.\n");
        }
        fclose(file);

        length = size / 2;
        long int x = length / 5;
        long int matrix_A[5][x];
        long int matrix_B[x][5];

        long int f;
        long int tr = 0;
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

        FILE *output;
        output = fopen("/home/alfred/Desktop/output.txt", "w");

        fprintf(output, "\n MATRIX A \n");
        for (f = 0; f < 5; f++) {
            for (k = 0; k < x; k++) {
                fprintf(output, "%d \t", matrix_A[f][k]);
            }
            fprintf(output, "\n");
        }

        fprintf(output, "\n MATRIX B \n");
        for (f = 0; f < x; f++) {
            for (k = 0; k < 5; k++) {
                fprintf(output, "%d \t", matrix_B[f][k]);
            }
            fprintf(output, "\n");
        }

        long int matrix_C[5][5];

        long int total = 0;
        long int fix[25];
        long int arr[x];
        long int q;
        count = 0;
        for (tr = 0; tr < 25; tr++) {
            fix[tr] = 0;
        }
        for (q = 0; q < x; q++) {
            for (f = 0; f < 5; f++) {
                for (k = 0; k < x; k++) {
                    arr[k] = matrix_A[q][k] * matrix_B[k][f];
                }
                for (tr = 0; tr < x; tr++) {
                    //printf("%d, ", arr[tr]);
                    fix[count] = fix[count] + arr[tr];
                }
                //printf("\n %d \t", f);
                //printf(" %d \n", fix[count]);
                count++;
            }
        }

        tr = 0;
        for (f = 0; f < 5; f++) {
            for (k = 0; k < 5; k++) {
                matrix_C[k][f] = fix[tr];
                tr++;
            }
        }

        fprintf(output, "\n MATRIX C (MATRIX A * MATRIX B) \n");
        for (f = 0; f < 5; f++) {
            for (k = 0; k < 5; k++) {
                fprintf(output, "%d \t", matrix_C[k][f]);
            }
            fprintf(output, "\n");
        }
        fclose(output);
    }

    return 0;
}

