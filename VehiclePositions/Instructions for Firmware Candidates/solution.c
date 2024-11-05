#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <string.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct
{
    int32_t VehicleId;
    char VehicleRegistration[256]; // Assuming max length of 256 for simplicity
    float Latitude;
    float Longitude;
    uint64_t RecordedTimeUTC;
} VehicleData;

typedef struct
{
    int position;
    double latitude;
    double longitude;
    char closestReg[256];
} Position;

double calculateDistance(double lat1, double lon1, double lat2, double lon2)
{
    // Haversine formula to calculate the distance between two points on the Earth
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
    lat1 = lat1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;

    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double c = 2 * asin(sqrt(a));
    double R = 6371; // Radius of Earth in kilometers
    return R * c;
}

int compareLatitude(const void *a, const void *b)
{
    VehicleData *vehicleA = (VehicleData *)a;
    VehicleData *vehicleB = (VehicleData *)b;
    return (vehicleA->Latitude > vehicleB->Latitude) - (vehicleA->Latitude < vehicleB->Latitude);
}

size_t read_vehicle_data(const char *filename, VehicleData **vehicles)
{
    FILE *file = fopen(filename, "rb");
    if (!file)
    {
        perror("Failed to open file");
        return 0;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Calculate the number of entries
    size_t numEntries = fileSize / sizeof(VehicleData);

    // Allocate memory for the entries
    *vehicles = (VehicleData *)malloc(fileSize);
    if (*vehicles == NULL)
    {
        perror("Failed to allocate memory");
        fclose(file);
        return 0;
    }

    // Read the file into memory
    size_t bytesRead = fread(*vehicles, sizeof(VehicleData), numEntries, file);
    if (bytesRead != numEntries)
    {
        perror("Failed to read the expected number of entries");
        free(*vehicles);
        fclose(file);
        return 0;
    }

    fclose(file);
    return numEntries;
}

void findClosestRegistrations(Position *positions, int numPositions, VehicleData *vehicles, size_t numVehicles)
{
    // Sort vehicles by latitude
    qsort(vehicles, numVehicles, sizeof(VehicleData), compareLatitude);

    for (int i = 0; i < numPositions; i++)
    {
        double minDistance = INFINITY;
        int closestIndex = -1;

        // Perform a binary search to find the closest latitude
        int left = 0;
        int right = numVehicles - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            double distance = calculateDistance(positions[i].latitude, positions[i].longitude, vehicles[mid].Latitude, vehicles[mid].Longitude);
            if (distance < minDistance)
            {
                minDistance = distance;
                closestIndex = mid;
            }
            if (vehicles[mid].Latitude < positions[i].latitude)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        // Check neighbors around the closest latitude found
        for (int j = closestIndex - 1; j >= 0 && fabs(vehicles[j].Latitude - positions[i].latitude) < minDistance; j--)
        {
            double distance = calculateDistance(positions[i].latitude, positions[i].longitude, vehicles[j].Latitude, vehicles[j].Longitude);
            if (distance < minDistance)
            {
                minDistance = distance;
                closestIndex = j;
            }
        }
        for (int j = closestIndex + 1; j < numVehicles && fabs(vehicles[j].Latitude - positions[i].latitude) < minDistance; j++)
        {
            double distance = calculateDistance(positions[i].latitude, positions[i].longitude, vehicles[j].Latitude, vehicles[j].Longitude);
            if (distance < minDistance)
            {
                minDistance = distance;
                closestIndex = j;
            }
        }

        if (closestIndex != -1)
        {
            strncpy(positions[i].closestReg, vehicles[closestIndex].VehicleRegistration, 255);
            positions[i].closestReg[255] = '\0'; // Ensure null termination
        }
    }
}

int main()
{
    // Print the start time
    clock_t start_time = clock();

    // 10 pre-defined co-ordinates or positions
    Position positions[10] = {
        {1, 34.544909, -102.100843, ""},
        {2, 32.345544, -99.123124, ""},
        {3, 33.234235, -100.214124, ""},
        {4, 35.195739, -95.348899, ""},
        {5, 31.895839, -97.789573, ""},
        {6, 32.895839, -101.789573, ""},
        {7, 34.115839, -100.225732, ""},
        {8, 32.335839, -99.992232, ""},
        {9, 33.535339, -94.792232, ""},
        {10, 32.234235, -100.222222, ""}};

    VehicleData *vehicles;
    size_t numVehicles = read_vehicle_data("../VehiclePositions_DataFile/VehiclePositions.dat", &vehicles);
    if (numVehicles == 0)
    {
        return 1;
    }

    // Find the closest registrations
    findClosestRegistrations(positions, 10, vehicles, numVehicles);

    // Print the results
    for (int i = 0; i < 10; i++)
    {
        printf("Position %d: Latitude = %f, Longitude = %f, Closest Registration = %s\n",
               positions[i].position, positions[i].latitude, positions[i].longitude, positions[i].closestReg);
    }

    // Clean up
    free(vehicles);

    // Print the end time
    clock_t end_time = clock();

    // Print the execution time
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf("Time taken: %f milliseconds\n", time_spent);

    return 0;
}