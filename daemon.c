#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/syslog.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int init_daemon(const char *pname,int facility) {
	int pid;
	int i;
	/*忽略可能的终端信号*/
	signal(SIGTTOU,SIG_IGN);
	signal(SIGTTIN,SIG_IGN);
	signal(SIGTSTP,SIG_IGN);
	signal(SIGHUP,SIG_IGN);
	//创建子进程，父进程推出
	if( (pid=fork())) {
		exit(EXIT_SUCCESS);//是父进程，结束父进程，子进程继续
	} else if(pid < 0) {
		perror("fork error!\n");
		exit(EXIT_FAILURE);
	} 

	setsid();//设置新会话组长，脱离终端
	for(i=0;i<NOFILE;i++) {
		close(i);
	}

	open("/dev/null",O_RDONLY);
	open("/dev/null",O_RDWR);
	open("/dev/null",O_RDWR);

	chdir("/");
	umask(0);
	signal(SIGCHLD,SIG_IGN);

	openlog(pname,LOG_PID,facility);

	return 0;
}

int main(int argc,char *argv[]) {
	time_t ticks;
	init_daemon(argv[0],LOG_KERN);
	while(1) {
		sleep(1);
		ticks = time(NULL);                              //读取当前时间
		syslog(LOG_INFO,"%s",asctime(localtime(&ticks)));//写日志信息
	}
	return 0;
}
