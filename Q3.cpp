#include <stdio.h>

void updateSector(int grid[5][5], int row, int col) {
    int r, c, bit, action;

    printf("Enter sector coordinates (row and column 0-%d): ", row - 1);
    scanf("%d %d", &r, &c);

    if (r < 0 || r >= row || c < 0 || c >= col) {
        printf("Invalid coordinates!\n");
        return;
    }

    printf("Select status flag to modify:\n");
    printf("0 = Power Status (1=ON, 0=OFF)\n");
    printf("1 = Overload Warning (1=ON, 0=OFF)\n");
    printf("2 = Maintenance Required (1=ON, 0=OFF)\n");
    printf("Enter bit number (0-2): ");
    scanf("%d", &bit);

    if (bit < 0 || bit > 2) {
        printf("Invalid bit number!\n");
        return;
    }

    printf("Enter action (1=Set, 0=Clear): ");
    scanf("%d", &action);

    if (action == 1) {
        grid[r][c] = grid[r][c] | (1 << bit);
    } else {
        grid[r][c] = grid[r][c] & (~(1 << bit));
    }

    printf("Sector (%d,%d) updated. Current value = %d\n", r, c, grid[r][c]);
}

void querySector(int grid[5][5], int row, int col) {
    int r, c;
    printf("Enter sector coordinates to query (0-%d): ", row - 1);
    scanf("%d %d", &r, &c);

    if (r < 0 || r >= row || c < 0 || c >= col) {
        printf("Invalid coordinates!\n");
        return;
    }

    int val = grid[r][c];
    printf("\nSector (%d,%d) Report:\n", r, c);

    if (val & 1)
        printf("Power Status: ON\n");
    else
        printf("Power Status: OFF\n");

    if (val & (1 << 1))
        printf("Overload Warning: OVERLOADED\n");
    else
        printf("Overload Warning: NORMAL\n");

    if (val & (1 << 2))
        printf("Maintenance Required: YES\n");
    else
        printf("Maintenance Required: NO\n");
}

void runDiagnostic(int grid[5][5], int row, int col) {
    int i, j;
    int overloadCount = 0;
    int maintenanceCount = 0;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (grid[i][j] & (1 << 1)) {
                overloadCount++;
            }
            if (grid[i][j] & (1 << 2)) {
                maintenanceCount++;
            }
        }
    }

    printf("\n--- System Diagnostic Report ---\n");
    printf("Total Overloaded Sectors: %d\n", overloadCount);
    printf("Total Maintenance Required: %d\n", maintenanceCount);
}

int main() {
    int grid[5][5] = {0};
    int choice;
    int row = 5, col = 5;

    do {
        printf("\n--- IESCO Power Grid System ---\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                updateSector(grid, row, col);
                break;
            case 2:
                querySector(grid, row, col);
                break;
            case 3:
                runDiagnostic(grid, row, col);
                break;
            case 4:
                printf("Exiting system...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}

