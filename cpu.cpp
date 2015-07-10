#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdint.h>

#include "cpu.hpp"

CPU_TIME* get_cpu_time(){
    CPU_TIME* res = new CPU_TIME();
    FILE* file = fopen("/proc/stat", "r");
    if(file == NULL) return NULL;
    fscanf(file, "cpu %Ld %Ld %Ld %Ld",
        (unsigned long long*)&res->user,
        (unsigned long long*)&res->userLow,
        (unsigned long long*)&res->sys,
        (unsigned long long*)&res->idle);
    fclose(file);
    return res;
}

uint8_t get_cpu_count(){
    return 0;
}

uint16_t get_cpu_percent(){

    return 0;
}
