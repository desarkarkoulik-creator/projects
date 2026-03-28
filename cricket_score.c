#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store match details
struct Match {
    char team1[50];
    char team2[50];
    int runs1;
    int wickets1;
    float overs1;
    int runs2;
    int wickets2;
    float overs2;
    int totalOvers;
};

struct Match match;

// Function to initialize match details
void initializeMatch() {
    printf("Enter Team 1 Name: ");
    scanf("%s", match.team1);
    printf("Enter Team 2 Name: ");
    scanf("%s", match.team2);
    printf("Enter Total Overs for the match: ");
    scanf("%d", &match.totalOvers);
    
    match.runs1 = 0;
    match.wickets1 = 0;
    match.overs1 = 0.0;
    match.runs2 = 0;
    match.wickets2 = 0;
    match.overs2 = 0.0;
    
    printf("\nMatch initialized: %s vs %s (%d Overs)\n", match.team1, match.team2, match.totalOvers);
}

// Function to update the score
void updateScore() {
    int teamChoice;
    printf("\nUpdate Score for:\n");
    printf("1. %s\n", match.team1);
    printf("2. %s\n", match.team2);
    printf("Enter choice: ");
    scanf("%d", &teamChoice);

    int r, w;
    float o;
    printf("Enter new Runs: ");
    scanf("%d", &r);
    printf("Enter new Wickets: ");
    scanf("%d", &w);
    printf("Enter current Overs: ");
    scanf("%f", &o);

    if (teamChoice == 1) {
        match.runs1 = r;
        match.wickets1 = w;
        match.overs1 = o;
    } else if (teamChoice == 2) {
        match.runs2 = r;
        match.wickets2 = w;
        match.overs2 = o;
    } else {
        printf("Invalid choice!\n");
        return;
    }
    printf("Score updated successfully!\n");
}

// Function to print runs scored (Detailed per team)
void printRunsScored() {
    printf("\n--- Current Scorecard ---\n");
    printf("%s: %d/%d (%.1f Overs)\n", match.team1, match.runs1, match.wickets1, match.overs1);
    printf("%s: %d/%d (%.1f Overs)\n", match.team2, match.runs2, match.wickets2, match.overs2);
}

// Function to print detailed match statistics
void printMatchStats() {
    printf("\n--- Match Statistics ---\n");
    printf("Match: %s vs %s\n", match.team1, match.team2);
    printf("Total Overs: %d\n", match.totalOvers);
    
    float runRate1 = (match.overs1 > 0) ? (float)match.runs1 / match.overs1 : 0;
    float runRate2 = (match.overs2 > 0) ? (float)match.runs2 / match.overs2 : 0;

    printf("%s Statistics:\n", match.team1);
    printf("  Runs: %d, Wickets: %d, Overs: %.1f\n", match.runs1, match.wickets1, match.overs1);
    printf("  Run Rate: %.2f\n", runRate1);

    printf("%s Statistics:\n", match.team2);
    printf("  Runs: %d, Wickets: %d, Overs: %.1f\n", match.runs2, match.wickets2, match.overs2);
    printf("  Run Rate: %.2f\n", runRate2);
}

// Function to show the match result
void showResult() {
    printf("\n--- Match Result ---\n");
    if (match.runs1 > match.runs2) {
        printf("%s won by %d runs!\n", match.team1, match.runs1 - match.runs2);
    } else if (match.runs2 > match.runs1) {
        printf("%s won by %d runs!\n", match.team2, match.runs2 - match.runs1);
    } else {
        printf("The match is a Draw/Tie!\n");
    }
}

int main() {
    int choice;
    initializeMatch();

    while (1) {
        printf("\n--- Cricket Score Display ---\n");
        printf("1. Update Score\n");
        printf("2. Print Runs Scored\n");
        printf("3. Print Match Statistics\n");
        printf("4. Show Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: updateScore(); break;
            case 2: printRunsScored(); break;
            case 3: printMatchStats(); break;
            case 4: showResult(); break;
            case 5: exit(0);
            default: printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
