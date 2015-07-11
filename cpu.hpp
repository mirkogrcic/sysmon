#include <stdint.h>

struct CPU_TIME{
    uint64_t user;
    uint64_t userLow; //  Time spent in user mode with low priority (nice)
    uint64_t sys;
    uint64_t idle;
};

struct CPU_TIME_PROCESS{
    char* command;
    uint32_t command_len;
    CPU_TIME* cpu_time;
};


CPU_TIME* get_cpu_time(uint32_t cpu=0); // 0 for all, 1 based
uint32_t get_cpu_count();
double get_cpu_percent(CPU_TIME* time_low, CPU_TIME* time_high=NULL);
