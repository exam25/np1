#include<stdio.h>
#include<string.h>

void reciever(char *data);

void sender(){
    
    char data[256];
    
    int n;
    
    printf("Number of Frames : ");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        char buf[64];
        char len[4];
        
        printf("Enter Frame %d : ", i+1);
        scanf(" %s", buf);
        
        int l = strlen(buf);
        sprintf(len, "%d", l);
        
        printf("Frame Length is %d\n", l);
        
        strcat(data, len);
        strcat(data, buf);
    }
    reciever(data);
}

void reciever(char *data){
    int i = 0;
    printf("Data recieved : %s\n", data);
    
    while(data[i] != '\0'){
        char *buf;
        int len = (int)data[i++] - (int)'0';
        int s = i;
        printf("\nLength: %d\nData: ", len);
        for(; i<s+len; i++)
            printf("%c", data[i]);
        printf("\n");
    }
}

void main(){
    sender();
}
