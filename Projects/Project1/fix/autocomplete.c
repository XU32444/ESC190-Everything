#include <stdio.h>
#include <stdlib.h>
#include "autocomplete.h"
#include <string.h>

int compare_weight(const void *a, const void *b)
{
    const term *term1 = (const term *)a;
    const term *term2 = (const term *)b;
    return (term2->weight - term1->weight);
}
int compare_terms(const void *a, const void *b)
{
    const term *term1 = (const term *)a;
    const term *term2 = (const term *)b;
    return strcmp(term1->term, term2->term);
}

void read_in_terms(term **terms, int *pnterms, char *filename)
{
    // getting the number of terms in the file
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("unsucessful");
        exit(1);
    }
    char buffer[200];                                   // assuming the maximum length of a line is 200
    int nterms = -1;                                    // text file starts with number of lines/terms
    while (fgets(buffer, sizeof(buffer), file) != NULL) // reading the file line by line
    {
        nterms++;
    }
    *pnterms = nterms;
    *terms = (term *)malloc((*pnterms) * sizeof(term));

    // putting each term into *terms
    rewind(file);              // resetting the file pointer to the beginning of the file
    fscanf(file, "%*[^\n]\n"); // skipping the first line
    for (int i = 0; i < nterms; i++)
    {
        fscanf(file, "%lf", &(*terms)[i].weight);
        fscanf(file, "%s", (*terms)[i].term);
    }
    fclose(file);

    qsort(*terms, nterms, sizeof(term), compare_terms);
}

int lowest_match(term *terms, int nterms, char *substr)
{
    int substr_len = strlen(substr);
    int low = 0;
    int high = nterms - 1;
    int mid;
    int match = -1; // Default to -1, indicating no match

    while (low <= high)
    {
        mid = low + (high - low) / 2; // To prevent potential overflow
        int cmp = strncmp(terms[mid].term, substr, substr_len);

        if (cmp < 0)
        {
            low = mid + 1;
        }
        else if (cmp > 0)
        {
            high = mid - 1;
        }
        else
        {
            match = mid; // Found a match, but continue to find the first occurrence
            high = mid - 1;
        }
    }

    return match; // Will return -1 if no match is found
}

int highest_match(term *terms, int nterms, char *substr)
{
    int substr_len = strlen(substr);
    int low = 0;
    int high = nterms - 1;
    int mid;
    int match = -1; // Default to -1, indicating no match

    while (low <= high)
    {
        mid = low + (high - low) / 2; // To prevent potential overflow
        int cmp = strncmp(terms[mid].term, substr, substr_len);

        if (cmp > 0)
        {
            high = mid - 1;
        }
        else if (cmp < 0)
        {
            low = mid + 1;
        }
        else
        {
            match = mid; // Found a match, continue to find the highest occurrence
            low = mid + 1;
        }
    }

    return match; // Will return -1 if no match is found
}

int compare_weight1(const void *a, const void *b)
{
    const term *termA = (const term *)a;
    const term *termB = (const term *)b;
    if (termA->weight < termB->weight)
    {
        return 1;
    }
    else if (termA->weight > termB->weight)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void autocomplete(term **answer, int *n_answer, term *terms, int nterms, char *substr)
{
    int start_index = lowest_match(terms, nterms, substr);
    int end_index = highest_match(terms, nterms, substr);

    if (start_index == -1 || end_index == -1)
    {
        *answer = NULL;
        *n_answer = 0;
        return;
    }

    *n_answer = end_index - start_index + 1;

    *answer = (term *)malloc(*n_answer * sizeof(term));
    if (*answer == NULL)
    {
        perror("Memory Allocation Failure");
        exit(1);
    }

    // Initialize the allocated memory
    memset(*answer, 0, *n_answer * sizeof(term));

    for (int i = 0; i < *n_answer; i++)
    {
        (*answer)[i].weight = terms[start_index + i].weight;
        strncpy((*answer)[i].term, terms[start_index + i].term, sizeof((*answer)[i].term) - 1);
        (*answer)[i].term[sizeof((*answer)[i].term) - 1] = '\0'; // Ensuring null-termination
    }

    qsort(*answer, *n_answer, sizeof(term), compare_weight1);
}

// void autocomplete(term **answer, int *n_answer, term *terms, int nterms, char *substr)
// {
//     int start_index = lowest_match(terms, nterms, substr);
//     int end_index = highest_match(terms, nterms, substr);

//     if (start_index == -1 || end_index == -1)
//     {
//         *answer = NULL;
//         *n_answer = 0;
//         return;
//     }

//     *n_answer = end_index - start_index + 1;

//     *answer = (term *)malloc(*n_answer * sizeof(term));
//     if (*answer == NULL)
//     {
//         perror("Memory Allocation Failure");
//         exit(1);
//     }

//     for (int i = 0; i < *n_answer; i++)
//     {
//         (*answer)[i].weight = (terms)[start_index + i].weight;
//         strcpy((*answer)[i].term, (terms)[start_index + i].term);
//     }
//     qsort(*answer, *n_answer, sizeof(term), compare_weight1);
// }
