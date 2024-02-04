// C Claw!!

// ########
// |      |
// |      |
// | |oooo|
// ########
// ########


#include <stdio.h>     
#include <stdlib.h>     // Include for system()
#include <time.h>
#include <unistd.h>     // Include for sleep()   

void playMachine()
{
    // Declare rewards array and randomNum
    // rewards: 2D array of rewards in the machine
    // randomNum: Store random number output
   
    char rewards[5][14] = {"a Teddy Bear","a Bow","a Necklace","a Figurine", "Nothing"};
    int randomNum;

    // Generate random number between 0 and 4.
    // The number generated will then be used to determine what value of
    // rewards[] will output.
    srand(time(NULL));
    randomNum = rand() % 5;

    // Tell player what reward they got.
    printf("You won %s!\n", rewards[randomNum]);
}

int main()
{
    // Declare int variable for wether or not user would like to play
    int playerResponse;

    // Clear terminal 
    system("clear");

    // Greet player and ask if they want to play
    printf("Welcome to the C Claw! Would you like to play?\n");
    printf("\n########\n|      |\n|      |\n| |oooo|\n########\n########\n");
    printf("\n(1)YES, (2)NO\n");

    // Store answer in variable declared above
    scanf("%d", &playerResponse);

    // Use switch to determine what to run, based off the value of playerResponse
    switch (playerResponse) {
        
        // If playerResponse is 1, play game
        case 1:
            // Use "clear" Syscall to clear console, then call playMachine()
            system("clear");
            playMachine(); 

        // If playerResponse is 2, end program
        case 2:
            return 0;

        // If playerResponse is any value other than 1 or 2, notify user and reprompt
        default:
            // Tell user the number that had been submitted is not valid
            printf("\nInvalid response, please try again in 3 seconds.\n");
            // Use sleep() function to temporarily stall program for 3 seconds
            sleep(3);
            main();
    }
    return 0;
}