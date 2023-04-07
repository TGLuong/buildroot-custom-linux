#include "proc.h"
#include <stdio.h>

int main()
{
    struct proc_info *list_proc;
    get_proc(&list_proc);

    for_each_proc(proc, list_proc) {
        printf("%d %s\n", proc->pid, proc->name);
    }

    free_proc(&list_proc);

    return 0;
}