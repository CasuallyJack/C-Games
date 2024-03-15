// C Slot Machine!!

// ___ ___ ___
// |o| |o| |o|
// --- --- --- 
//

// C-Game by CasuallyJack, 2024

#include <stdio.h>
#include <stdlib.h>     // Include for system().
#include <unistd.h>     // include for sleep().
#include <time.h>

void playMachine()
{
    // Declare rewards array and randomNum. This will allow us to generate
    // A random number that determines the value of the reward.

    char rewards[5][7] = {"Seven","Pear","Bar","Cherry","Lemon"};
    int randomNum;

    // By calling srand here, it ensures the value will always be different.
    srand(time(0));

    // Use a for loop because our machine has 3 slots

    for(int i=0; i < 3; i++)
    {
        // Generate number in here so it's random every spin
        randomNum = rand() % 5;

        printf("Slot %d: You got a %s!\n", i+1, rewards[randomNum]);
    }
}

int main()
{
    // Create variable to store user input.
    int playerResponse;

    // Clear terminal.
    system("clear");

    // Greet player and give them a choice of wether or not they'd like to play.
    printf("Welcome to the C Slot Machine!\n");
    printf("___ ___ ___\n|o| |o| |o|-o\n--- --- ---\n");
    printf("Would you like to play?\n(1) YES, (2) NO\n");

    // Store user input in playerResponse variable.
    scanf("%d", &playerResponse);

    // Use switch to determine what to run, based off of playerResponsive variable.
    switch(playerResponse)
    {
        case 1:
            // Clear the screen
            system("clear");
            playMachine();
        
        case 2:
            return 0;
        
        default:
            // Tell user the number that had been submitted is not valid
            printf("\nInvalid response, please try again in 3 seconds.\n");
            // Use sleep() function to temporarily stall program for 3 seconds
            sleep(3);
            main();

    }

    return 0;
}
