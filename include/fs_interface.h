#ifndef FS_INTERFACE_H
#define FS_INTERFACE_H

#include <stddef.h>
#include <sys/types.h>

int fs_init();
int fs_mount(const char *disk_image);
int fs_unmount();

int fs_create(const char *path);
int fs_delete(const char *path);
int fs_rename(const char *old_path, const char *new_path);


#endif // FS_INTERFACE_H
