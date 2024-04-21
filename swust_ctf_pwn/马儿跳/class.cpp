
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void ucatch();
void show();
void dance();
int index();

struct UMA {
    char name[0x20];
    void* Introduction;
  //  void (*dance)();
};

struct UMA *list[10] = {NULL};

int main() {
    int cmd;

    while (1) {
    puts("---------");
    puts("UMA Dance!");
    puts("---------\n");
    puts("1. catch");
    puts("2. show hourse");
    puts("3. dance");
    puts("4. exit\ninput:");
        scanf("%d",&cmd);
        switch (cmd) {
            case 1:
                ucatch();
                break;
            case 2:
                show();
                break;
            case 3:
                dance();
                break;
            case 4:
                exit(0);
            default:
                break;
        }
    }
}

void ucatch() {
	int k;
    int i = index();
    list[i] = (struct UMA*)malloc(sizeof(struct UMA));
    puts("name:");
    read(0,list[i]->name,32);
    puts("Introduction size:\n");
    scanf("%d",&k);
    list[i]->Introduction=malloc(k);
    puts("content:\n");
    read(0,list[i]->Introduction,k);
}

void show()
{
	int i=index();
	puts(list[i]->name);
	puts((const char*)list[i]->Introduction);
}
void dance()
{
	int i = index();
	puts("　　　　　　/ヾ∧\n"
	     "　　　　彡|　・　＼\n"
	     "　　　　彡|　丶.＿）))\n"
	     "　　　((　(　つ 　ヽ、♪\n"
	     "　　♪　　. 〉 とノ　i　))\n"
	     "　　　　　（__ノ^（＿）♪\n"   );
	free(list[i]->Introduction);
}
int index() {
	printf("index: ");
    char buf[0x10];
    buf[read(0, buf, 0xf)] = 0;
    return atoi(buf);
}

__attribute__((constructor))
void init()
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
  setvbuf(stderr, 0LL, 2, 0LL);
}
