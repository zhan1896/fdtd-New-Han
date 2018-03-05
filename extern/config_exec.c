
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *s1, const void *s2);
int executeProcedure(const char *key);

struct entry {
    char *str;
    int n;
};

/* sorted according to str */
/*
struct entry dict[] = {
    "dont_live", 4,
    "half_kill", 3,
    "kill", 1,
    "live", 2
};
*/
int compare(const void *s1, const void *s2){
    /*
    const struct entry *e1 = s1;
    const struct entry *e2 = s2;
    return strcmp(e1->str, e2->str);
     */
    return 0;
}

int executeProcedure(const char *key){
    /*
    struct entry *result, keyEntry;
    
    keyEntry = {(char *)key};

    result = bsearch(&keyEntry, dict, sizeof(dict)/sizeof(dict[0]),
                     sizeof dict[0], compare);
    if (result)
        printf("Executed: %s, %d\n", result->str, result->n);
    */
    return 0;
}