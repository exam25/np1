#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/ip.h>
#include<sys/socket.h>

void main(){
    int sock, conn;
    struct sockaddr_in ser, cli;
    
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    printf("Socket Created\n");
    
    ser.sin_family = AF_INET;
    ser.sin_addr.s_addr = INADDR_ANY;
    ser.sin_port = htons(8080);

    bind(sock, (struct sockaddr*)&ser, sizeof(ser));
    printf("Socket Bound\n");
    
    for(;;){
    
   	 char buf[1024];
   	 int n;
   	 
   	 int len = sizeof(ser);
   	 printf("Litsening.....\n");
   	 n = recvfrom(sock, buf, 1024, MSG_WAITALL, (struct sockaddr*)&cli, &len);
   	 buf[n] = '\0';
   	 printf("Client said %s\n", buf);
   	 
   	 n = 0;
   	 bzero(buf, 1024);
   	 printf("You say ");
   	 while((buf[n++] = getchar()) != '\n');
   	 sendto(sock, buf, n, MSG_CONFIRM, (struct sockaddr*)&cli, len);
   	 
    }
}
