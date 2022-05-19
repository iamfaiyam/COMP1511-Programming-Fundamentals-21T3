// CSE Valley
// cse_valley.c
//
// This program was written by Faiyam Islam (z5258151)
// on 27/10/21
//
// Version 1.0.0 (2021-10-04): Assignment Released.
//
// A C program which creates a simple world, where the user can act 
// as a farmer to seed, grow, harvest, and trade plants for 
// the farmer's wellbeing. The success of the user's career depends
// on how the user navigates this challenging world. 

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_SIZE 50
#define MAX_NUM_SEED_TYPES 26
#define LAND_SIZE 8
#define NO_SEED ' '
#define TRUE 1
#define FALSE 0
#define SEEDS 60

struct land {
    int is_watered;
    char seed_name;
};

struct seeds {
    char name;
    int amount;
};

struct farmer {
    int curr_col;
    int curr_row;
    char curr_dir;
};


// HINT: You will be using this function in stage 2!
void print_land(struct land farm_land[LAND_SIZE][LAND_SIZE], struct farmer cse_farmer);

// Provided functions use for game setup
// You do not need to use these functions yourself.
struct farmer initialise_farmer(struct farmer cse_farmer);
void initialise_seeds(struct seeds seed_collection[MAX_NUM_SEED_TYPES]);
void initialise_land(struct land farm_land[LAND_SIZE][LAND_SIZE]);
void print_top_row(struct land farm_land[LAND_SIZE][LAND_SIZE], int row);
void print_farmer_row(struct land farm_land[LAND_SIZE][LAND_SIZE], 
                      struct farmer cse_farmer);

