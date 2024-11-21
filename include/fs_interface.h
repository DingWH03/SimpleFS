#ifndef FS_INTERFACE_H
#define FS_INTERFACE_H

#include <stddef.h>
#include <sys/types.h>

// 打开文件
int fs_open(const char *path, int flags);

// 关闭文件
int fs_close(int fd);

// 读取文件
ssize_t fs_read(int fd, void *buf, size_t count);

// 写入文件
ssize_t fs_write(int fd, const void *buf, size_t count);

// 删除文件
int fs_unlink(const char *path);

// 创建文件
int fs_create(const char *path);

#endif // FS_INTERFACE_H
