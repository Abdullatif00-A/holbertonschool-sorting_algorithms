#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck.h"

/**
 * card_value - Map card string to number 0–12
 * @value: Card value string
 * Return: Numeric representation
 */
int card_value(const char *value)
{
    if (strcmp(value, "Ace") == 0)
        return (0);
    if (strcmp(value, "2") == 0)
        return (1);
    if (strcmp(value, "3") == 0)
        return (2);
    if (strcmp(value, "4") == 0)
        return (3);
    if (strcmp(value, "5") == 0)
        return (4);
    if (strcmp(value, "6") == 0)
        return (5);
    if (strcmp(value, "7") == 0)
        return (6);
    if (strcmp(value, "8") == 0)
        return (7);
    if (strcmp(value, "9") == 0)
        return (8);
    if (strcmp(value, "10") == 0)
        return (9);
    if (strcmp(value, "Jack") == 0)
        return (10);
    if (strcmp(value, "Queen") == 0)
        return (11);
    if (strcmp(value, "King") == 0)
        return (12);
    return (-1);
}

/**
 * compare_cards - Compare two cards
 * @a: First card
 * @b: Second card
 * Return: Negative, zero, or positive int
 */
int compare_cards(const void *a, const void *b)
{
    deck_node_t *card_a = *(deck_node_t **)a;
    deck_node_t *card_b = *(deck_node_t **)b;
    int kind_diff = card_a->card->kind - card_b->card->kind;

    if (kind_diff != 0)
        return (kind_diff);
    return (card_value(card_a->card->value) - card_value(card_b->card->value));
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Double pointer to deck's head
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *node = *deck, **nodes_array;
    size_t i, count = 0;

    if (!deck || !*deck || !(*deck)->next)
        return;

    while (node)
    {
        count++;
        node = node->next;
    }

    nodes_array = malloc(sizeof(deck_node_t *) * count);
    if (!nodes_array)
        return;

    node = *deck;
    for (i = 0; i < count; i++)
    {
        nodes_array[i] = node;
        node = node->next;
    }

    qsort(nodes_array, count, sizeof(deck_node_t *), compare_cards);

    for (i = 0; i < count; i++)
    {
        nodes_array[i]->prev = (i > 0) ? nodes_array[i - 1] : NULL;
        nodes_array[i]->next = (i < count - 1) ? nodes_array[i + 1] : NULL;
    }

    *deck = nodes_array[0];
    free(nodes_array);
}