int main(void) { 
    int day_time = 1, j = 0;
    int seeds_type, no_seeds;
    struct farmer cse_farmer = {};
    cse_farmer = initialise_farmer(cse_farmer);

    struct land farm_land[LAND_SIZE][LAND_SIZE];
    initialise_land(farm_land);

    struct seeds seed_collection[MAX_NUM_SEED_TYPES];
    initialise_seeds(seed_collection);

    printf("Welcome to CSE Valley, farmer!\n");
    printf("Congratulations, you have received 60 seeds.\n");
    printf("How many different seeds do you wish to have? ");

    // Stage 1.1: Scanning in Seeds
    scanf("%d", &seeds_type);
    printf("Enter the names of the seeds to be given:\n");

    // While loop which scans the seed collection and divides the 60
    // seeds by the number of different seed types.
    int i = 0;
    while (i < seeds_type) {
        scanf(" %c", & seed_collection[i].name);
        seed_collection[i].amount = SEEDS / seeds_type;
        i++;
    }
    
    // Stage 1.2: Printing all Seeds
    printf("Game Started!\n");
    printf("Enter command: ");
    char command;
    int square_watering = 0;
    int total_seeds = seeds_type;
    
    // Depending on the number of different seeds which the user inputs, 
    // when the user enters the command 'a', the program prints out 
    // the seed collection based on the user's input.
    while (scanf(" %c", &command) == 1) {
        if (command == 'a') {
            printf("  Seeds at your disposal:\n");
            if (seeds_type == total_seeds) {
                j = 0;     
                while (j < total_seeds) {
                    printf("  - %d seed(s) with the name '%c'\n",
                    seed_collection[j].amount, seed_collection[j].name);
                    j++;
                }
            } else {
                j = seeds_type - 1;
                while (j >= total_seeds) {
                    printf("  - %d seed(s) with the name '%c'\n",
                    seed_collection[j].amount, seed_collection[j].name);
                    j--;
                }
                 
                while (j < total_seeds) {
                    printf("  - %d seed(s) with the name '%c'\n",
                    seed_collection[j].amount, seed_collection[j].name);
                    j++;
                }

            }
        }        
           
        // Stage 1.3: Printing one Seed
        // If the user inputs the command 's', followed by the name of a seed
        // the program will print out how many seeds there are based on that
        // name of the seed.
        if (command == 's') {
            scanf(" %c", & command);
            int one_seed = 0;
            
            while (one_seed < seeds_type) {
            
                int another_seed = 0;
                
                while (another_seed < seeds_type) {
                
                    if (command == seed_collection[another_seed].name) {
                        printf("  There are %d seeds with the name '%c'\n",
                            seed_collection[another_seed].amount,
                            seed_collection[another_seed].name);
                        another_seed = 26;
                    }
                    
                    if (another_seed == (seeds_type - 1)) {
                    
                        if (command < 'a' || command > 'z') {
                            printf("  Seed name has to be a lowercase letter\n");
                            
                        } else
                            printf("  There is no seed with the name '%c' \n", command);
                    }
                    another_seed++;
                }
                one_seed = 26;
                one_seed++;
            }

        }
        
        // Stage 2.1: Printing Land
        // If user provides the command 'l', the entire farm land is printed
        if (command == 'l') {
            print_land(farm_land, cse_farmer);
        }
        
        // Stage 2.2: Moving Around the Farm   
        // This part of the program allows the user to change the direction of 
        // the farmer and correspondingly move the farmer, however the farmer
        // is restricted to a certain boundary and will not cross it
        if (command == '^' || command == 'v' || 
        command == '>' || command == '<') {
        
            if (command == cse_farmer.curr_dir) {
            
                if (command == '>' && cse_farmer.curr_col < LAND_SIZE - 1) {
                    cse_farmer.curr_col = cse_farmer.curr_col + 1;
                    
                } else if (command == '<' && cse_farmer.curr_col > 0) {
                    cse_farmer.curr_col = cse_farmer.curr_col - 1;
                    
                } else if (command == 'v' && 
                cse_farmer.curr_row < LAND_SIZE - 1) {
                    cse_farmer.curr_row = cse_farmer.curr_row + 1;
                    
                } else if (command == '^' && cse_farmer.curr_row > 0) {
                    cse_farmer.curr_row = cse_farmer.curr_row - 1;
                    
                }
            } else {
                cse_farmer.curr_dir = command;
            }
        }
        
        // Stage 2.3: Attending to an Adjacent Land
        // In this stage, if the user provides the command 'l', then: 
        // 1. Plant a seed from an adjacent land
        // 2. Water the seed 
        // 3. The seed name will appear based on what seed was initially 
        // inputted by the user 
        if (command == 'o') {
            square_watering = 1; 
            scanf(" %c", &command); 
            
            if (command == 'p') {
                scanf(" %c", &command); 
                
                int seed_plant = 2; 
                
                j = 0;   
                while (j < seeds_type) {
                    if (command == seed_collection[j].name) {
                        if (seed_collection[j].amount > 0) {
                    
                            seed_plant = 1; 
                        
                        } else {
                            seed_plant = 0; 
                            seed_collection[j].amount = 0; 
                        }
                    }
                    j++;
                }
                  
                if (seed_plant == 1) {
                    if ((cse_farmer.curr_dir == '>') && 
                    (cse_farmer.curr_col < LAND_SIZE - 1)) {
                        farm_land[cse_farmer.curr_row][cse_farmer.curr_col + 1]
                        .seed_name = command; 
                        
                        j = 0; 
                        while (j < seeds_type) {
    
                            if (command == seed_collection[j].name) {
                            
                                seed_collection[j].amount--; 
                            }
                            j++;
                        }
                    } else if ((cse_farmer.curr_dir == '<') && 
                    (cse_farmer.curr_col > 0)) {
                    
                        farm_land[cse_farmer.curr_row][cse_farmer.curr_col - 1]
                        .seed_name = command; 
                        
                        j = 0;
                        while (j < seeds_type) {
                        
                            if (command == seed_collection[j].name) {
                                
                                seed_collection[j].amount--; 
                                
                            }
                            j++;
                        }
                    } else if ((cse_farmer.curr_dir == '^') && 
                    (cse_farmer.curr_row > 0)) {
            
                        farm_land[cse_farmer.curr_row - 1]
                        [cse_farmer.curr_col].seed_name = command; 
                        
                        j = 0;
                        while (j < seeds_type) {
                        
                            if (command == seed_collection[j].name) {
                            
                                seed_collection[j].amount--; 
                            }
                            j++;
                        }
                        
                    } else if ((cse_farmer.curr_dir == 'v') && 
                    (cse_farmer.curr_row < LAND_SIZE - 1)) {

                        farm_land[cse_farmer.curr_row + 1]
                        [cse_farmer.curr_col].seed_name = command; 
                        
                        j = 0;
                        while (j < seeds_type) {
                        
                            if (command == seed_collection[j].name) {
                            
                                seed_collection[j].amount--;
                            }
                            j++;
                        }
                    }
                }
            } else if ((command == 'w') && (square_watering == 1)) {
            
                if ((cse_farmer.curr_dir == '^') && 
                (cse_farmer.curr_row > 0)) {

                    farm_land[cse_farmer.curr_row - 1]
                    [cse_farmer.curr_col].is_watered = TRUE;
               
                } else if ((cse_farmer.curr_dir == 'v') && 
                (cse_farmer.curr_row < LAND_SIZE - 1)) {

                    farm_land[cse_farmer.curr_row + 1]
                    [cse_farmer.curr_col].is_watered = TRUE; 
                    
                } else if ((cse_farmer.curr_dir == '>') && 
                (cse_farmer.curr_col < LAND_SIZE - 1)) {
                
                    farm_land[cse_farmer.curr_row][cse_farmer.curr_col + 1]
                    .is_watered = TRUE;
              
                } else if ((cse_farmer.curr_dir == '<') && 
                (cse_farmer.curr_col > 0)) {

                    farm_land[cse_farmer.curr_row][cse_farmer.curr_col - 1]
                    .is_watered = TRUE; 
                }
            }
        }
        
        // Stage 2.4: Scattering Seeds
        // If the user uses the command 'p' for this program, 
        // followed by the seed name, then depending on the 
        // position in the farm that they are located at 
        // the seeds will be printed 
        if (command == 'p') {
            int scattering_seeds = 0;
            int not_counting_seeds = 0;
            scanf(" %c", &command);
           
            j = 0;
            while (j < seeds_type) {
                if (command < 'a' || command > 'z') {
                    printf(" Seed name has to be a lowercase letter\n");
                    j = seeds_type;

                } else if (command != seed_collection[j].name) {
                    not_counting_seeds++;
                    if (not_counting_seeds == seeds_type) {
                        printf(" There is no seed with the name '%c'\n",
                        command);
                    }
                } else if (cse_farmer.curr_dir == '^' || 
                cse_farmer.curr_dir == '<') {
                    printf(" You cannot scatter seeds ^ or <\n");
                    j = seeds_type;
                } else if (cse_farmer.curr_dir == 'v' && seed_collection[j]
                .name == command) {

                    if (seed_collection[j].amount >= LAND_SIZE - cse_farmer
                    .curr_row)

                        for (i = cse_farmer.curr_row; i < LAND_SIZE; ++i) {

                        farm_land[i][cse_farmer.curr_col].seed_name = command;
                        scattering_seeds++;

                    }

                    else {
                        i = cse_farmer.curr_row; 
                        while (i < seed_collection[j].amount + cse_farmer
                        .curr_row) {

                            farm_land[i][cse_farmer.curr_col].seed_name 
                            = command;
                            scattering_seeds++;
                            i++;
                        }

                    }

                    j = seeds_type;
                } else if (cse_farmer.curr_dir == '>' && seed_collection[j]
                .name == command) {

                    if (seed_collection[j].amount >= LAND_SIZE - cse_farmer
                    .curr_col) {
                        
                        i = cse_farmer.curr_col;
                        while (i < LAND_SIZE) {

                            farm_land[cse_farmer.curr_row][i].seed_name 
                            = command;

                            scattering_seeds++;
                            i++;
                        }
                    } else {
                        i = cse_farmer.curr_col;
                        while (i < seed_collection[j].amount + 
                        cse_farmer.curr_col) {

                            farm_land[cse_farmer.curr_row][i].seed_name = 
                            command;
                            scattering_seeds++;
                            i++;
                        }
                    }

                    j = seeds_type;
                }
                j++;
            }
            j = 0; 
            while (j < seeds_type) {

                if (command == seed_collection[j].name) {

                    seed_collection[j].amount -= scattering_seeds;
                }

                if (seed_collection[j].amount < 0) {
                    seed_collection[j].amount = 0;
                }
                j++;
            }
        }
        
        // Stage 3.1: Square Watering
        // If the user puts 'w' as the command, followed by a number
        // then the farmer will be able to water the seeds 
        if (command == 'w' && square_watering == 0) {
           
            int size_of_farm; 
            
            scanf("%d", &size_of_farm);
            
            if (size_of_farm >= 0) {
                
                i = cse_farmer.curr_row - size_of_farm; 
                
                while (i <= cse_farmer.curr_row + size_of_farm) {
                
                    j = cse_farmer.curr_col - size_of_farm;
                    
                    while (j <= cse_farmer.curr_col + size_of_farm) {
                    
                        if (i >= 0 && i < LAND_SIZE 
                        && j >= 0 && j < LAND_SIZE) 
                        {

                            farm_land[i][j].is_watered = TRUE; 
                        }
                        j++;
                    }
                    i++;
                }
                
            } else {
           
                printf("The size argument needs to be a non-negative integer\n"); 
            
            }
            
        }
        
        // Stage 3.2: Advancing to the Next Day and Harvesting
        // If the user puts 'h' as the command, then they are able to harvest
        // the seed that has grown
        // If the user provides 'n' as the command, then they are able to 
        // advance to a particular day depending on the number they provide
        if (command == 'h') {
         
            if (cse_farmer.curr_dir == '>' && cse_farmer.curr_col < LAND_SIZE - 1) {
            
                if ((farm_land[cse_farmer.curr_row][cse_farmer.curr_col + 1]
                .seed_name >= 'A') 
                && (farm_land[cse_farmer.curr_row][cse_farmer.curr_col + 1]
                .seed_name <= 'Z')) {
                
                    j = 0; 
                    while (j < seeds_type) {
                    
                        if (farm_land[cse_farmer.curr_row][cse_farmer.curr_col 
                        + 1].seed_name 
                        + 32 == seed_collection[j].name) {
                        
                            seed_collection[j].amount += 5; 
                        
                            printf("Plant '%c' was harvested, resulting", 
                            farm_land[cse_farmer.curr_row]
                        [cse_farmer.curr_col + 1].seed_name); 
                            printf("in 5 '%c' seed(s)\n", 
                        seed_collection[j].name);
                        
                        }
                        j++;
                    }
                    
                    farm_land[cse_farmer.curr_row][cse_farmer.curr_col + 1]
                    .seed_name = NO_SEED; 
                 
                }
                 
            } else if (cse_farmer.curr_dir == '<' && cse_farmer.curr_col > 0) {
            
                if (farm_land[cse_farmer.curr_row][cse_farmer.curr_col - 1]
                .seed_name >= 'A' 
                && farm_land[cse_farmer.curr_row][cse_farmer.curr_col - 1]
                .seed_name <= 'Z') {

                    j = 0; 
                    while (j < seeds_type) {
                    
                        if (farm_land[cse_farmer.curr_row][cse_farmer.curr_col 
                        - 1].seed_name 
                        + 32 == seed_collection[j].name) {
                        
                            seed_collection[j].amount = 
                            seed_collection[j].amount + 5; 
                            
                            printf("Plant '%c' was harvested", 
                            farm_land[cse_farmer.curr_row]
                            [cse_farmer.curr_col - 1].seed_name); 
                            printf("resulting in 5 '%c' seed(s)\n",       
                            seed_collection[j].name); 
                        }
                        j++;
                    }
                    
                    farm_land[cse_farmer.curr_row][cse_farmer.curr_col - 1]
                    .seed_name = NO_SEED;
                }
            } else if ((cse_farmer.curr_dir == '^') &&
             (cse_farmer.curr_row > 0)) {
            
                if (farm_land[cse_farmer.curr_row - 1]
                [cse_farmer.curr_col].seed_name >= 'A' && 
                farm_land[cse_farmer.curr_row - 1]
                [cse_farmer.curr_col].seed_name <= 'Z') {
                
                    j = 0; 
                    while (j < seeds_type) {
                    
                        if (farm_land[cse_farmer.curr_row - 1]
                        [cse_farmer.curr_col].seed_name 
                        + 32 == seed_collection[j].name) {

                            seed_collection[j].amount =
                            seed_collection[j].amount + 5;
                            
                            printf("Plant '%c' was harvested", 
                            farm_land
                            [cse_farmer.curr_row - 1][cse_farmer.curr_col]
                            .seed_name);
                            printf("resulting in 5 '%c' seed(s)\n", 
                            seed_collection[j].name); 
                        }
                        j++;
                    }
                    
                    farm_land[cse_farmer.curr_row = 1][cse_farmer.curr_col]
                    .seed_name = NO_SEED; 
                }
                
            } else if ((cse_farmer.curr_dir == 'v') && (cse_farmer.curr_row 
            < LAND_SIZE - 1)) {

                if (farm_land[cse_farmer.curr_row + 1][cse_farmer.curr_col]
                .seed_name >= 'A' 
                && farm_land[cse_farmer.curr_row + 1][cse_farmer.curr_col]
                .seed_name <= 'Z') {
                
                    j = 0; 
                    while (j < seeds_type) {
                
                        if (farm_land[cse_farmer.curr_row + 1][cse_farmer.curr_col]
                        .seed_name 
                        + 32 == seed_collection[j].name) {
                    
                            seed_collection[j].amount += 5; 
                        
                            printf("Plant '%c' has harvested,", 
                            farm_land[cse_farmer.curr_row + 1]
                        [cse_farmer.curr_col].seed_name); 
                            printf("resulting in 5 '%c' seed(s)\n",  
                        seed_collection[j].name); 
                        }
                        j++;
                    }
                
                    farm_land[cse_farmer.curr_row + 1][cse_farmer.curr_col]
                    .seed_name = NO_SEED;  
                  
                }
            }
        }
        
        if (command == 'n') {
                      
            day_time = day_time + 1; 
            
            printf("Advancing to the next day... Day %d, let's go!\n", day_time); 
            
            cse_farmer = initialise_farmer(cse_farmer); 
            
            i = 0; 
            while (i < LAND_SIZE) {
            
                j = 0; 
                while (j < LAND_SIZE) {

                    if (farm_land[i][j].is_watered == TRUE) {

                        farm_land[i][j].is_watered = FALSE; 
                        
                        if (farm_land[i][j].seed_name != NO_SEED) {
                        
                            farm_land[i][j].seed_name = farm_land[i][j].
                            seed_name - 32; 
                        
                        } else if (farm_land[i][j].seed_name >= 'A' && 
                        farm_land[i][j].seed_name <= 'Z') {

                            farm_land[i][j].seed_name = NO_SEED; 
                           
                        }
                        
                    } else if (((farm_land[i][j].seed_name >= 'a') && 
                    (farm_land[i][j].seed_name <= 'z')) ||
                        ((farm_land[i][j].seed_name >= 'A') && 
                        (farm_land[i][j].seed_name <= 'Z'))) {
                        
                        farm_land[i][j].seed_name = NO_SEED; 
                    }
                    j++;
                }
                i++;
            }
        }
        
        // Stage 3.3: Trading Seeds
        // The 't' command, provided by the user will allow them to traded
        // the seeds 
        if (command == 't') {
      
            char first_seed, second_seed;
            int first_check = 0, second_check = 0, third_check = 0;
            int fourth_check = 0, checking_seed = 0, trade = 0;
  
            scanf(" %c", &first_seed);
            scanf(" %d", &trade);
            scanf(" %c", &second_seed);
       
       
            if (first_seed < 'a' || first_seed > 'z') {
            
                printf(" Seed name has to be a lowercase letter\n");
                first_check = 1;
            }

            else if (second_seed < 'a' || second_seed > 'z') {
            
                printf(" Seed name has to be a lowercase letter\n");
                first_check = 1;
            }
       
            else if (trade < 0 && first_check != 1) {
            
                printf("You can't trade negative seeds\n");
                second_check = 1;
            }

            no_seeds = 0;
            j = 0; 
            while (j < seeds_type) {
        
                if (seed_collection[j].name != first_seed) {
                    no_seeds = no_seeds + 1;
               
                    if (no_seeds == seeds_type && first_check != 1 && 
                    second_check != 1)  {
                    
                        printf("You don't have the seeds to be traded\n");
                        third_check = 1;
                    }    
               
                }
           
                else if ((seed_collection[j].amount < trade) && 
                (third_check != 1)) {
               
                    printf("You don't have enough seeds to be traded\n");
                    fourth_check = 1;
            
                }
                j++;
            }
       
            int current_amount = seeds_type;
       
            j = 0;
            while (j < current_amount) {
       
                if (first_check != 1 && second_check != 1 && 
                third_check != 1 && fourth_check != 1) {
            
                    if (seed_collection[j].name == first_seed) {
                        seed_collection[j].amount = seed_collection[j].amount 
                        - trade; 
                    }
       
       
                    if (seed_collection[j].name == second_seed) {
           
                        seed_collection[j].amount = seed_collection[j].amount 
                        + trade; 
                        checking_seed = 1;
           
                    }
       
                    if (j == current_amount - 1) {
       
                        if (checking_seed != 1) { 
                    
                            seed_collection[current_amount].name = 
                            second_seed;
                        
                            seed_collection[current_amount].amount
                            = seed_collection[current_amount].amount 
                            + trade;
                        
                            seeds_type++;
                        }
                    }
                }
                j++;
            }

        }                                
             
        printf("Enter command: ");
    }
    
    return 0;
} 


