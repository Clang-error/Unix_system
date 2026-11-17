#include <stdio.h>
#include <string.h>

int main(void) {
    char text1[] = "a b\nc d\ne f";
    char text2[] = "a b\nc d\ne f";
    char *line, *word, *outer, *inner;

    printf("=== strtok (중첩) ===\n");
    for (line = strtok(text1, "\n"); line; line = strtok(NULL, "\n")) {
        printf("줄: ");
        for (word = strtok(line, " "); word; word = strtok(NULL, " "))
            printf("[%s]", word);
        printf("\n");
    }

    printf("=== strtok_r (중첩) ===\n");
    for (line = strtok_r(text2, "\n", &outer); line; line = strtok_r(NULL, "\n", &outer)) {
        printf("줄: ");
        for (word = strtok_r(line, " ", &inner); word; word = strtok_r(NULL, " ", &inner))
            printf("[%s]", word);
        printf("\n");
    }
    return 0;
}
