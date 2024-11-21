#ifndef FS_OPERATIONS_H
#define FS_OPERATIONS_H

#include <stddef.h>

// 文件系统操作函数表
struct fs_operations {
    int (*open)(const char *path, int flags);
    int (*close)(int fd);
    ssize_t (*read)(int fd, void *buf, size_t count);
    ssize_t (*write)(int fd, const void *buf, size_t count);
    int (*unlink)(const char *path);
    int (*create)(const char *path);
};

extern struct fs_operations simplefs_operations;

#endif // FS_OPERATIONS_H