////////////////////////////////
//     Provided Functions     //
////////////////////////////////

// Prints the structs land (including locating where the
// farmer is)
// You will need this function in Stage 2.
void print_land(struct land farm_land[LAND_SIZE][LAND_SIZE],
                struct farmer cse_farmer) {
    printf("|---|---|---|---|---|---|---|---|\n");
    int i = 0;
    while (i < LAND_SIZE) {
        print_top_row(farm_land, i);
        // only prints mid and bottom row when the farmer
        // is in that row
        if (i == cse_farmer.curr_row) {
            print_farmer_row(farm_land, cse_farmer);
        }
        printf("|---|---|---|---|---|---|---|---|\n");
        i++;
    }
}

// NOTE: You do not need to directly call any of the functions
// below this point. You are allowed to modify them, but you
// do not need to.

// Initialises struct farmer to its default state upon starting
// in which the farmer will be on the top left of the farm
// facing to the right (as noted by '>')
struct farmer initialise_farmer(struct farmer cse_farmer) {
    cse_farmer.curr_col = 0;
    cse_farmer.curr_row = 0;
    cse_farmer.curr_dir = '>';
    return cse_farmer;
}

// Initialises a 2d array of struct land to its default state 
// upon starting, which is that all land is unwatered and
// contains no seed
void initialise_land(struct land farm_land[LAND_SIZE][LAND_SIZE]) {
    int i = 0;
    while (i < LAND_SIZE) {
        int j = 0;
        while (j < LAND_SIZE) {
            farm_land[i][j].is_watered = FALSE;
            farm_land[i][j].seed_name = NO_SEED;
            j++;
        }
        i++;
    }
}

