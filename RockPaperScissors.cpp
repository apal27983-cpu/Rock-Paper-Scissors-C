#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerChoice, computerChoice;
    int playerScore = 0, computerScore = 0;
    int menuChoice;

    char *choices[] = {"Rock", "Paper", "Scissors"};

    srand(time(NULL));

    while (1) {
        printf("\n===== ROCK PAPER SCISSORS =====\n");
        printf("1. Play Game\n");
        printf("2. Show Score\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menuChoice);

        switch (menuChoice) {

            case 1:
                printf("\n1. Rock\n2. Paper\n3. Scissors\n");
                printf("Enter your choice: ");
                scanf("%d", &playerChoice);

                if (playerChoice < 1 || playerChoice > 3) {
                    printf("Invalid choice!\n");
                    break;
                }

                computerChoice = (rand() % 3) + 1;

                printf("You chose: %s\n", choices[playerChoice - 1]);
                printf("Computer chose: %s\n", choices[computerChoice - 1]);

                if (playerChoice == computerChoice) {
                    printf("It's a Draw!\n");
                }
                else if ((playerChoice == 1 && computerChoice == 3) ||
                         (playerChoice == 2 && computerChoice == 1) ||
                         (playerChoice == 3 && computerChoice == 2)) {
                    printf("You Win this round!\n");
                    playerScore++;
                }
                else {
                    printf("Computer Wins this round!\n");
                    computerScore++;
                }
                break;

            case 2:
                printf("\n--- SCORE BOARD ---\n");
                printf("Player Score: %d\n", playerScore);
                printf("Computer Score: %d\n", computerScore);
                break;

            case 3:
                printf("\nFinal Score:\n");
                printf("Player: %d | Computer: %d\n", playerScore, computerScore);
                printf("Exiting Game... Thank You!\n");
                return 0;

            default:
                printf("Invalid Menu Choice!\n");
        }
    }

    return 0;
}
