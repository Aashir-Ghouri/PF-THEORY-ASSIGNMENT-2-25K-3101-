#include <stdio.h>

int addnewbook(int isbns[], char titles[][50], float prices[], int quantities[], int count) {
    int isbn;
    int isduplicate = 0;

    printf("Enter ISBN of the book: ");
    scanf("%d", &isbn);

    for (int i = 0; i < count; i++) {
        if (isbns[i] == isbn) {
            printf("Book with this ISBN already exists.\n");
            isduplicate = 1;
            break;
        }
    }

    if (isduplicate == 0) {
        isbns[count] = isbn;

        printf("Enter book title: ");
        scanf(" %[^\n]s", titles[count]);   // notice the space before %[^\n]

        printf("Enter price: ");
        scanf("%f", &prices[count]);

        printf("Enter quantity: ");
        scanf("%d", &quantities[count]);

        printf("Book added successfully!\n");
        count = count + 1;
    }

    return count;
}

void processsale(int isbns[], int quantities[], int count) {
    int isbn;
    int numsold;
    int found = 0;

    printf("Enter ISBN: ");
    scanf("%d", &isbn);

    printf("Enter number of copies sold: ");
    scanf("%d", &numsold);

    for (int i = 0; i < count; i++) {
        if (isbns[i] == isbn) {
            found = 1;
            if (quantities[i] >= numsold) {
                quantities[i] = quantities[i] - numsold;
                printf("Quantity updated successfully.\n");
                printf("The updated quantity of ISBN %d is : %d\n", isbn, quantities[i]);
            } else {
                printf("Not enough stock.\n");
            }
            break;
        }
    }

    if (found == 0) {
        printf("ISBN not found!\n");
    }
}

void lowstockreport(int isbns[], char titles[][50], int quantities[], int count) {
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            found = 1;
            printf("The book with ISBN : %d and Title : %s is low on quantity.\n", isbns[i], titles[i]);
            printf("The available number of books is %d.\n", quantities[i]);
        }
    }

    if (found == 0) {
        printf("All books are in sufficient stock.\n");
    }
}

int main() {
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int count = 0;
    int choice;

    do {
        printf("\n--- Liberty Books Inventory System ---\n");
        printf("1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low-Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                count = addnewbook(isbns, titles, prices, quantities, count);
                break;
            case 2:
                processsale(isbns, quantities, count);
                break;
            case 3:
                lowstockreport(isbns, titles, quantities, count);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

