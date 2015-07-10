#include <stdint.h>

struct CPU_TIME{
    uint64_t user;
    uint64_t userLow; //  Time spent in user mode with low priority (nice)
    uint64_t sys;
    uint64_t idle;
};

CPU_TIME* get_cpu_time();
