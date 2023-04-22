#include "custom_logger.h"
#include <stdint.h>

int main(int argc, char *argv[])
{
    DEBUG_LOG("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ test debug logs ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    uint32_t num = 4294901796u;
    DEBUG_LOG("hex format print of %u: [0x%x]", num, num);
    DEBUG_LOG("---------- number of arguments with this executable : [%d] ----------", argc);
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            DEBUG_LOG("argument number %d: %s ", i, argv[i]);
        }
    } else {
        DEBUG_LOG("no arguments.");
    }
    return 0;
}