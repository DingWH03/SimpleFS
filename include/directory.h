#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <stddef.h>
#include <cstdint>

typedef struct {
    char name[256];   // 文件或目录名
    uint32_t inode;   // 对应的索引结点编号
} DirectoryEntry;

typedef struct {
    DirectoryEntry entries[1024]; // 一个目录最多包含的条目数
    uint32_t entry_count;         // 当前目录的条目数
} Directory;


int create_directory(const char *path);
int delete_directory(const char *path);

int add_directory_entry(Directory *dir, const char *name, uint32_t inode);
int remove_directory_entry(Directory *dir, const char *name);


#endif // DIRECTORY_H
