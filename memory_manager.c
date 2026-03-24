/*
 * Memory Manager Assignment
 * Computer Science XII - Computer Systems
 */

#include <stdio.h>
#include <stdlib.h>

// PART 1: CREATE INVENTORY

void create_inventory() {
    printf("\n=== PART 1: CREATE INVENTORY ===\n");
    
    int inventory_size = 5;
    int *item_ids = NULL;
    int *quantities = NULL;
    
    item_ids = (int*)malloc(inventory_size * sizeof(int));

    if (item_ids == NULL) {
        printf("Failed to allocate item_ids\n");
        return;
    }

    quantities = (int*)malloc(inventory_size * sizeof(int));

    if (quantities == NULL) {
        printf("Failed to allocate quantities\n");
        free(item_ids);
        return;
    }

    printf("Starting inventory:\n");
    for (int i = 0; i < inventory_size; i++) {
        item_ids[i] = 100 + i;
        quantities[i] = (i + 1) * 10;
        printf("  Item %d: quantity %d\n", item_ids[i], quantities[i]);
    }

    free(item_ids);
    free(quantities);

    printf("Memory freed successfully.\n");
}

// PART 2: EXPAND INVENTORY

void expand_inventory() {
    printf("\n=== PART 2: EXPAND INVENTORY ===\n");
    
    int initial_size = 3;
    int expanded_size = 6;
    int *item_ids = NULL;
    int *quantities = NULL;
    
    item_ids = (int*)malloc(initial_size * sizeof(int));

    if (item_ids == NULL) {
        printf("Failed to allocate item_ids\n");
        return;
    }

    quantities = (int*)malloc(initial_size * sizeof(int));

    if (quantities == NULL) {
        printf("Failed to allocate quantities\n");
        free(item_ids);
        return;
    }

    printf("Initial inventory (size %d):\n", initial_size);
    for (int i = 0; i < initial_size; i++) {
        item_ids[i] = 200 + i;
        quantities[i] = 5 * (i + 1);
        printf("  Item %d: quantity %d\n", item_ids[i], quantities[i]);
    }

    printf("\nPlayer acquires more items! Expanding inventory...\n");

    int *temp_ids = (int*)realloc(item_ids, expanded_size * sizeof(int));
    if (temp_ids == NULL) {
        printf("Realloc failed for item_ids\n");
        free(item_ids);
        free(quantities);
        return;
    }
    item_ids = temp_ids;

    int *temp_quantities = (int*)realloc(quantities, expanded_size * sizeof(int));
    if (temp_quantities == NULL) {
        printf("Realloc failed for quantities\n");
        free(item_ids);
        free(quantities);
        return;
    }
    quantities = temp_quantities;

    for (int i = initial_size; i < expanded_size; i++) {
        item_ids[i] = 200 + i;
        quantities[i] = 5 * (i + 1);
    }

    printf("Expanded inventory (size %d):\n", expanded_size);
    for (int i = 0; i < expanded_size; i++) {
        printf("  Item %d: quantity %d\n", item_ids[i], quantities[i]);
    }

    free(item_ids);
    free(quantities);

    printf("Memory freed successfully.\n");
}

// PART 3A: MEMORY LEAK DEMONSTRATION

void memory_leak_demo() {
    printf("\n=== PART 3A: MEMORY LEAK DEMONSTRATION ===\n");
    
    for (int i = 0; i < 1000; i++) {
        int *temp_item = (int*)malloc(1000 * sizeof(int));

        if (temp_item == NULL) {
            printf("Allocation failed at iteration %d!\n", i);
            return;
        }

        temp_item[0] = 300 + i;
    }

    printf("Memory leaked.\n");
}

// PART 3B: FIXED VERSION

void memory_leak_fixed() {
    printf("\n=== PART 3B: FIXED VERSION ===\n");
    
    for (int i = 0; i < 1000; i++) {
        int *temp_item = (int*)malloc(1000 * sizeof(int));

        if (temp_item == NULL) {
            printf("Allocation failed at iteration %d!\n", i);
            return;
        }

        temp_item[0] = 300 + i;

        free(temp_item);
    }

    printf("Memory properly freed.\n");
}

// PART 4: SAFE POINTER HANDLING

void safe_pointer_handling() {
    printf("\n=== PART 4: SAFE POINTER HANDLING ===\n");
    
    int *player_health = (int*)malloc(sizeof(int));

    if (player_health == NULL) {
        printf("Allocation failed!\n");
        return;
    }

    *player_health = 100;
    printf("Player health: %d\n", *player_health);

    free(player_health);

    player_health = NULL;

    if (player_health != NULL) {
        printf("Health: %d\n", *player_health);
    } else {
        printf("Health data not available\n");
    }

    printf("Safe pointer handling complete.\n");
}

// MAIN

int main() {
    create_inventory();
    expand_inventory();
    memory_leak_demo();
    memory_leak_fixed();
    safe_pointer_handling();
    return 0;
}