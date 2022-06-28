#include <stdio.h>
#include <stdlib.h>

#include "args.h"
#include "log.h"
#include "rec.h"

#define FRAMES_PER_SECOND 50
#define FRAMES_PER_MINUTE (50 * 60)

int main(int argc, char** argv) {
    // Parse command line arguments
    Options options = args_parse(argc, argv);
    
    // Use default file path
    if(!options.file_path) {
        if(options.verbose) {
            LOG_INFO("No file path provided. Defaulting to '290.rec' instead.\n");
        }
        options.file_path = "290.rec";
    }

    // Decode rec file contents
    int result = rec_decode(options.file_path);
    if(result == -1) {
        return EXIT_FAILURE;
    }

    // Display results
    const int minutes = result / FRAMES_PER_MINUTE;
    const double seconds = (double)(result % FRAMES_PER_MINUTE) / FRAMES_PER_SECOND;

    printf("\033[0;1mTime:\033[0m   %02u:%.2lf\n", minutes, seconds);
    printf("\033[0;1mFrames:\033[0m %u\n", result);

    return EXIT_SUCCESS;
}
