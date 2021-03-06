#ifndef FS_H
#define FS_H

#include <fsinfo.h>
#include <vfs/vfs.h>
#include <tstr.h>
#include <proto.h>

enum {
	FS_CTRL_NONE = 0,
	FS_CTRL_INFO,
	FS_CTRL_RESET,
	FS_CTRL_ENABLE,
	FS_CTRL_DISABLE,
	FS_CTRL_SET_FONT,
	FS_CTRL_SET_FG_COLOR,
	FS_CTRL_SET_BG_COLOR,
	FS_CTRL_CUSTMIZE
};

int fs_open(const char* name, int32_t flags);

int fs_pipe_open(int fds[2]);

int fs_close(int fd);

int fs_remove(const char* fname);

int fs_info(int fd, fs_info_t* info);

int32_t fs_update(fs_info_t* info);

int fs_finfo(const char* name, fs_info_t* info);

tstr_t* fs_kid(const char* dir_name, int32_t index);

int fs_read(int fd, char* buf, uint32_t size);

int fs_ctrl(int fd, int32_t cmd, const proto_t* input, proto_t* output);

int fs_fctrl(const char* fname, int32_t cmd, const proto_t* input, proto_t* output);

int fs_getch(int fd);

int fs_putch(int fd, int c);

int fs_write(int fd, const char* buf, uint32_t size);

int fs_lseek(int fd, int offset, int whence);

int32_t fs_add(const char* dir_name, const char* name, uint32_t type);

int32_t fs_flush(int fd);

int32_t fs_dma(int fd, uint32_t* size);

char* fs_read_file(const char* fname, int32_t *size);

tstr_t* fs_full_name(const char* fname);

int32_t fs_parse_name(const char* fname, tstr_t* dir, tstr_t* name);

tstr_t* fs_make_fname(const char* dir_name, const char* name);

#endif
