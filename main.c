#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

#define NUM_ITEMS 5

// function for adding items
void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
{
item_list[index].price = price;

item_list[index].sku = (char *)malloc((strlen(sku) + 1) * sizeof(char));
strcpy(item_list[index].sku, sku);

item_list[index].name = (char *)malloc((strlen(name) + 1) * sizeof(char));
strcpy(item_list[index].name, name);

item_list[index].category = (char *)malloc((strlen(category) + 1) * sizeof(char));
strcpy(item_list[index].category, category);
}

//function for free items
void free_items(Item *item_list, int size)
{
for (int i = 0; i < size; i++) {
        free(item_list[i].sku);
        free(item_list[i].name);
        free(item_list[i].category);
        }
        free(item_list);
}

//function for average price
double average_price(Item *item_list, int size)
{
double total = 0.0; 
for (int i = 0; i < size; i++) {
        total += item_list[i].price;
        }
        return total / size;
}

//function for printing the items
void print_items(Item *item_list, int size)
{
for (int i = 0; i < size; i++) {
        printf("################\n");
        printf("item name = %s\n", item_list[i].name);
        printf("item sku = %s\n", item_list[i].sku);
        printf("item category = %s\n", item_list[i].category);
        printf("item price = %.2f\n", item_list[i].price);
        printf("################\n");
        }
}

//main
int main(int argc, char *argv[])
{
        Item *item_list = (Item *)malloc(NUM_ITEMS * sizeof(Item));


        add_item(item_list, 5.00, "19282", "breakfast", "reese's cereal", 0);
        add_item(item_list, 3.95, "79862", "dariy", "milk", 1);
        add_item(item_list, 2.50, "23412", "snacks", "chips", 2);
        add_item(item_list, 10.00, "43123", "beverages", "coffee", 3);
        add_item(item_list, 6.00, "98765", "frozen", "ice cream", 4);

        print_items(item_list, NUM_ITEMS);

        printf("Average price of items = %.2f\n", average_price(item_list, NUM_ITEMS));

        if (argc > 1) {
                char *search_sku = argv[1];
                int found = 0;
                int i = 0;
                while (i < NUM_ITEMS && strcmp(item_list[i].sku, search_sku) != 0)
                {
                        i++;
                }
                if (i < NUM_ITEMS) {
                        printf("Item found:\n");
                        printf("Item name = %s\nitem sku = %s\nitem category = %s\nitem price = %.2f\n, item_list[i].name, item_list[i].sku, item_list[i].category, item_list.price");
                        } else {
                                printf("Item not found!\n");
                                }
                        }

        free_items(item_list, NUM_ITEMS);

        return 0;
}
