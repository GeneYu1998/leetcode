#include <stdio.h>

#define DEBUG_LOG(fmt, ...) \
printf("\n[%s:%d] ", __FILE_NAME__, __LINE__); printf(fmt, ##__VA_ARGS__); printf("\n")
