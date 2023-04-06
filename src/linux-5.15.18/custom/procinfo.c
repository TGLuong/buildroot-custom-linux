#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/proc.h>
#include <linux/gfp.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/string.h>


SYSCALL_DEFINE2(procinfo, void *, list_proc, int *, out_size)
{
    struct task_struct *task;
    struct proc_info list_kernel_proc[50];
    int size = 0;

    for_each_process(task)
    {
        if (!task_is_running(task))
            continue;
        list_kernel_proc[size].pid = task->pid;
        strcpy(list_kernel_proc[size].name, task->comm);
        size++;
    }

    if (!access_ok(list_proc, size * sizeof(struct proc_info)))
    {
        printk(KERN_INFO "list_proc address invalide!\n");
        return -1;
    }
    if (!access_ok(out_size, sizeof(int)))
    {
        printk(KERN_INFO "out_size address invalide\n");
        return -1;
    }

    copy_to_user(list_proc, list_kernel_proc, size * sizeof(struct proc_info));
    copy_to_user(out_size, &size, sizeof(int));

    return 0;
}