#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>
#include <cstdint>

// 打印错误信息
void print_error(const char *message);

// 分割路径，返回目录和文件名
int split_path(const char *path, char **directory, char **filename);

// 对内存进行对齐
void *aligned_alloc(uint32_t alignment, uint32_t size);

int path_to_inode(const char *path, uint32_t *inode_id);
void *read_block(uint32_t block_id);
int write_block(uint32_t block_id, const void *buf);


#endif // UTILS_H
