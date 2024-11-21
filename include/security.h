#ifndef SECURITY_H
#define SECURITY_H

#include <stdint.h>

// 检查用户对路径的权限
int check_permission(const char *path, uint32_t uid, uint32_t gid, int permissions);

// 设置文件权限
int set_permissions(const char *path, int permissions);

// 设置文件所有者
int set_owner(const char *path, uint32_t uid, uint32_t gid);

#endif // SECURITY_H
