#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include "cpu.hpp"

CPU_TIME* get_cpu_time(uint32_t cpu){
    CPU_TIME* res = new CPU_TIME();
    FILE* file = fopen("/proc/stat", "r");
    if(file == NULL) return NULL;
    char* fmt = new char[100];
    if(cpu){
        sprintf(fmt, "cpu%d %%Ld %%Ld %%Ld %%Ld", cpu-1);
    }else{
        sprintf(fmt, "cpu %%Ld %%Ld %%Ld %%Ld");
    }
    fscanf(file, fmt,
        (unsigned long long*)&res->user,
        (unsigned long long*)&res->userLow,
        (unsigned long long*)&res->sys,
        (unsigned long long*)&res->idle);
    fclose(file);
    delete fmt;
    return res;
}

uint32_t get_cpu_count(){
    FILE* file;
    char* line;
    uint32_t cpu_count;

    file = fopen("/proc/cpuinfo", "r");
    line = new char[128];
    cpu_count = 0;

    while(fgets(line, 128, file) != NULL){
        if (strncmp(line, "processor", 9) == 0)
            cpu_count++;
    }
    fclose(file);
    delete line;
    return cpu_count;
}

double get_cpu_percent(CPU_TIME* time_low, CPU_TIME* time_high){
    CPU_TIME delta;
    if(time_high){
        delta.user = time_high->user - time_low->user;
        delta.userLow = time_high->userLow - time_low->userLow;
        delta.sys = time_high->sys - time_low->sys;
        delta.idle = time_high->idle - time_low->idle;
    }else{
        delta = *time_low;
    }
    if((int64_t)delta.user < 0 || (int64_t)delta.userLow < 0 || (int64_t)delta.sys < 0)
        return -1;
    uint64_t total = delta.user + delta.userLow + delta.sys;
    double percent = (double)total / (total + delta.idle);
    percent *= 100;
    return percent;
}


