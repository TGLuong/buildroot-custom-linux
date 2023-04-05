#ifndef _CUSTOME_PROC_H
#define _CUSTOME_PROC_H

struct proc_info {
	int	pid;
	char	name[100];
	struct proc_info *next;
};

#endif
