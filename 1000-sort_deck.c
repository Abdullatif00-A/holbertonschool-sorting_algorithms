#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * card_value - Convert card value string to integer
 * @value: string of the card value
 * Return: integer value of card
 */
int card_value(const char *value)
{
	if (strcmp(value, "Ace") == 0)
		return (1);
	if (strcmp(value, "2") == 0)
		return (2);
	if (strcmp(value, "3") == 0)
		return (3);
	if (strcmp(value, "4") == 0)
		return (4);
	if (strcmp(value, "5") == 0)
		return (5);
	if (strcmp(value, "6") == 0)
		return (6);
	if (strcmp(value, "7") == 0)
		return (7);
	if (strcmp(value, "8") == 0)
		return (8);
	if (strcmp(value, "9") == 0)
		return (9);
	if (strcmp(value, "10") == 0)
		return (10);
	if (strcmp(value, "Jack") == 0)
		return (11);
	if (strcmp(value, "Queen") == 0)
		return (12);
	if (strcmp(value, "King") == 0)
		return (13);
	return (0);
}

/**
 * compare_cards - Compare two cards
 * @a: first card node
 * @b: second card node
 * Return: negative if a < b, 0 if equal, positive if a > b
 */
int compare_cards(const deck_node_t *a, const deck_node_t *b)
{
	if (a->card->kind != b->card->kind)
		return (a->card->kind - b->card->kind);

	return (card_value(a->card->value) - card_value(b->card->value));
}

/**
 * swap_nodes - Swap two adjacent nodes in a doubly linked list
 * @deck: pointer to head of the deck
 * @a: first node
 * @b: second node
 */
void swap_nodes(deck_node_t **deck, deck_node_t *a, deck_node_t *b)
{
	if (!a || !b || a == b)
		return;

	if (a->prev)
		a->prev->next = b;
	else
		*deck = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: pointer to head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current;
	int swapped;

	if (!deck || !*deck || !(*deck)->next)
		return;

	do {
		swapped = 0;
		current = *deck;
		while (current && current->next)
		{
			if (compare_cards(current, current->next) > 0)
			{
				swap_nodes(deck, current, current->next);
				swapped = 1;
				/* move back to fix pointer update after swap */
				if (current->prev)
					current = current->prev;
			}
			else
			{
				current = current->next;
			}
		}
	} while (swapped);
}

