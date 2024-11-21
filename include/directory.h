#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <stddef.h>

// 初始化目录模块
void directory_init();

// 创建目录
int create_directory(const char *path);

// 删除目录
int delete_directory(const char *path);

// 列出目录内容
int list_directory(const char *path, char ***contents, size_t *count);

#endif // DIRECTORY_H
