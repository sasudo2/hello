
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FOODS 100

struct Food {
    char name[100];
    double calories;
};

int main() {
    // Read food records from "food.txt" and store them in an array
    struct Food foods[MAX_FOODS];
    int numFoods = 0;

    FILE *foodFile = fopen("food.txt", "r");
    if (foodFile == NULL) {
        printf("Error opening the food file.\n");
        return 1; // Return an error code
    }

    while (fscanf(foodFile, "%[^-] - %lf", foods[numFoods].name, &foods[numFoods].calories) == 2) {
        fgetc(foodFile); // Consume the newline character
        numFoods++;
    }

    fclose(foodFile);

    // Display food options to the user
    printf("Food Options:\n");
    for (int i = 0; i < numFoods; i++) {
        printf("%d. %s\n", i + 1, foods[i].name);
    }

    int choice;
    printf("Enter the number corresponding of the food you want to track: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > numFoods) {
        printf("Invalid choice.\n");
        return 1; // Return an error code
    }

    // Open "tracking.txt" in append mode to store the chosen food
    FILE *trackingFile = fopen("tracking.txt", "a");
    if (trackingFile == NULL) {
        printf("Error opening the tracking file.\n");
        return 1; // Return an error code
    }

    // Store the chosen food and its calorie content in "tracking.txt"
    fprintf(trackingFile, "%s - %.2lf calories\n", foods[choice - 1].name, foods[choice - 1].calories);

    fclose(trackingFile);

    printf("Chosen food has been tracked and stored in \"tracking.txt\".\n");

    return 0;
}
