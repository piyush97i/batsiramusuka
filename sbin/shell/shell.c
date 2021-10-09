#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <kserv/fs.h>

#define KEY_BACKSPACE 127
#define KEY_LEFT 0x8

static void gets(char* buf, int len) {
	int i = 0;
	while(true) {
		if(i >= len)
			break;

		int c = getch();
		if(c == 0) {
			yield();
			continue;
		}

		if (c == KEY_BACKSPACE) {
			if (i > 0) {
				//delete last char
				putch(KEY_LEFT); 
				putch(' ');
				putch(KEY_LEFT); 
				i--;
			}
		}
		else {
			putch(c);
			if(c == '\r' || c == '\n')
				break;
			buf[i] = c;
			i++;
		}
	}
	buf[i] = 0;
}

static int cd(const char* dir) {
	char cwd[FNAME_MAX];
	if(getcwd(cwd, FNAME_MAX) == NULL)
		return -1;

	if(strcmp(dir, ".") == 0)
		return 0;

	while(*dir == ' ') /*skip all space*/
		dir++;

	if(dir[0] == 0) {
		chdir("/");
		return 0;
	}

	if(strcmp(dir, "..") == 0) {
		if(strcmp(cwd, "/") == 0)
			return 0;

		int len = strlen(cwd)  - 1;
		for(int i=len; i>=0; i--) {
			if(cwd[i] == '/') {
				cwd[i] = 0;
				break;
			}
		}
		if(cwd[0] == 0) {
			chdir("/");
			return 0;
		}
	}
	else if(dir[0] == '/') {
		strncpy(cwd, dir, FNAME_MAX);
	}
	else {
		int len = strlen(cwd);
		if(cwd[len-1] != '/') {
			cwd[len] = '/';
			len++;
		}
		strcpy(cwd+len, dir);
	}

	FSInfoT info;
	if(fsFInfo(cwd, &info) != 0)
		printf("[%s] not exist!\n", dir);	
	else if(info.type != FS_TYPE_DIR)
		printf("[%s] is not a directory!\n", dir);	
	else 
		chdir(cwd);
	return 0;
}

static int handle(const char* cmd) {
	if(strcmp(cmd, "cd") == 0) {
		return cd("/");
	}
	else if(strncmp(cmd, "cd ", 3) == 0) {
		return cd(cmd + 3);
	}

	return -1; /*not shell internal command*/
}

#define CMD_MAX 128

void _start() {
	char cmd[CMD_MAX];
	char cwd[FNAME_MAX];

	int uid = getuid();

	while(1) {
		if(uid == 0)
			printf("ewok:%s.# ", getcwd(cwd, FNAME_MAX));
		else
			printf("ewok:%s.$ ", getcwd(cwd, FNAME_MAX));

		gets(cmd, CMD_MAX);
		if(cmd[0] == 0)
			continue;

		if(strcmp(cmd, "exit") == 0)
			break;

		if(handle(cmd) == 0)
			continue;

		int child_pid = fork();
		if (child_pid == 0) {
			if(exec(cmd) != 0) {
				printf("unknown command: '%s'.\n", cmd);
				exit(0);
			}
		}
		else {
			wait(child_pid);
		}
	}
	exit(0);
}
