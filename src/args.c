#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "args.h"
#include "log.h"

void print_help(const char* exec_path) {
    printf(
        "Nikumaru - Cave Story 'Hell' time extraction tool\n\n"
        "Usage:\n"
        "    %s [options] <file path>\n\n"
        "Options:\n"
        "    -h, --help      Display help information\n"
        "    -v, --verbose   Display additional information while running\n"
        "    -p, --csplus    Extract time from Cave Story+ '.dat' files\n",
        
        exec_path
    );
}

Options args_parse(int argc, char** argv) {
    const char* exec_path = argv[0];
    Options options = (Options) { 0 };

    for(int i = 1; i < argc; ++i) {
        const char* arg = argv[i];

        // Flag
        if(arg[0] == '-') {
            // Long flag
            if(arg[1] == '-') {
                if(strcmp(arg, "--help") == 0) {
                    print_help(exec_path);
                    exit(EXIT_SUCCESS);
                }
                else if(strcmp(arg, "--verbose") == 0) {
                    options.verbose = true;
                }
                else if(strcmp(arg, "--csplus") == 0) {
                    options.csplus = true;
                }
                else {
                    LOG_ERROR("Unknown option '%s' provided.\n", arg);
                    exit(EXIT_FAILURE);
                }
            }
            // Short flag
            else {
                ++arg;  // Skip leading dash
                while(*arg != '\0') {
                    const char c = *arg++;
                    switch(c) {
                    case 'h':
                        print_help(exec_path);
                        exit(EXIT_SUCCESS);
                    case 'v':
                        options.verbose = true;
                        break;
                    case 'p':
                        options.csplus = true;
                        break;

                    default:
                        LOG_ERROR("Unknown option '-%c' provided.\n", c);
                        exit(EXIT_FAILURE);
                    }
                }
            }
        }
        else {
            if(!options.file_path) {
                options.file_path = arg;
            }
            else {
                LOG_ERROR("Unexpected argument '%s' provided.\n", arg);
                exit(EXIT_FAILURE);
            }
        }
    }

    return options;
}
