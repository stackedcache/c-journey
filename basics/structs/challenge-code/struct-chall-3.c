#include <stdio.h> 
#include <string.h>

// CHALLENGE 3 
// Define a soldier struct with name, rank, weapon, ammo, and health. 
// Create an array of 5 soldiers and populate each entry.
// Print each soldier's info using a loop

// Define Rank Enum
typedef enum {
    PRIVATE, // 0
    CORPORAL, // 1 . . .
    SERGEANT,
    LIEUTENANT
} Rank;

// Define Weapon Enum
typedef enum{
    AK12,
    AK47,
    AK74,
    PKM
} WeaponType;

struct Soldier {
    char name[20];
    Rank rank;
    WeaponType weapon;
    unsigned int ammo;
    unsigned int health;
};


int main(){

    // Map Enums to Strings for printing
    char *rank_names[] = {"Private", "Corporal", "Sergeant", "Lieutenant"};
    char *weapon_type[] = {"AK-12", "AK-47", "AK-74", "PKM"};
    
    struct Soldier soldier[5]; // Create an array of 5 soldiers using Soldier struct
    
    // Using snprintf to ensure that each string is null terminated correctly.
    snprintf(soldier[0].name, sizeof(soldier[0].name), "%s", "Russ");
    snprintf(soldier[1].name, sizeof(soldier[1].name), "%s", "Eric");
    snprintf(soldier[2].name, sizeof(soldier[2].name), "%s", "Alex");
    snprintf(soldier[3].name, sizeof(soldier[3].name), "%s", "Kirill");
    snprintf(soldier[4].name, sizeof(soldier[4].name), "%s", "Sparrow");
   
   // Assign rank to each soldier 
    for(int i = 0; i < 5; i++){
        soldier[i].rank = PRIVATE;
        soldier[i].weapon = AK12;
        soldier[i].ammo = 100;
        soldier[i].health = 100;
    }
    
    for(int i = 0; i < 5; i++){
        printf("Soldier Name: %s\n", soldier[i].name);
        printf("Soldier Rank: %s\n", rank_names[soldier[i].rank]);
        printf("Soldier Weapon: %s\n", weapon_type[soldier[i].weapon]);
        printf("Soldier Ammo: %d\n", soldier[i].ammo);
        printf("Soldier Health: %d\n\n", soldier[i].health);
    }
    
    return 0;
}
