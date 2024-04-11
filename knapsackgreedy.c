#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Comparison function for qsort to sort items based on value-to-weight ratio
int compare(const void *a, const void *b) {
    double ratio_a = ((struct Item *)a)->value / (double)((struct Item *)a)->weight;
    double ratio_b = ((struct Item *)b)->value / (double)((struct Item *)b)->weight;
    return ratio_b - ratio_a;
}

// Greedy knapsack function
double knapsack(struct Item items[], int n, int capacity) {
    // Sort items based on value-to-weight ratio
    qsort(items, n, sizeof(struct Item), compare);

    double total_value = 0.0;
    int current_weight = 0;

    // Iterate through sorted items
    for (int i = 0; i < n; i++) {
        // If adding the item won't exceed capacity, add it to the knapsack
        if (current_weight + items[i].weight <= capacity) {
            total_value += items[i].value;
            current_weight += items[i].weight;
        } else {
            // Add fraction of item to fill the knapsack
            int remaining_capacity = capacity - current_weight;
            total_value += items[i].value * ((double)remaining_capacity / items[i].weight);
            break;
        }
    }

    return total_value;
}

int main() {
    struct Item items[] = {{10, 60}, {20, 100}, {30, 120}}; // Example items
    int n = sizeof(items) / sizeof(items[0]); // Number of items
    int capacity = 50; // Knapsack capacity

    double max_value = knapsack(items, n, capacity);
    printf("Maximum value in the knapsack: %.2f\n", max_value);

    return 0;
}
