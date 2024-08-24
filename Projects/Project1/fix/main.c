#include <stdio.h>
#include <stdlib.h>
#include "autocomplete.h"
#include <string.h>

void read_in_terms(term **terms, int *pnterms, char *filename);
int lowest_match(term *terms, int nterms, char *substr);
int highest_match(term *terms, int nterms, char *substr);
void autocomplete(term **answer, int *n_answer, term *terms, int nterms, char *substr);

int main(void)
{
    struct term *terms;
    int nterms;
    read_in_terms(&terms, &nterms, "cities.txt");
    lowest_match(terms, nterms, "Tor");
    highest_match(terms, nterms, "Tor");

    struct term *answer;
    int n_answer;
    autocomplete(&answer, &n_answer, terms, nterms, "Tor");
    // free allocated blocks here -- not required for the project, but good practice
    return 0;
}
