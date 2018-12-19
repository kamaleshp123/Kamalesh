#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void signal_handler(int sig)
{

printf("catch %d",sig);
exit(sig);
}


int main()
{

signal(SIGINT,signal_handler);
while(1){
printf("1\n");
sleep(1);
}

}
