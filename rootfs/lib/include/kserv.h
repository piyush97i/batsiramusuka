#ifndef KSERV_H
#define KSERV_H

#include "package.h"

typedef void (*kserv_func_t) (package_t* pkg, void *p);

typedef void (*kserv_step_func_t) (void *p);

int kserv_register(const char* reg_name);

int kserv_run(kserv_func_t serv_func, void* p, kserv_step_func_t step_func, void* pstep);

int kserv_get_by_name(const char* reg_name);

int kserv_get_by_pid(int32_t pid);

int kserv_ready(void);

void kserv_wait_by_name(const char* reg_name);

void kserv_wait_by_pid(int32_t pid);

#endif
