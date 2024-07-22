#ifndef STDLIB_H
#define STDLIB_H

#include <types.h>

void* malloc(uint32_t size);
void free(void* p);

mem_funcs_t* mem_funcs();
#define MFS mem_funcs()

int32_t atoi(const char *str);
int32_t atoi_base(const char *str, int32_t base);

int32_t setenv(const char* name, const char* value);
const char* getenv(const char* name);

#endif
