// C FISHING!!!
//   /|
//  / |
// / ><>

// A player can catch 5 different kinds of fish, varying between about 0.5-10 pounds!
// C-Game by CasuallyJack, 2024

#include <stdio.h>
#include <stdlib.h> // Include for strtol()
#include <unistd.h> // Include for sleep()
#include <time.h>   // Include for srand input
#include <string.h> // Include for strcmp()

void clearTerm()
{
    // Clears terminal. Should work on all platforms!!!

    printf("\e[H\e[2J\e[3J");
}

void flushStdin()
{
    // More portable solution for clearing stdin
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}


void goFish()
{
    // Go fishing!!!
     
    const char fish[5][8] = {"Tuna","Trout","Perch","Salmon","Sunfish"};
    int fishNumber;

    float fishWeight;

    // Ensure value is always different for rand.
    srand(time(0));
       
    fishNumber = rand() % 5;

    // Calculare fishWeight.
    float diff = 10 - 0.5;
    fishWeight = (diff+1)/RAND_MAX * rand() + 0.5;

    printf("You caught a %s that weighs %.2f Pounds!\n", fish[fishNumber], fishWeight);

}

int main()
{   
    // Declare variable to store user response to initial question.
    char playerResponse[2];
    
    // Variables to be used with strtol.
    char *strptr;
    long convertPR;

    // Clear the terminal.
    clearTerm();

    // Display the title screen.
    printf("    /|\n   / |\n  / ><>\n");
    printf("Welcome to C Fishing!\nWould you like to play?\n");

    // Choose your own adventure
    printf("YES (1) , NO (2)\n");
    
    // Scanf is unsecure so switch to fgets().
    fgets(playerResponse, 2, stdin);
    
    // Convert playerResponse into long.
    convertPR = strtol(playerResponse, &strptr, 10); 
    
    // Decide path based on input.
    if (convertPR == 1)
        goFish();
    else if (convertPR == 2 || strcmp(playerResponse, "\x0D"))
        return 0;
    else 
    {
        printf("\nInvalid Response, please try again in 3 seconds.\n");
        
        // Flush stdin to fix issue of delayed sleep.
        flushStdin();

        sleep(3);
        main();
    }

}
