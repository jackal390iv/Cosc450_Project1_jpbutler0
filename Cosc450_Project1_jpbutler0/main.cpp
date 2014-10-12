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
    printf("Please input the location of the data.txt file: ");
    //fgets(location, 256, stdin);
    strcpy(location, "/home/alfred/Desktop/data.txt");
    printf("You have entered: %s \n", location);
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
        ;

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
        int l = 0;
        while (l < size) {
            int tmp = array[l];
            fixed[l] = tmp;
            l++;
        }

        /* int i = 0;
         while (i < size) {
             printf("%d\n", fixed[i]);
             i++;
         }*/

        if (!(size % 10 == 0)) {
            printf("ERROR: number of integers are not a multiple of 10, please try again.\n");
            exit(0);
        } else {
            printf("PASS: number of integers is a multiple of 10.\n");
        }
        fclose(file);
        
        
        
        
        
    }

    return 0;
}

