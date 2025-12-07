#include <stdio.h>
#include <stdbool.h>

// Function prototypes
bool login();
void showMenu();
void checkBalance(double balance);
double deposit(double balance);
double withdraw(double balance);

int main() {
    double balance = 1000.00; // initial balance

    // Login first
    if (!login()) {
        printf("Access denied. Program exiting.\n");
        return 0;
    }

    int choice;

    // Main ATM loop
    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;

            case 2:
                balance = deposit(balance);
                break;

            case 3:
                balance = withdraw(balance);
                break;

            case 4:
                printf("Thank you! Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

// ---------------------------------------------------------
// Login Function
// ---------------------------------------------------------
bool login() {
    const int PIN = 1234;  // stored PIN
    int enteredPIN;
    int attempts = 3;

    while (attempts > 0) {
        printf("Enter your PIN: ");
        scanf("%d", &enteredPIN);

        if (enteredPIN == PIN) {
            printf("Login successful!\n\n");
            return true;
        } else {
            attempts--;
            printf("Incorrect PIN. Attempts left: %d\n", attempts);
        }
    }

    return false;
}

// ---------------------------------------------------------
// Display Menu
// ---------------------------------------------------------
void showMenu() {
    printf("\n======= ATM MENU =======\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
    printf("========================\n");
}

// ---------------------------------------------------------
// Balance Inquiry
// ---------------------------------------------------------
void checkBalance(double balance) {
    printf("Your current balance is: $%.2f\n", balance);
}

// ---------------------------------------------------------
// Deposit Function
// ---------------------------------------------------------
double deposit(double balance) {
    double amount;
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Deposit must be positive.\n");
        return balance;
    }

    balance += amount;
    printf("Deposit successful! New balance: $%.2f\n", balance);
    return balance;
}

// ---------------------------------------------------------
// Withdraw Function
// ---------------------------------------------------------
double withdraw(double balance) {
    double amount;
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Withdrawal must be positive.\n");
        return balance;
    }

    if (amount > balance) {
        printf("Insufficient balance! Withdrawal denied.\n");
        return balance;
    }

    balance -= amount;
    printf("Withdrawal successful! New balance: $%.2f\n", balance);
    return balance;
}
