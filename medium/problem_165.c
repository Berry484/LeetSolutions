


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareVersion (char* version1, char* version2);

int main() {
    char version1[] = "1.0.1", version2[] = "1";
    printf("compareVersion = %i\n", compareVersion(version1, version2));

    printf("\n\n");
    return 0;
}

/**
 * Compares two version numbers
 *
 * @param   version1    -First version number
 * @param   version2    -Second version number
 *
 * @return -1 if version1 is larger, 1 if opposite and 0 if equal.
 */
int compareVersion(char* verA, char* verB) {
    const char* sep = ".";
    char *partA, *partB;
    while (partA != NULL || partB != NULL) {
        partA = strsep(&verA, sep);
        partB = strsep(&verB, sep);
        int numA = (partA && *partA) ? atoi(partA) : 0;
        int numB = (partB && *partB) ? atoi(partB) : 0;
        if (numA < numB) return -1;
        else if (numA > numB) return 1;
    }
    return 0;
}
