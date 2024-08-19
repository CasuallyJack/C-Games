/*
 * Years-And-Sweeps calculator by CasuallyJack, 2024
 *
 * Homestuck created by Andrew Hussie
 *
 * Calculator that converts Earth years to Alternian/Beforeus solar sweeps and vice-versa
 * using the two formulas below:
 *
 * sweeps = years / 2.17
 * years = sweeps * 2.17
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lib/hsconv/hsconv.h"

void clearTerm();
void flushStdin();

int main()
{

    /* Declare variable to store user response to question */
    char playerResponse[2];

    clearTerm();
    
    /* Display the first options screen. */
    printf("Years and Sweeps Calculator\n\n");
    printf("Which function would you like to use?\n\n");
    printf("(1) Years to Sweeps\n(2) Sweeps to Years\n\n");
    
    /* Read user input */
    fgets(playerResponse, sizeof playerResponse, stdin);
    
    if(strcmp(playerResponse, "1") == 0)
    {   
        /* Use with strtol */
        char *p;

        /* Variable to store response */
        char yearsInput[9];
        
        flushStdin();
        clearTerm(); 
        
        printf("Please input the years you'd like to convert (max 10 digits): ");
        
        fgets(yearsInput, sizeof yearsInput, stdin);
        
        /* Removing newline character to make life easier during output */
        yearsInput[strcspn(yearsInput, "\n")] = 0;

        /* Convert yearsInput into a long, and then a double */

        long convertYI = strtol(yearsInput, &p, 10);
        double doubleCYI = (double)convertYI; 

        double result = yearsToSweeps(doubleCYI);
        
        printf("\n%s is about %.2f sweeps!\n", yearsInput, result);   

    } else if (strcmp(playerResponse, "2") == 0) {
        
        /* Use with strtol */
        char *p;

        /* Variable to store response */
        char sweepsInput[9];

        flushStdin();
        clearTerm();
        
        printf("Please input the sweeps you'd like to convert (max 10 digits): ");

        fgets(sweepsInput, sizeof sweepsInput, stdin);

        /* Removing newline character to make life easier during output */
        sweepsInput[strcspn(sweepsInput, "\n")] = 0;

        /* Convert sweepsInput into a long, and then a double */
        
        long convertSI = strtol(sweepsInput, &p, 10);
        double doubleCSI = (double)convertSI;

        double result = sweepsToYears(doubleCSI);

        printf("\n%s is about %.2f years!\n", sweepsInput, result);

    } else {

        printf("Invalid response! Run again.\n");
        
        return 0;    
    }    
     
    return 0;
}    

void clearTerm()
{
    /* Clears terminal in a way that should work on all platforms. */
    printf("\e[H\e[2J\e[3J");

}

void flushStdin()
{
    /* Better portable solution for clearing stdin */
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

