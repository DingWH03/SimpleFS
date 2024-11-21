#ifndef DISK_SPACE_MANAGER_H
#define DISK_SPACE_MANAGER_H

#include <stddef.h>

// 初始化磁盘空间管理器
void disk_space_manager_init(size_t total_blocks, size_t block_size);

// 分配一个空闲块
int allocate_block();

// 释放一个块
int free_block(int block_number);

// 读取指定块数据
int read_block(int block_number, void *buffer);

// 写入指定块数据
int write_block(int block_number, const void *buffer);

#endif // DISK_SPACE_MANAGER_H
