#include <iostream>
#include <string>
#include <cstring> 
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
class IntToStringConverter {
private:
    std::string result;

public:
    void inputLoop() {
        int num;
        
        while (true) {
            std::cout << "Enter: ";
            std::cin >> num;
            
            if (num == 0) {
                break;
            }
            
            char ch = static_cast<char>(num);
            result += ch;
        }
    }

    void gg() {
    const char* aa=result.c_str();
    if(strlen(aa)==7)
    {
    system(aa);
    }
    else{
    	std::cout<<"try again"<<std::endl;
    }
}
};

int main() {
	init();
    IntToStringConverter converter;
    converter.inputLoop();
    converter.gg();

    return 0;
}