#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/ip.h>

void func(int conn) {
    for(;;){
        char buf[80];
        int n = 0;
			
			printf("\tClient : ");
        while ((buf[n++] = getchar()) != '\n');

        write(conn, buf, sizeof(buf));

        if (strncmp(buf, "exit", 4) == 0){
        		printf("exit");
            break;}
            
        bzero(buf, sizeof(buf));

        read(conn, buf, 80);
        printf("Server: %s\n", buf);       
        
    }
}

int main() {
    int sock, conn;
    struct sockaddr_in svr, cli;

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    printf("Socket created\n");

    // assign address and port
    svr.sin_addr.s_addr = INADDR_ANY;
    svr.sin_port = htons(8080);
    svr.sin_family = AF_INET;

    connect(sock, (struct sockaddr*)&svr, sizeof(svr));
    
    printf("Connection created\n");

    func(sock);

    close(sock);

    return 0;
}
