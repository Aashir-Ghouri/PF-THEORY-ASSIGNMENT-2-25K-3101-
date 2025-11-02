#include <stdio.h>

void addinfo(char name[], int cnicarray[]) {
    printf("Enter your name: ");
    scanf(" %[^\n]", name);

    printf("Enter CNIC number: ");
    scanf("%d", &cnicarray[0]);

    printf("You entered %s and %d.\n", name, cnicarray[0]);
}

void displayinventory(int product[][1][3], int productcount) {
    printf("Product code     Quantity in stock     Price per product\n");
    for (int i = 0; i < productcount; i++) {
        printf("%d                        %d                    %d\n",
               product[i][0][0], product[i][0][1], product[i][0][2]);
    }
}

void updateinventory(int product[][1][3], int productcount) {
    int code;
    printf("Enter product code: ");
    scanf("%d", &code);
    for (int i = 0; i < productcount; i++) {
        if (product[i][0][0] == code) {
            product[i][0][1]++;
            printf("Inventory updated.\n");
            printf("Updated quantity of product with code %d is %d.\n",
                   code, product[i][0][1]);
            return;
        }
    }
    printf("Product not found.\n");
}

int additem(int product[][1][3], int productcount) {
    int code, price, quantity;
    printf("Enter product code: ");
    scanf("%d", &code);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);
    printf("Enter product price: ");
    scanf("%d", &price);

    if (productcount < 100) {
        product[productcount][0][0] = code;
        product[productcount][0][1] = quantity;
        product[productcount][0][2] = price;
        printf("Product added successfully.\n");
        productcount++;
    } else {
        printf("Array is full.\n");
    }
    return productcount;
}

float displaybill(int product[][1][3], int productcount, char responsearray[]) {
    float bill = 0;
    float discountedbill = 0;

    for (int i = 0; i < productcount; i++) {
        bill = bill + product[i][0][1] * product[i][0][2];
    }

    printf("We are offering a discount code on account of eid ul fitr.\n");
    printf("If you have a promotion code, press 'Y' else press 'N': ");
    scanf(" %c", &responsearray[0]);

    if (responsearray[0] == 'Y' || responsearray[0] == 'y') {
        printf("Congratulations! You are applicable for 25%% discount.\n");
        discountedbill = 0.75 * bill;
        printf("Your discounted bill is %.2f.\n", discountedbill);
        return discountedbill;
    } else {
        printf("Oops! Looks like you are not eligible for discount.\n");
        printf("Your bill is %.2f.\n", bill);
        return bill;
    }
}

void showinvoice(char name[], int cnicarray[], float bill, char responsearray[]) {
    printf("Hey %s! Your bill against the CNIC %d is %.2f.\n", name, cnicarray[0], bill);
    if (responsearray[0] == 'N' || responsearray[0] == 'n') {
        printf("You were not eligible for discount so final bill is : %.2f.\n", bill);
    } else {
        printf("You were eligible for discount so final bill is : %.2f.\n", bill);
    }
}

int main() {
    int choice;
    int product[100][1][3];
    int productcount = 0;
    float bill = 0;
    char responsearray[1];
    char name[100];
    int cnicarray[1];

    do {
        printf("\n--- SuperMarket Items Inventory System ---\n");
        printf("1. Add Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Update Inventory\n");
        printf("4. Add Items to Cart\n");
        printf("5. Display Total Bill\n");
        printf("6. Show Invoice\n");
        printf("7. Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addinfo(name, cnicarray);
                break;
            case 2:
                displayinventory(product, productcount);
                break;
            case 3:
                updateinventory(product, productcount);
                break;
            case 4:
                productcount = additem(product, productcount);
                break;
            case 5:
                bill = displaybill(product, productcount, responsearray);
                break;
            case 6:
                showinvoice(name, cnicarray, bill, responsearray);
                break;
            case 7:
                printf("Exiting Program..\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}

