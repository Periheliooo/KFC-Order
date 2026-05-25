// 124033910070 GTY SJTU-CS
// Created on 2025.4.22, Jiangchuan Rd., Minhang

#include <iostream>
#include "alloc-monitor.h"

using namespace std;

void AllocMonitor::add(void* addr, int type) {
    Node* n = (Node*) calloc(1, sizeof(Node));
    n->addr = addr;
    n->type = type;
    if (!node)
        node = n;
    else {
        n->next = node;
        node = n;
    }
}


void AllocMonitor::ensure(void* addr, int type) {
    Node* p = node;
    while (p) {
        if (p->addr == addr && p->type == type)
            return;
        else if (p->addr == addr) {
            cout << "分配释放方式不匹配！请联系助教检查。" << endl;
            exit(-1);
        }

        p = p->next;
    }
    cout << "找不到这块内存！" << endl;
    exit(-1);
}


void AllocMonitor::remove(void* addr, int type) {
    ensure(addr, type);
    if (node->addr == addr && node->type == type) {
        Node* p = node;
        node = p->next;
        free(p);
        return;
    }

    Node* prev = node;
    Node* curr = node->next;
    while (true) {
        if (curr->addr == addr && curr->type == type) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = prev->next;
        curr = curr->next;
    }
}


AllocMonitor::~AllocMonitor() {
    if (node) {
        cout << "内存没释放干净！请联系助教检查。" << endl;
        exit(-1);
    }
}



void* operator new (size_t size) {
    void* addr = malloc(size);
    if (!addr)
        return addr;
    allocMonitor.add(addr, 0);
    return addr;
}


void* operator new[] (size_t size) {
    void* addr = malloc(size);
    if (!addr)
        return addr;
    allocMonitor.add(addr, 1);
    return addr;
}


void operator delete (void* addr) {
    allocMonitor.remove(addr, 0);
    free (addr);
}


void operator delete[] (void* addr) {
    allocMonitor.remove(addr, 1);
    free (addr);
}
