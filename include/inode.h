#ifndef INODE_H
#define INODE_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t size;              // 文件大小
    uint32_t direct_blocks[12]; // 直接块指针
    uint32_t indirect_block;    // 间接块指针
    uint32_t double_indirect;   // 双重间接块指针
    uint16_t permissions;       // 权限
    uint32_t ref_count;         // 引用计数
} Inode;

int create_inode();
int delete_inode(uint32_t inode_id);

Inode *get_inode(uint32_t inode_id);
int update_inode(uint32_t inode_id, Inode *inode);


#endif // INODE_H
