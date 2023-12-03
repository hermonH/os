#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char buffer[50];
	//sprintf(buffer,"My name is Asad.");
	FILE *rd;
	rd=popen("ls","r");
	fread(buffer,sizeof(char),20,rd);
	write(1,buffer,20);
	pclose(rd);
}



