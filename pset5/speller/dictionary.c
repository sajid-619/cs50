// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// hash table size = 2^16
const int HASHTABLE_SIZE = 65536;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    unsigned int hashing = 0;
    for (int i=0, n=strlen(word); i<n; i++) {
        hashing = (hashing << 2) ^ word[i];
    }
    return hashing % N;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    // initialise lower case word
    char lcword[LENGTH+1];

    // convert to lowercase, as we need this to lookup. TODO: change from length to length of word
    for (int i = 0; i < LENGTH; i++)
    {
        lcword[i] = tolower(word[i]);
    }

    // set cursor to start of appropriate lined list
    node *cursor = table[hash(lcword)];


    // traverse list
    while (cursor != NULL)
    {
        // check node's word to see if it is target word, ignoring case
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    // initialise word
    char word[LENGTH+1];

    // open dictionary
    FILE *dicptr = fopen(dictionary, "r");

    // iterate through dictionary words
    while (fscanf(dicptr, "%s", word) != EOF)
    {
        // make a new word.
        node *new_node = malloc(sizeof(node));

        // check for error assigning memory
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        else
        {
            // copy word into node
            strcpy(new_node->word, word);

            // use hash function to determine which bucket (linked list) to insert word into
            int n = hash(new_node->word);

            // insert into list
            new_node->next = table[n];
            table[n] = new_node;
        }
    }
    // close dictionary
    fclose(dicptr);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // dictionary size counter
    int counter = 0;

    // iterate through hashtable
    for (int i = 0; i < N; i++)
    {
        // set pointer to head of list
        node *cursor = table[i];

        // traverse list
        while (cursor != NULL)
        {
            counter++;
            cursor = cursor->next;
        }
    }
    return counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    // iterate through hashtable
    for (int i = 0; i < N; i++)
    {
        // set pointer to head of list
        node *cursor = table[i];

        // traverse list
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        free(cursor);
    }
    return true;
}
