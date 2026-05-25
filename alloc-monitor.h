// 124033910070 GTY SJTU-CS
// Created on 2025.4.22, Jiangchuan Rd., Minhang


#pragma once

#include <cstdlib>

// ---------------------------------------------------------
// 下面是一个基于链表的内存分配登记器，用于追踪你的 new delete 过程。
// 这部分代码只是用于发现你有没有 new delete 用错的地方。
// 你不需要理解这是怎么实现的。当然如果特别感兴趣，可以阅读一下。
// 本作业的要求请往后看。

struct AllocMonitor {
    struct Node {
        void* addr;
        int type;
        Node* next;
    } *node = nullptr;

    void add(void* addr, int type);
    void ensure(void* addr, int type);
    void remove(void* addr, int type);
    ~AllocMonitor();
} static allocMonitor;


void* operator new (size_t size);
void* operator new[] (size_t size);
void operator delete (void* addr);
void operator delete[] (void* addr);


// 内存管理监控代码到此结束。
// ---------------------------------
