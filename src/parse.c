#include <stdint.h>
#include <stdio.h>

#include "log.h"
#include "parse.h"

typedef struct {
    uint32_t counter[4];
    uint8_t random[4];
} Rec;

int rec_decode(const char* file_path) {
    // Open file
    FILE* rec_file = fopen(file_path, "rb");
    if(!rec_file) {
        LOG_ERROR("Unable to open file '%s' for reading.\n", file_path);
        return -1;
    }

    // Read file contents into 'Rec' struct
    Rec rec;
    if(fread(&rec, sizeof(Rec), 1, rec_file) != 1) {
        LOG_ERROR("Failed to read file contents into struct.\n");
        return -1;
    }
    fclose(rec_file);

    // Decode file contents
    for (int i = 0; i < 4; ++i) {
        uint8_t* p = (uint8_t*) &rec.counter[i];
        p[0] -= rec.random[i];
        p[1] -= rec.random[i];
        p[2] -= rec.random[i];
        p[3] -= rec.random[i] / 2;
    }

    // Verify result
    if (rec.counter[0] != rec.counter[1] || rec.counter[0] != rec.counter[2]) {
        LOG_ERROR("Failed to parse file contents. Invalid checksum.\n");
        return -1;
    }

    return rec.counter[0];
}

#define DAT_COUNTER_OFFSET 0x1F054

int dat_decode(const char* file_path) {
    // Open file
    FILE* dat_file = fopen(file_path, "rb");
    if(!dat_file) {
        LOG_ERROR("Unable to open file '%s' for reading.\n", file_path);
        return -1;
    }

    // Seek to location of best Hell time
    fseek(dat_file, DAT_COUNTER_OFFSET, SEEK_SET);

    // Read file contents into 'result'
    uint64_t result;
    if(fread(&result, sizeof(result), 1, dat_file) != 1) {
        LOG_ERROR("Failed to parse file contents.\n");
        return -1;
    }
    fclose(dat_file);

    return result;
}
