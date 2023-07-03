#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/ip.h>

void func(int conn) {
    for(;;) {
        char buf[80];
        int n = 0;
		
	read(conn, buf, sizeof(buf));
        printf("Client: %s\n", buf);

        bzero(buf, 80);

        printf("\tServer : ");
        while ((buf[n++] = getchar()) != '\n');

        write(conn, buf, sizeof(buf));

        if (strncmp(buf, "exit", 4) == 0){
        		printf("exit");
            break;}
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

    // bind
    bind(sock, (struct sockaddr*)&svr, sizeof(svr));
    printf("Socket bound\n");

    // wait for client
    listen(sock, 5);
    printf("Listening for connections\n");

    int len = sizeof(cli);
    conn = accept(sock, (struct sockaddr*)&cli, &len);
    if(conn > 0)
    	printf("Connection created\n");

    func(conn);

    close(conn);
    close(sock);

    return 0;
}
