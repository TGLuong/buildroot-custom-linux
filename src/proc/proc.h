#ifndef _CUSTOME_PROC_H
#define _CUSTOME_PROC_H

struct proc_info {
	int	pid;
	char name[100];
	struct proc_info *next;
};

int get_proc(struct proc_info **list_proc);
int free_proc(struct proc_info **head);

#define for_each_proc(p, list) \
    for (struct proc_info *p = list; (p = p->next) != NULL; )

#endif
