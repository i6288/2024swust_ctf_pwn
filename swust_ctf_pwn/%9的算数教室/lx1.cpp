#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() { 
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
	printf("%d\n",(l+r+v1)%9);

}

return 0;
}
