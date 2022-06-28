#include <stdio.h>
#include <stdlib.h>

#include "args.h"
#include "defs.h"
#include "log.h"
#include "rec.h"

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

    // Decode file contents
    int result;
    if(options.csplus) {
        result = dat_decode(options.file_path);
    } else {
        result = rec_decode(options.file_path);
    }

    if(result == -1) {
        return EXIT_FAILURE;
    }

    // Display results
    const int frames_per_second = options.csplus ? 60 : 50;
    const int frames_per_minute = frames_per_second * 60;

    const int minutes = result / frames_per_minute;
    const double seconds = (double)(result % frames_per_minute) / frames_per_second;

    printf("\033[0;1mTime:\033[0m   %02u:%.2lf\n", minutes, seconds);
    printf("\033[0;1mFrames:\033[0m %u\n", result);

    return EXIT_SUCCESS;
}
