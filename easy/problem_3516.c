/**
 * Problem    : 3516
 * Difficulty : Easy
 * Language   : C
 * Time       : O(1)
 * Space      : O(1)
 */

#include <stdio.h>
#include <stdlib.h>

int findClosest(int x, int y, int z) {
    int closest = 0, distance_x = 0, distance_y = 0;

    distance_x = abs(z - x);
    distance_y = abs(z - y);

    if(distance_x < distance_y)
        return 1;
    
    if(distance_x > distance_y)
        return 2;

    return 0;
}

int main() {
    int x = 2, y = 7, z = 4;
    int closest = findClosest(x, y, z);
    printf("Person %i is closest to person 3", closest);

    return 0;
}
