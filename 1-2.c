#include<stdio.h>

void sender();
void reciever(int *message, int len);

void main()
{
    sender();
}

void sender(){
    int n, a[64], msg[64];
    int j=0, count=0, zcount=0;
    printf("Enter number of bits : "); scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("%dth bit : ", i+1);
        scanf("%d", (a+i));
    }
    
    msg[0] = 0;
    for(j=1; j<=6; j++)
        msg[j] = 1;
    msg[j++] = 0;
    
    for(int i=0; i<n; i++){
        int ch = a[i];
        msg[j++] = ch;
        
        if(ch == 0){
            count = 1;
        }
        else if(ch == 1){
            
            if(count == 5){
                count = 0;
                msg[j++] = 0;
                zcount += 1;
            }
            
            else if(count != 0)
                count += 1;
        }
    }
    
    msg[j++] = 0;
    for(int i=0; i<6; i++)
        msg[j++] = 1;
    msg[j++] = 0;

    int len = 16 + zcount + n;
    printf("The length is : %d\n", len);
    printf("The Frame sent is : ");
    for(int i=0; i<j; i++){
        printf("%d", *(msg+i));
    }
    
    reciever(msg, len);
}

void reciever(int *message, int len){
    int l = len - 8;
    int msg[64], j=0;
    int count = 0;
    for(int i=8; i<l; i++){
        int ch = message[i];
        
        if(ch == 0)
        {
            if(count == 6){
                i += 1;
                count = 0;
            }
            else
                count = 1;
        }
        else if(ch == 1){
            if(count != 0)
                count += 1;
        }
        
        msg[j++] = message[i];
    }
    
    printf("\nThe Frame recieved is : ");
    for(int i=0; i<j; i++){
        printf("%d", *(msg+i));
    }
}
