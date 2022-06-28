#ifndef ARGS_H
#define ARGS_H

#include <stdbool.h>

typedef struct {
    bool verbose;
    bool csplus;
    const char* file_path;
} Options;

// Prases command-line arguments into options. May exit on error.
Options args_parse(int argc, char** argv);

#endif // ARGS_H
