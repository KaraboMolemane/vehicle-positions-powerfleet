#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
    int32_t VehicleId;
    char VehicleRegistration[256]; // Assuming max length of 256 for simplicity
    float Latitude;
    float Longitude;
    uint64_t RecordedTimeUTC;
} VehicleData;

size_t read_vehicle_data(const char *filename, VehicleData *vehicles, size_t max_entries)
{
    FILE *file = fopen(filename, "rb");
    if (!file)
    {
        perror("Failed to open file");
        return 0;
    }

    size_t index = 0;
    while (index < max_entries && fread(&vehicles[index].VehicleId, sizeof(int32_t), 1, file) == 1)
    {
        // Read VehicleRegistration
        int i = 0;
        while (i < 256)
        {
            fread(&vehicles[index].VehicleRegistration[i], sizeof(char), 1, file);
            if (vehicles[index].VehicleRegistration[i] == '\0')
                break;
            i++;
        }

        // Read Latitude
        fread(&vehicles[index].Latitude, sizeof(float), 1, file);

        // Read Longitude
        fread(&vehicles[index].Longitude, sizeof(float), 1, file);

        // Read RecordedTimeUTC
        fread(&vehicles[index].RecordedTimeUTC, sizeof(uint64_t), 1, file);

        index++;
    }

    fclose(file);
    return index;
}

int main()
{
    size_t max_entries = 2000000;
    VehicleData *vehicles = malloc(max_entries * sizeof(VehicleData));
    if (!vehicles)
    {
        perror("Failed to allocate memory");
        return 1;
    }

    size_t count = read_vehicle_data("../VehiclePositions_DataFile/VehiclePositions.dat", vehicles, max_entries);

    for (size_t i = 0; i < count && i < 20; i++)
    {
        printf("VehicleId: %d, VehicleRegistration: %s, Latitude: %f, Longitude: %f, RecordedTimeUTC: %llu\n",
               vehicles[i].VehicleId, vehicles[i].VehicleRegistration, vehicles[i].Latitude, vehicles[i].Longitude, vehicles[i].RecordedTimeUTC);
    }

    free(vehicles);
    return 0;
}
