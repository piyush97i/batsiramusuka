#include <types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <syscall.h>
#include <ext2.h>

static int32_t read_block(int32_t block, char* buf) {
	if(syscall1(SYSCALL_SDC_READ, block) < 0)
		return -1;

	int32_t res = -1;
	while(true) {
		res = syscall1(SYSCALL_SDC_READ_DONE, (int32_t)buf);
		if(res == 0)
			break;
		yield();
	}
	return 0;
}

int main() {
	int32_t size;
	char* p = ext2_load("/sbin/vfsd", read_block, malloc, free, &size);
		
	if(p != NULL)
		free(p);
	return 0;
}

