#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int init()

{
 puts(" ________  ___       __   ___  ___  ________  _________        ________ _________  ________ \n"
         "|\\   ____\\|\\  \\     |\\  \\|\\  \\|\\  \\|\\   ____\\|\\___   ___\\     |\\   ____\\|___   ___\\\\  _____\\\n"
         "\\ \\  \\___|\\ \\  \\    \\ \\  \\ \\  \\\\\\  \\ \\  \\___|\\|___ \\  \\_|     \\ \\  \\___\\|___ \\  \\_\\ \\  \\__/ \n"
         " \\ \\_____  \\ \\  \\  __\\ \\  \\ \\  \\\\\\  \\ \\_____  \\   \\ \\  \\       \\ \\  \\       \\ \\  \\ \\ \\   __\\\n"
         "  \\|____|\\  \\ \\  \\|\\__\\_\\  \\ \\  \\\\\\  \\|____|\\  \\   \\ \\  \\       \\ \\  \\____   \\ \\  \\ \\ \\  \\_|\n"
         "    ____\\_\\  \\ \\____________\\ \\_______\\____\\_\\  \\   \\ \\__\\       \\ \\_______\\  \\ \\__\\ \\ \\__\\\n"
         "   |\\_________\\|____________|\\|_______|\\_________\\   \\|__|        \\|_______|   \\|__|  \\|__|\n"
         "   \\|_________|                       \\|_________|                                           \n"
         "                                                                                                \n"
         "                                                                                                \n");
         

setvbuf(stdin, 0LL, 2, 0LL);
  setvbuf(stdout, 0LL, 2, 0LL);
  return setvbuf(stderr, 0LL, 2, 0LL);
}
int main() { 
init();
unsigned int seed = time(0);
srand(seed);
int v0=50;
int score=0;
int v1=rand()%999;

while(v0--)
{
	int ans;
	int l=rand()%99;
	int r=rand()%99;
	printf("%d + %d = ",l,r);
	scanf("%d",&ans);
	if(ans==(l+r+v1)%9)
	{
	score+=2;
	printf("ok!\n");
	}
}
printf("%d\n",score);
if(score==100)
{
	system("/bin/sh");
}
return 0;
}
