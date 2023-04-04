#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/proc.h>
#include <linux/gfp.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/string.h>

SYSCALL_DEFINE1(procinfo, const int __user *, pid) {
	int *i = kmalloc(sizeof(int), GFP_USER);
	copy_from_user(i, pid, sizeof(int));
	printk(KERN_INFO "CALL procinfo, addr: %d\n", i);

	return 0;
}
