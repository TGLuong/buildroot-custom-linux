#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "proc.h"

int main()
{
    struct proc_info *p = malloc(sizeof(struct proc_info));
    long int ret = syscall(449, p);
    printf("%d %s\n", p->pid, p->name);
    while (p->next != NULL) {
        p = p->next;
        printf("%d %s\n", p->pid, p->name);
    }

    return 0;
}
