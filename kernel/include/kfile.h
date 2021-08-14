#ifndef KFILE_H
#define KFILE_H

#include <types.h>

#define KF_READ 	0x0
#define KF_WRITE 0x1

typedef struct KFile {
	struct KFile* next;
	struct KFile* prev;

	uint32_t fsNodeAddr;
	uint16_t refR;
	uint16_t refW;
} KFileT;

KFileT* kfOpen(uint32_t fsNodeAddr);

void kfRef(KFileT* kf,  uint32_t flags);

void kfUnref(KFileT* kf, uint32_t flags);

#endif
