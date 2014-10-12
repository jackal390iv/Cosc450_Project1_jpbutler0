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

    int val = 1;
    FILE *file = NULL;

    do {

        char location[256];
        printf("Please input the location of the data.txt file: ");
        fgets(location, 256, stdin);
        strcpy(location, "/home/alfred/Desktop/data.txt");
        printf("You have entered: %s \n", location);
        file = fopen(location, "r");

        if (file == NULL) {
            printf("ERROR: failed to find data.txt file, please try again \n");
        } else {
            printf("PASS: data.txt file has been found. \n");

            struct stat st;
            stat(location, &st);
            int size = st.st_size;
            char bef[size];
            
            int k=0;
            fscanf(file, "%d", &k);
            while(!feof(file)){
                printf("%d\n",k);
                fscanf(file, "%d", &k);
            }
            

        }
        break;
    } while (val = 1);

    return 0;
}

