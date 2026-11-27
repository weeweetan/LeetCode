#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize);

#define CHECK(condition) do { if (!(condition)) { \
    fprintf(stderr, "line %d: %s\n", __LINE__, #condition); \
    exit(EXIT_FAILURE); \
} } while (0)

static void check_prefix(char **words, int count, const char *expected)
{
    char *prefix = longestCommonPrefix(words, count);
    CHECK(prefix != NULL);
    CHECK(strcmp(prefix, expected) == 0);
    free(prefix);
}

int main(int argc, char **argv)
{
    CHECK(argc == 2);
    if (strcmp(argv[1], "examples") == 0) {
        char *shared[] = {"flower", "flow", "flight"};
        char *disjoint[] = {"dog", "racecar", "car"};
        check_prefix(shared, 3, "fl");
        check_prefix(disjoint, 3, "");
    } else if (strcmp(argv[1], "equal") == 0) {
        char *same[] = {"repeated", "repeated", "repeated"};
        char *single[] = {"one string"};
        check_prefix(same, 3, "repeated");
        check_prefix(single, 1, "one string");
    } else if (strcmp(argv[1], "empty") == 0) {
        char *empty_first[] = {"", "text"};
        char *empty_later[] = {"text", ""};
        check_prefix(empty_first, 2, "");
        check_prefix(empty_later, 2, "");
    } else if (strcmp(argv[1], "zero") == 0) {
        check_prefix(NULL, 0, "");
    } else {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
