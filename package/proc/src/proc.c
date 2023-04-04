#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "proc.h"

int abc(int *i) {
	printf("addr: %x, val: %d\n", i, *i);
}

int main()
{
	int i = 10;
        long int ret = syscall(449, &i);
        return 0;
}
