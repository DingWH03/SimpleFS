#ifndef FS_OPERATIONS_H
#define FS_OPERATIONS_H

#include <stddef.h>
#include <unistd.h>
#include <cstdint>

ssize_t fs_read(const char *path, void *buf, uint32_t size, off_t offset);
ssize_t fs_write(const char *path, const void *buf, uint32_t size, off_t offset);

int fs_stat(const char *path, struct stat *buf);


#endif // FS_OPERATIONS_H
