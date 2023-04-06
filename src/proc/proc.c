#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "proc.h"

int get_proc(struct proc_info **list_proc) 
{
    struct proc_info *head = calloc(1, sizeof(struct proc_info));
    struct proc_info *tail = head;
    struct proc_info list[50];
    int size;

    syscall(449, list, &size);
    for (int i = 0; i < size; i++) {
        struct proc_info *new_node = calloc(1, sizeof(struct proc_info));
        new_node->pid = list[i].pid;
        new_node->next = NULL;
        strcpy(new_node->name, list[i].name);
        printf("new node: %d %s\n", new_node->pid, new_node->name);

        tail->next = new_node;
        tail = tail->next;
    }

    *list_proc = head;
}