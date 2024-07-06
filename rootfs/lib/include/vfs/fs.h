#ifndef FS_H
#define FS_H

#include <fsinfo.h>
#include <vfs/vfs.h>
#include <tstr.h>

int fs_open(const char* name, int32_t flags);

int fs_pipe_open(int fds[2]);

int fs_close(int fd);

int fs_remove(const char* name);

int fs_info(int fd, fs_info_t* info);

int fs_ninfo(uint32_t node, fs_info_t* info);

int fs_ninfo_update(fs_info_t* info);

int fs_finfo(const char* name, fs_info_t* info);

int fs_kid(int fd, int32_t index, fs_info_t* info);

int fs_read(int fd, char* buf, uint32_t size);

int fs_ctrl(int fd, int32_t cmd, void* input, uint32_t isize, void* output, uint32_t osize);

int fs_getch(int fd);

int fs_putch(int fd, int c);

int fs_write(int fd, const char* buf, uint32_t size);

uint32_t fs_add(int dir_fd, const char* name, uint32_t type);

int32_t fs_flush(int fd);

int32_t fs_dma(int fd, uint32_t* size);

char* fs_read_file(const char* fname, int32_t *size);

tstr_t* fs_full_name(const char* fname);

int32_t fs_parse_name(const char* fname, tstr_t* dir, tstr_t* name);

#endif
