#include "proc.h"
#include <stdio.h>

int main()
{
    struct proc_info *list_proc;
    get_proc(&list_proc);

    for (;(list_proc = list_proc->next) != NULL;) {
        printf("%d %s\n", list_proc->pid, list_proc->name);
    }

    return 0;
}