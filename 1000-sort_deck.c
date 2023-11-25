#include "deck.h"

int _str_cmp(const char *n1, const char *n2);
char _get_value(deck_node_t *card);
void insert_sort_deck_kind(deck_node_t **deck);
void insert_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _str_cmp ->> Compares two str.
 * @n1: The first str to be compared.
 * @n2: The second str to be compared.
 * Return: 0.
 */
int _str_cmp(const char *n1, const char *n2)
{
	while (*n1 && *n2 && *n1 == *n2)
	{
		n1++;
		n2++;
	}

	if (*n1 != *n2)
		return (*n1 - *n2);
	return (0);
}

/**
 * _get_value ->> Get numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 * Return: The numerical value of the card.
 */
char _get_value(deck_node_t *card)
{
	if (_str_cmp(card->card->value, "Ace") == 0)
		return (0);
	if (_str_cmp(card->card->value, "1") == 0)
		return (1);
	if (_str_cmp(card->card->value, "2") == 0)
		return (2);
	if (_str_cmp(card->card->value, "3") == 0)
		return (3);
	if (_str_cmp(card->card->value, "4") == 0)
		return (4);
	if (_str_cmp(card->card->value, "5") == 0)
		return (5);
	if (_str_cmp(card->card->value, "6") == 0)
		return (6);
	if (_str_cmp(card->card->value, "7") == 0)
		return (7);
	if (_str_cmp(card->card->value, "8") == 0)
		return (8);
	if (_str_cmp(card->card->value, "9") == 0)
		return (9);
	if (_str_cmp(card->card->value, "10") == 0)
		return (10);
	if (_str_cmp(card->card->value, "Jack") == 0)
		return (11);
	if (_str_cmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insert_sort_deck_kind ->> Sort a deck of playing cards from spades to diamonds.
 * @deck: A pointer to the deck_node_t duplex list header.
 */
void insert_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && insert->card->kind > iter->card->kind)
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * insert_sort_deck_value ->> Sort the ranked deck of playing cards from spades to diamonds from ace to king.
 * @deck: A pointer to the deck_node_t duplex list header.
 */
void insert_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL &&
		       insert->card->kind == iter->card->kind &&
		       _get_value(insert) > _get_value(iter))
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * sort_deck ->> Sort the deck from ace to king and from spades to diamonds.
 * @deck: A pointer to the deck_node_t duplex list header.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insert_sort_deck_kind(deck);
	insert_sort_deck_value(deck);
}
