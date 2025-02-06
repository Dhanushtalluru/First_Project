#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main() {
    char options[3][10] = {"rock", "paper", "scissors"};
    char user_choice[10];
    int user_score = 0, computer_score = 0;
    int computer_choice;

   
    srand(time(0));

    while (1) {
        printf("Choose Rock, Paper, or Scissors (or type 'exit' to quit): ");
        scanf("%s", user_choice);

       
        for (int i = 0; user_choice[i]; i++) {
            user_choice[i] = tolower(user_choice[i]);
        }

        if (strcmp(user_choice, "exit") == 0) {
            break;
        }

        
        if (strcmp(user_choice, "rock") != 0 && strcmp(user_choice, "paper") != 0 && strcmp(user_choice, "scissors") != 0) {
            printf("Invalid choice. Please choose Rock, Paper, or Scissors.\n");
            continue;
        }

        
        computer_choice = rand() % 3;

        printf("Your choice: %s\n", user_choice);
        printf("Computer's choice: %s\n", options[computer_choice]);

    
        if (strcmp(user_choice, options[computer_choice]) == 0) {
            printf("It's a tie!\n");
        } else if ((strcmp(user_choice, "rock") == 0 && strcmp(options[computer_choice], "scissors") == 0) ||
                   (strcmp(user_choice, "paper") == 0 && strcmp(options[computer_choice], "rock") == 0) ||
                   (strcmp(user_choice, "scissors") == 0 && strcmp(options[computer_choice], "paper") == 0)) {
            printf("You win!\n");
            user_score++;
        } else {
            printf("Computer wins!\n");
            computer_score++;
        }

       
        printf("Your score: %d\n", user_score);
        printf("Computer's score: %d\n\n", computer_score);
    }

  
    printf("Final score:\n");
    printf("Your score: %d\n", user_score);
    printf("Computer's score: %d\n", computer_score);

    if (computer_score > user_score) {
        printf("Computer wins the game!\n");
    } else if (computer_score < user_score) {
        printf("You win the game!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}


