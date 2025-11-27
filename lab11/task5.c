#include <stdio.h>
#include <string.h>

typedef struct {
    char teamName[50];
    int scores[10];
    int roundCount;
} Team;

void task5Menu();
void addTeam(Team teams[], int *count);
void addScore(Team teams[], int count);
int calculateTeamScoreRecursive(int scores[], int index, int roundCount);
void displayTeamScores(Team teams[], int count);
void filterTeamsByScore(Team teams[], int count, int threshold);

int main() {
    task5Menu();
    return 0;
}

void task5Menu() {
    Team teams[50];
    int count = 0;
    int choice;

    while(1) {
        printf("\n--- TASK 5: QUIZ TEAM SCORING SYSTEM ---\n");
        printf("1. Add Team\n");
        printf("2. Add Scores to Team\n");
        printf("3. Display Team Scores\n");
        printf("4. Filter Teams by Score\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1: addTeam(teams, &count); break;
            case 2: {
                if(count == 0) {
                    printf("No teams available\n");
                } else {
                    addScore(teams, count);
                }
                break;
            }
            case 3: displayTeamScores(teams, count); break;
            case 4: {
                int threshold;
                printf("Enter score threshold: ");
                scanf("%d", &threshold);
                getchar();
                filterTeamsByScore(teams, count, threshold);
                break;
            }
            case 5: return;
            default: printf("Invalid choice\n");
        }
    }
}

void addTeam(Team teams[], int *count) {
    if(*count >= 50) {
        printf("Maximum teams reached\n");
        return;
    }
    printf("Enter team name: ");
    fgets(teams[*count].teamName, sizeof(teams[*count].teamName), stdin);
    teams[*count].teamName[strcspn(teams[*count].teamName, "\n")] = 0;

    teams[*count].roundCount = 0;
    (*count)++;
    printf("Team added successfully\n");
}

void addScore(Team teams[], int count) {
    printf("Enter team number (1-%d): ", count);
    int teamNum;
    scanf("%d", &teamNum);
    getchar();

    if(teamNum < 1 || teamNum > count) {
        printf("Invalid team number\n");
        return;
    }
    teamNum--;

    if(teams[teamNum].roundCount >= 10) {
        printf("Maximum rounds reached for this team\n");
        return;
    }

    printf("Enter score for round %d: ", teams[teamNum].roundCount + 1);
    scanf("%d", &teams[teamNum].scores[teams[teamNum].roundCount]);
    getchar();

    teams[teamNum].roundCount++;
    printf("Score added successfully\n");
}

int calculateTeamScoreRecursive(int scores[], int index, int roundCount) {
    if(index >= roundCount) return 0;
    return scores[index] + calculateTeamScoreRecursive(scores, index + 1, roundCount);
}

void displayTeamScores(Team teams[], int count) {
    if(count == 0) {
        printf("No teams to display\n");
        return;
    }
    printf("\n=== TEAM SCORES ===\n");
    for(int i = 0; i < count; i++) {
        int totalScore = calculateTeamScoreRecursive(teams[i].scores, 0, teams[i].roundCount);
        printf("%s | Total Score: %d | Rounds: %d\n", teams[i].teamName, totalScore, teams[i].roundCount);
    }
}

void filterTeamsByScore(Team teams[], int count, int threshold) {
    printf("\n=== TEAMS WITH SCORE >= %d ===\n", threshold);
    int found = 0;
    for(int i = 0; i < count; i++) {
        int totalScore = calculateTeamScoreRecursive(teams[i].scores, 0, teams[i].roundCount);
        if(totalScore >= threshold) {
            printf("%s | Total Score: %d\n", teams[i].teamName, totalScore);
            found = 1;
        }
    }
    if(!found) printf("No teams found\n");
}
