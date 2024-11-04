/*
 * Use your preferred naming convention
 * Add comments to help others to understand your code and to document assumptions
 * You are welcome to add additional files if required
 */

#include <stdio.h>

typedef struct
{
    int position;
    double latitude;
    double longitude;
} Position;

int main()
{
    // 10 pre-defined co-ordinates or positions 
    Position positions[10] = {
        {1, 34.544909, -102.100843},
        {2, 32.345544, -99.123124},
        {3, 33.234235, -100.214124},
        {4, 35.195739, -95.348899},
        {5, 31.895839, -97.789573},
        {6, 32.895839, -101.789573},
        {7, 34.115839, -100.225732},
        {8, 32.335839, -99.992232},
        {9, 33.535339, -94.792232},
        {10, 32.234235, -100.222222}};

    for (int i = 0; i < 10; i++)
    {
        printf("Position %d: Latitude = %f, Longitude = %f\n", positions[i].position, positions[i].latitude, positions[i].longitude);
    }

    return 0;
}