#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/proc.h>
#include <linux/gfp.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/string.h>

SYSCALL_DEFINE1(procinfo, struct proc_info __user *, proc) {
    int proc_info_size = sizeof(struct proc_info);
    struct proc_info *proc_head = kmalloc(proc_info_size, GFP_KERNEL);
    struct proc_info *proc_user = kmalloc(proc_info_size, GFP_KERNEL);
    copy_from_user(proc_user, proc, proc_info_size);

    struct proc_info *proc_tail = proc_head;
    struct task_struct *task_list;

    for_each_process(task_list) {
        struct proc_info *new_node = kmalloc(proc_info_size, GFP_KERNEL);

        new_node->pid = task_list->pid;
        new_node->next = NULL;
        strcpy(new_node->name, task_list->comm);

        proc_tail->next = new_node;
        proc_tail = new_node;
    }

    copy_to_user(proc, proc_user, proc_info_size);
    copy_to_user(proc_user->next, proc_head->next, proc_info_size);

    struct proc_info *ele = proc_head;
    while (ele->next != NULL) {
        ele = ele->next;
        printk(KERN_INFO "PRINT NODE: %d %s\n", ele->pid, ele->name);
    }

    


    return 0;
}
