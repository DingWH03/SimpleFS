#ifndef INODE_H
#define INODE_H

#include <stddef.h>
#include <stdint.h>

// 初始化inode管理器
void inode_manager_init();

// 创建一个inode
int create_inode(uint32_t mode, uint32_t uid, uint32_t gid);

// 删除inode
int delete_inode(int inode_number);

// 获取inode信息
int get_inode(int inode_number, void *inode_info);

// 更新inode信息
int update_inode(int inode_number, const void *inode_info);

#endif // INODE_H
