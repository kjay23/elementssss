#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define LEFT(str, w) \
    ({int m = w + strlen(str); m % 2 ? (m + 1) / 2 : m / 2;})

#define RIGHT(str, w) \
({ int m = w - strlen(str); m % 2 ? (m - 1) / 2 : m / 2; })

#define STR_CENTER(str, width) \
    LEFT(str, width), str, RIGHT(str, width), ""

#define PRINTF_CENTER(width, start, fmt, end, ...) ({ \
    int n = snprintf(NULL, 0, fmt, __VA_ARGS__);     \
    int m = width - n;                               \
    int left = m % 2 ? (m + 1) / 2 : m / 2;          \
    int right = m % 2 ? (m - 1) / 2 : m / 2;         \
    printf(start "%*s" fmt "%*s" end, left, "",      \
           __VA_ARGS__, right, "");                  \
})

#define MYFORMAT_CENTER(width, fmt, ...)  \
    PRINTF_CENTER(40, "[", fmt  , "]\n", __VA_ARGS__)
    //para na ma center ang texts, duh

#ifdef _WIN32
#include <Windows.h>
#define CLEAR_SCREEN() system("cls")
#else
#define CLEAR_SCREEN() printf("\033[H\033[J")
#endif

//to clear screen churva2
void clear_screen() {
    CLEAR_SCREEN();
}

struct Individual {
    char atom[50];
    char name[50];
    char symbol[3];
    float atomic_mass;
    char group[20];
};

void inputIndividualInfo(struct Individual *individual) {
    printf("\n\nInput Atomic Number: ");
    scanf("%s", individual->atom);
    printf("Enter name: ");
    scanf("%s", individual->name);
    printf("Enter symbol: ");
    scanf("%s", individual->symbol);
    printf("Enter atomic mass: ");
    scanf("%f", &(individual->atomic_mass));
    printf("Enter chemical group: ");
    scanf("%s", individual->group);
}

int main(int argc, char const *argv[]) {
    printf("%*s%*s\n\n", STR_CENTER(" PERIODIC TABLE INFORMATION ", 100));
    printf("\n");
    printf("\t\t\t\t\tGROUP MEMBERS\n");
    printf("1. KLEVIN JAY A. PORIO\n");
    printf("2. SHERLYN KATE C. YPO\n");
    printf("3. JHUDIEL LEDENIO\n");
    printf("4. MARIA CLARENCE F. CASIPE\n");
    printf("5. SHERIFER W. ARNADO\n");
    printf("6. JANJAN A. EGOC\n");

    int choice;
    printf("\n");

    printf("SELECT INFORMATION YOU WANT:\n");
    printf("1. INDIVIDUAL INFORMATION\n");
    printf("2. CHEMICAL GROUP BLOCK\n\n");

    scanf("%d", &choice);
    switch (choice) {
        case 1:
            {
                struct Individual individual;

                // Prompt user to input individual information
                inputIndividualInfo(&individual);

                // Display the entered information
                printf("\nName: %s\n", individual.name);
                printf("Symbol: %s\n", individual.symbol);
                printf("Atomic Mass: %.2f\n", individual.atomic_mass);
                printf("Chemical Group: %s\n", individual.group);
            }
            break;
        case 2:
            printf("ambot");
            break;
        case 0:
            printf("NO DISPLAY");
            return 0;
        default:
            printf("ERROR!\n");
            return 1;
    }

    char returnToMain;
    printf("\n\nReturn to main menu? (Y/N): ");
    scanf(" %c", &returnToMain);

    if (returnToMain == 'Y' || returnToMain == 'y') {
        // Return to main menu
        clear_screen();
        main(argc, argv);
    }

    return 0;
}
