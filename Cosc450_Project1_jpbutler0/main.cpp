/* 
 * File:   main.cpp
 * Author: Jonathan Butler
 * Class: COSC 450- Project 1
 *
 */

#include <cstdlib>
#include<stdio.h>
#include<string.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int val=1;
    FILE *file=NULL;
    
    do{
        
        char location[256];
        printf("Please input the location of the data.txt file: ");
        fgets(location, 256, stdin);
        strcpy(location,"/home/alfred/Desktop/data.txt");        
        printf("You have entered: %s \n",location);        
        file=fopen(location,"r");
               
        if(file==NULL){
            printf("ERROR: failed to find data.txt file, please try again");
        }
        else{
            printf("PASS: data.txt file has been found.");
            
            
            val=-1;
        }        
        break;        
    }while(val=1);
    
    return 0;
}

