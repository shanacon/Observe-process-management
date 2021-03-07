#include<linux/init.h>
#include<linux/sched.h>
#include<linux/module.h>
#include <linux/types.h>
asmlinkage int get_procnum_ofpid(int pid)
{
    struct task_struct *task = NULL;
    struct task_struct *tgl = NULL;
    int count_ret = 0;
    pid_t now;
    tgl = pid_task(find_vpid(pid),PIDTYPE_PID);
    for_each_process(task)
    {
	now = task->tgid;
        printk("compare:%d %d\n",now,tgl->tgid);
	if(now==tgl->tgid)
	    count_ret++;
    }
    return count_ret;
}
