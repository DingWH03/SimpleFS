#ifndef DISK_SPACE_MANAGER_H
#define DISK_SPACE_MANAGER_H

#include <stddef.h>
#include <cstdint>

typedef struct {
    uint8_t *bitmap;    // 位图，标记每个块的使用情况
    uint32_t total_blocks; // 总块数
    uint32_t free_blocks;  // 空闲块数
} DiskSpaceManager;

int allocate_block();
int free_block(uint32_t block_id);

int init_disk_space_manager(uint32_t total_blocks);

uint32_t get_free_block_count();


#endif // DISK_SPACE_MANAGER_H