// Initialises struct farmer to its default state upon starting,
// which that all names are initialised as NO_SEED and its
// amount is 0
void initialise_seeds(struct seeds seed_collection[MAX_NUM_SEED_TYPES]) {
    int i = 0;
    while (i < MAX_NUM_SEED_TYPES) {
        seed_collection[i].amount = 0;
        seed_collection[i].name = NO_SEED;
        i++;
    }
}

////////////////////////////////
//      Helper Functions      //
////////////////////////////////

// prints the top row of a particular struct land
void print_top_row(struct land farm_land[LAND_SIZE][LAND_SIZE], int row) {
    int j = 0;
    while (j < LAND_SIZE) {
        printf("|");
        printf("%c", farm_land[row][j].seed_name);
        printf(" ");
        if (farm_land[row][j].is_watered == TRUE) {
            printf("W");
        } else {
            printf(" ");
        }
        j++;
    }
    printf("|");
    printf("\n");
}

// prints the 2 additional row when a farmer is in
// a particular row
void print_farmer_row(struct land farm_land[LAND_SIZE][LAND_SIZE], 
                      struct farmer cse_farmer)  {
    int j = 0;
    while (j < LAND_SIZE) {
        printf("|");
        if (j == cse_farmer.curr_col) {
            if (cse_farmer.curr_dir == '<') {
                printf("<");
            } else {
                printf(" ");
            }
            if (cse_farmer.curr_dir == '^') {
                printf("^");
            } else {
                printf("f");
            }
            if (cse_farmer.curr_dir == '>') {
                printf(">");
            } else {
                printf(" ");
            }
        } else {
            printf("   ");
        }
        j++;
    }
    printf("|");
    printf("\n");
    j = 0;
    while (j < LAND_SIZE) {
        printf("|");
        if (j == cse_farmer.curr_col) {
            printf(" ");
            if (cse_farmer.curr_dir == 'v') {
                printf("v");
            } else if (cse_farmer.curr_dir == '^') {
                printf("f");
            } else {
                printf(" ");
            }
            printf(" ");
        } else {
            printf("   ");
        }
        j++;
    }
    printf("|");
    printf("\n");
}





