#include <stdio.h>
#include <stdlib.h>

int main(void)

{
	FILE *fp,*fp_out;
	int n;
	char buf[1024] = {0};
	fp = fopen("dict.txt","r");
	if(fp == NULL)
		{
			perror("fopen error");
			exit(1);
		}
	fp_out = fopen("dict.cp","w");

	if(fp == NULL)
		{
			perror("fopen error");

			exit(1);
		}
	char *p;
	while((p = fgets(buf,4096,fp)) !=NULL)
		{

			fputs(buf,fp_out);

		}
	fclose(fp);
	fclose(fp_out);
	return 0;
}