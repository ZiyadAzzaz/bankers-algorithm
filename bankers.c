#include <stdio.h>
#include <stdbool.h>

#define P 5  // Number of processes
#define R 3  // Number of resource types

int main() {
    int i, j, k;
    
    // Step 1: Define available resources
    int available[R] = {3, 3, 2};

    // Step 2: Define maximum demand of each process
    int max[P][R] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    // Step 3: Define currently allocated resources
    int allocation[P][R] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    // Step 4: Calculate the need matrix
    int need[P][R];
    for (i = 0; i < P; i++) {
        for (j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Step 5: Create a finished flag for each process
    bool finish[P] = {false};

    // Step 6: Initialize work (copy of available resources)
    int work[R];
    for (i = 0; i < R; i++) {
        work[i] = available[i];
    }

    // Step 7: Store safe sequence
    int safeSeq[P];
    int count = 0;

    // Step 8: Main algorithm loop
    while (count < P) {
        bool found = false;

        for (i = 0; i < P; i++) {
            if (!finish[i]) {
                bool canExecute = true;

                for (j = 0; j < R; j++) {
                    if (need[i][j] > work[j]) {
                        canExecute = false;
                        break;
                    }
                }

                if (canExecute) {
                    // Pretend to run the process
                    for (k = 0; k < R; k++) {
                        work[k] += allocation[i][k];
                    }

                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        // If no process can run, break (unsafe state)
        if (!found) {
            printf("\nSystem is in an UNSAFE state (deadlock may occur).\n");
            return 1;
        }
    }

    // Step 9: If all processes finished, print safe sequence
    printf("\nSystem is in a SAFE state.\nSafe sequence is: ");
    for (i = 0; i < P; i++) {
        printf("P%d", safeSeq[i]);
        if (i != P - 1) printf(" -> ");
    }
    printf("\n");

    return 0;
}
// End of Bankers.c
// This code implements the Banker's Algorithm to determine if a system is in a safe state or not.