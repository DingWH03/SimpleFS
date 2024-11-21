#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

// 打印错误信息
void print_error(const char *message);

// 分割路径，返回目录和文件名
int split_path(const char *path, char **directory, char **filename);

// 对内存进行对齐
void *aligned_alloc(size_t alignment, size_t size);

#endif // UTILS_H
