// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents number of children for each node in a trie
#define N 27

// Represents a node in a trie
typedef struct node
{
    bool is_word;
    struct node *children[N];
}
node;

// Represents a trie
node *root = NULL;
 
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize trie
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        return false; 
    }
    root->is_word = false;
    for (int i = 0; i < N; i++)
    {
        root->children[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into trie
    while (fscanf(file, "%s", word) != EOF)
    {
        // Set children value
        node *children = root;

        // Loop every char in word
        for (int i = 0; word[i] != '\0'; i++)
        {
            // Hash char for position
            int cPosition = (word[i] == '\'') ? N - 1 : word[i] - 'a';

            // Check whether pointer to char = NULL
            if (children->children[cPosition] == NULL)
            {
                // Create node to be pointed by char address
                node *nextChildren = malloc(sizeof(node));
                if (nextChildren == NULL)
                {
                    unload();
                    return false;
                }

                nextChildren->is_word = false;
                for (int j = 0; j < N; j++)
                {
                    nextChildren->children[j] = NULL;
                }

                // Point address to next node
                children->children[cPosition] = nextChildren;

                // Point root to new node
                if (i == 0)
                {
                    root->children[cPosition] = nextChildren;
                }
            }
            // Point to next node
            children = children->children[cPosition];
        }

        // Set end of word = TRUE
        children->is_word = true;
    }

    // Close dictionary
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // Dictionary not loaded
    if (!root)
    {
        return 0;
    }
    
    // Dictionary size
    int dSize = 0;

    // Root pointer track
    node *ptr = root;

    // Increment by 1 if current node is a word
    if (ptr->is_word == true)
    {
        dSize++;
    }

    // Loop through current node
    for (int i = 0; i < N; i++)
    {
        // Move *root to next node
        root = ptr->children[i];

        // Add to dSize the size of the rest of trie
        dSize += size();
    }

    // Reset root to default value
    root = ptr;

    // Return current node its children size
    return dSize;

}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Return false if dictionary not loaded
    if (!root)
    {
        return false;
    }

    node *ptr = root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        char c = tolower(word[i]);
        int cPosition = (c == '\'') ? N - 1 : c - 'a';

        if (!ptr->children[cPosition])
        {
            return false;
        }

        ptr = ptr->children[cPosition];
    }
    return ptr->is_word;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    if (!root)
    {
        return false;
    }

    node *ptr = root;

    for (int i = 0; i < N; i++)
    {
        root = ptr->children[i];
        unload();
    }

    root = ptr;
    free(ptr);

    return true;
}
