#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

#define N 4096

int main(int argc,char * argv[])

{
	int fd,fd_out;
	int n;
	char buf[N];
	fd = open("./dict.txt",O_RDONLY);
	if(fd < 0)
		{
			perror("open dict.txt error");

			exit(1);
		}
	fd_out = open("./dict.cp",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(fd_out<0)
		{
			perror("open dict.cp error");
			exit(1);
		}
	while((n = read(fd,buf,N)) != 0)
	{
		write(fd_out,buf,n);
	}
	close(fd);
	close(fd_out);

	return 0;

}