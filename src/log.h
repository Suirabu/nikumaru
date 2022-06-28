#ifndef LOG_H
#define LOG_H

#include <stdio.h>

#define LOG_ERROR(...) \
    fprintf(stderr, "\033[31;1mError:\033[0m " __VA_ARGS__)

#define LOG_INFO(...) \
    fprintf(stderr, "\033[0;1mInfo:\033[0m " __VA_ARGS__)

#endif // LOG_H
