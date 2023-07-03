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
    
    ser.sin_family = AF_INET;
    ser.sin_addr.s_addr = INADDR_ANY;
    ser.sin_port = htons(8080);
    
    for(;;){
    
   	 char buf[1024];
   	 int n;
   	 int len = sizeof(ser);
   	 
   	 n = 0;
   	 bzero(buf, 1024);
   	 printf("You say ");
   	 while((buf[n++] = getchar()) != '\n');
   	 sendto(sock, buf, n, MSG_CONFIRM, (struct sockaddr*)&ser, len);
   	 
   	 n = 0;
   	 bzero(buf, 1024);
   	 
   	 printf("Litsening....\n");
   	 n = recvfrom(sock, buf, 1024, MSG_WAITALL, (struct sockaddr*)&ser, &len);
   	 buf[n] = '\0';
   	 printf("Server said %s\n", buf);
   	 
   	 
   	 
    }
}
