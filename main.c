#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
// pre-processors stuffs


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

// 1. input sa individual information: function kay individual_info
void individual_info(struct Individual *individual) {
    printf("\n\nInput Atomic Number: ");

    int elementChoice;
    scanf("%d", &elementChoice);
    switch (elementChoice) {
        case 1:
            strcpy(individual->name, "Hydrogen");
            strcpy(individual->symbol, "H");
            individual->atomic_mass = 1.008;
            strcpy(individual->group, "Non-Metals");
            break;
        case 2:
            strcpy(individual->name, "Helium");
            strcpy(individual->symbol, "He");
            individual->atomic_mass = 4.0026;
            strcpy(individual->group, "Noble Gases");
            break;
        case 3:
            strcpy(individual->name, "Lithium");
            strcpy(individual->symbol, "Li");
            individual->atomic_mass = 6.94;
            strcpy(individual->group, "Alkali Metals");
            break;
        case 4:
            strcpy(individual->name, "Beryllium");
            strcpy(individual->symbol, "Be");
            individual->atomic_mass = 9.0122;
            strcpy(individual->group, "Alkali Earth Metals");
            break;
        case 5:
            strcpy(individual->name, "Boron");
            strcpy(individual->symbol, "B");
            individual->atomic_mass = 10.81;
            strcpy(individual->group, "Metalloid");
            break;
        case 6:
            strcpy(individual->name, "Lithium");
            strcpy(individual->symbol, "Li");
            individual->atomic_mass = 6.94;
            strcpy(individual->group, "Alkali Metals");
            break;
        case 7:
            strcpy(individual->name, "Fluorine");
            strcpy(individual->symbol, "F");
            individual->atomic_mass = 18.998;
            strcpy(individual->group, "Halogens");
            break;
        case 8:
            strcpy(individual->name, "Helium");
            strcpy(individual->symbol, "He");
            individual->atomic_mass = 4.0026;
            strcpy(individual->group, "Noble Gases");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}


// 2. chemical group block: function kay group_block
void group_block(int choice) {
    switch (choice) {
        case 1:
            printf("\n\nHalogens\n");
            printf("1. Fluorine (F)\n");
            printf("2. Chlorine (Cl)\n");
            printf("3. Bromine (Br)\n");
            printf("4. Iodine (I)\n");
            printf("5. Astatine (At)\n");
            break;
        case 2:
            printf("\n\nNoble Gases\n");
            printf("1. Helium (He)\n");
            printf("2. Neon (Ne)\n");
            printf("3. Argon (Ar)\n");
            printf("4. Krypton (Kr)\n");
            printf("5. Xenon (Xe)\n");
            break;
        case 3:
            printf("\n\nMetalloid\n");
            printf("1. Boron (B)\n");
            printf("2. Silicon (Si)\n");
            printf("3. Germanium (Ge)\n");
            printf("4. Arsenic (As)\n");
            printf("5. Antimony (Sb)\n");
            break;
        case 4:
            printf("\n\nNon-Metals\n");
            printf("1. Hydrogen (H)\n");
            printf("2. Carbon (C)\n");
            printf("3. Nitrogen (N)\n");
            printf("4. Oxygen (O)\n");
            printf("5. Sulfur (S)\n");
            break;
        case 5:
            printf("\n\nAlkali Earth Metals\n");
            printf("1. Beryllium (Be)\n");
            printf("2. Magnesium (Mg)\n");
            printf("3. Calcium (Ca)\n");
            printf("4. Strontium (Sr)\n");
            printf("5. Barium (Ba)\n");
            break;
        default:
            printf("\n\nERROR!\n");
            sleep(2);
            clear_screen();
            return main();
    }
}

// main

int main(int argc, char const *argv[]) {
    printf("\t\t\t\t\tPERIODIC TABLE INFORMATION\n");
    printf("\n");
    printf("\t\t\t\t\tGROUP MEMBERS\n");
    printf("NAME: KLEVIN JAY A. PORIO\n");
    printf("NAME: SHERLYN KATE C. YPO\n");
    printf("NAME: JHUDIEL LEDENIO\n");
    printf("NAME: MARIA CLARENCE F. CASIPE\n");
    printf("NAME: SHERIFER W. ARNADO\n");
    printf("NAME: JANJAN A. EGOC\n");

    int choice;
    printf("\n");

    printf("SELECT INFORMATION YOU WANT:\n");
    printf("1. INDIVIDUAL INFORMATION\n");
    printf("2. CHEMICAL GROUP BLOCK\n\n");


// submain
    scanf("%d", &choice);
    switch (choice) {
        case 1: {
            struct Individual individual;
            individual_info(&individual);
            printf("\nName: %s\n", individual.name);
            printf("Symbol: %s\n", individual.symbol);
            printf("Atomic Mass: %.2f\n", individual.atomic_mass);
            printf("Chemical Group: %s\n", individual.group);
            break;
        }
            break;
        case 2:
            printf("\n\nPlease Select Chemical Group Block:\n\n");
            printf("1. Halogens\n");
            printf("2. Noble Gases\n");
            printf("3. Metalloid\n");
            printf("4. Non-Metals\n");
            printf("5. Alkali Earth Metals\n\n");

            int groupChoice;
            scanf("%d", &groupChoice);
            group_block(groupChoice);
            break;
        case 0:
            printf("NO DISPLAY");
            return 0;
        default:
            printf("ERROR!\n");
            return main;
    }


// confirmation para return to main
    char returnToMain;
    printf("\n\nReturn to main menu? (Y/N): ");
    scanf(" %c", &returnToMain);

    if (returnToMain == 'Y' || returnToMain == 'y') {
        clear_screen();
        main(argc, argv);
    }

    return 0;
}
