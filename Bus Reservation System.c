#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUSES 30
#define MAX_ROWS 8
#define MAX_COLS 4
#define MAX_NAME_LEN 50
#define MAX_CITY_LEN 20

typedef struct {
    char busn[5];
    char driver[20];
    char arrival[6];
    char depart[6];
    char from[20];
    char to[20];
    char seat[MAX_ROWS][MAX_COLS][MAX_NAME_LEN];
} Bus;

Bus bus[MAX_BUSES];
int p = 0;

void position(int l) {
    int s = 0, emptySeats = 0;
    printf("\n");
    for (int i = 0; i < MAX_ROWS; i++) {
        printf("\n");
        for (int j = 0; j < MAX_COLS; j++) {
            s++;
            if (strcmp(bus[l].seat[i][j], "Empty") == 0) {
                printf("%d. %-30s", s, "Empty");
                emptySeats++;
            } else {
                printf("%d. %-30s", s, bus[l].seat[i][j]);
            }
        }
    }
    printf("\n\nThere are %d seats empty in Bus No: %s\n", emptySeats, bus[l].busn);
}

// Function to read bus and driver details from the file
void readBusDetailsFromFile() {
    FILE *file;
    char line[100];
    file = fopen("bus_details.txt", "r");
    if (file == NULL) {
        printf("Error opening file 'bus_details.txt'.\n");
        exit(1);
    }
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s %s %s %s %s %s",
               bus[p].busn, bus[p].driver, bus[p].arrival,
               bus[p].depart, bus[p].from, bus[p].to);
        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                strcpy(bus[p].seat[i][j], "Empty");
            }
        }
        p++;
    }
    fclose(file);
}

// Function to reserve a seat
void allotment() {
    char name[MAX_NAME_LEN];
    int age;
    char gender[MAX_NAME_LEN];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your gender: ");
    scanf("%s", gender);
    int selectedSeats[MAX_BUSES][MAX_ROWS][MAX_COLS];
    char fromCity[MAX_CITY_LEN];
    char toCity[MAX_CITY_LEN];
    printf("Enter your city of departure: ");
    scanf("%s", fromCity);
    printf("Enter your city of arrival: ");
    scanf("%s", toCity);

    printf("\nAvailable Buses between %s and %s:\n", fromCity, toCity);
    int count = 0;
    for (int n = 0; n < p; n++) {
        if (strcmp(bus[n].from, fromCity) == 0 && strcmp(bus[n].to, toCity) == 0) {
            printf("%d. Bus no: %s\tDriver: %s\tDeparture time: %s\tArrival time: %s\n",
                   count + 1, bus[n].busn, bus[n].driver, bus[n].depart, bus[n].arrival);
            count++;
        }
    }
    
    int busChoice;
    if (count > 0) {
        printf("\nEnter the bus number of your choice (1 to %d): ", count);
        scanf("%d", &busChoice);
        if (busChoice < 1 || busChoice > count) {
            printf("Invalid bus number. Reservation canceled.\n");
            return;
        }
    } else {
        printf("No buses available for the selected cities. Reservation canceled.\n");
        return;
    }

    int actualBusIndex = 0;
    count = 0;
    for (int n = 0; n < p; n++) {
        if (strcmp(bus[n].from, fromCity) == 0 && strcmp(bus[n].to, toCity) == 0) {
            count++;
            if (count == busChoice) {
                actualBusIndex = n;
                break;
            }
        }
    }

    int numSeats;
    printf("Enter the number of seats you want to reserve (1 to 32): ");
    scanf("%d", &numSeats);
    int seat, seatarr[32];
    for (int i = 0; i < numSeats; i++) {
        while (1) {
            printf("Seat Number (1 to 32): ");
            scanf("%d", &seat);
            seatarr[i] = seat;
            if (seat < 1 || seat > 32) {
                printf("Invalid seat number. Please choose a seat between 1 and 32.\n");
            } else if (strcmp(bus[actualBusIndex].seat[(seat - 1) / 4][(seat - 1) % 4], "Empty") != 0) {
                printf("The seat no. is already reserved. Please choose another seat.\n");
            } else {
                strcpy(bus[actualBusIndex].seat[(seat - 1) / 4][(seat - 1) % 4], name);
                break;
            }
        }
    }
    
    printf("\nReservation Successful!\n");
    printf("Bus no: %s\nDriver: %s\tArrival time: %s\tDeparture time: %s\nFrom: %s\tTo: %s\n",
           bus[actualBusIndex].busn, bus[actualBusIndex].driver, bus[actualBusIndex].arrival,
           bus[actualBusIndex].depart, bus[actualBusIndex].from, bus[actualBusIndex].to);
    printf("Reserved seat numbers:\n");
    for (int i = 0; i < numSeats; i++) {
        printf("%d. Seat no: %d\tPassenger Name: %s\n", i + 1, seatarr[i], name);
    }
}

void show() {
    char number[5];
    printf("Enter bus no: ");
    scanf("%s", number);
    int n;
    for (n = 0; n < p; n++) {
        if (strcmp(bus[n].busn, number) == 0) {
            break;
        }
    }
    if (n < p) {
        printf("\n");
        for (int i = 0; i < 80; i++) {
            printf("*");
        }
        printf("\nBus no: %s\t\tDriver: %s\t\tArrival time: %s\tDeparture time: %s\nFrom: %s\t\tTo: %s\n",
               bus[n].busn, bus[n].driver, bus[n].arrival, bus[n].depart, bus[n].from, bus[n].to);
        for (int i = 0; i < 80; i++) {
            printf("*");
        }
        printf("\n");
        position(n); // Call the position() function for correct seat display
    } else {
        printf("Enter correct bus no: ");
    }
}

void avail() {
    printf("Buses Available:\n");
    for (int n = 0; n < p; n++) {
        printf("\n");
        for (int i = 0; i < 80; i++) {
            printf("*");
        }
        printf("\nBus no: %s\t\tDriver: %s\t\tArrival time: %s\tDeparture Time: %s\nFrom: %s\t\tTo: %s\n",
               bus[n].busn, bus[n].driver, bus[n].arrival, bus[n].depart, bus[n].from, bus[n].to);
        for (int i = 0; i < 80; i++) {
            printf("*");
        }
    }
}

void install() {
    printf("Enter bus no: ");
    scanf("%s", bus[p].busn);
    printf("Enter Driver's name: ");
    scanf("%s", bus[p].driver);
    printf("Arrival time: ");
    scanf("%s", bus[p].arrival);
    printf("Departure: ");
    scanf("%s", bus[p].depart);
    printf("From: ");
    scanf("%s", bus[p].from);
    printf("To: ");
    scanf("%s", bus[p].to);
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            strcpy(bus[p].seat[i][j], "Empty");
        }
    }
    p++;
}

int main() {
    readBusDetailsFromFile();
    int w;
    while (1) {
        printf("\n\n\n\n\n");
        printf("\t\t\t1. Reservation\n\t\t\t2. Show\n\t\t\t3. Buses Available\n\t\t\t4. Exit\n");
        printf("\t\t\tEnter your choice:-> ");
        scanf("%d", &w);
        switch (w) {
            case 1:
                allotment();
                break;
            case 2:
                show();
                break;
            case 3:
                avail();
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}
