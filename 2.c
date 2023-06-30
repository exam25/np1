#include<stdio.h>                                                                                                                                          

int g, n;
int gen[100], msg[100], rem[100];

void xorval(int s){
    for(int i=0; i<g; i++){
        //rem[i] = (rem[i] == gen[i])? 0:1;
        printf("xor %d: ",i);
        printf("rem : %d |", rem[i]);
        printf("gen : %d\n", gen[i]);
        if(rem[i] == gen[i])
            rem[i] = 0;
        else
            rem[i] = 1;
    }
}

void crc(){
    for(int i=0; i<g; i++){
        rem[i] = msg[i];
    }
    
    for(int i=0; i<n; i++){
        printf("%d = ", i+1);
        for(int i=0; i<g; i++)
            printf("%d",rem[i]);
        printf("\n");
        
        if(rem[0] == 1)
            xorval(i);
        
        printf("%d = ", i+1);
        for(int i=0; i<g; i++)
            printf("%d",rem[i]);
        printf("\n");
        
        for(int j=0; j<g-1; j++)
            rem[j] = rem[j+1];
        rem[g-1] = msg[i+g];
        
        printf("%d = ", i+1);
        for(int i=0; i<g; i++)
            printf("%d",rem[i]);
        printf("\n");
    }
}

void sender(){
    printf("Genertor polynomial length\n"); scanf("%d", &g);
    printf("Genertor polynomial\n");
    for(int i=0; i<g; i++){
        printf("%d : ", (i+1));
        scanf("%d", (gen+i));
    }
    
    printf("Message length\n"); scanf("%d", &n);
    printf("Message\n");
    for(int i=0; i<n; i++){
        printf("%d : ", (i+1));
        scanf("%d", (msg+i));
    }
    
    for(int i=0; i<g-1; i++){
        msg[n+i] = 0;
    }
    
    crc();
    
    for(int i=0; i<g-1; i++)
        printf("%d",rem[i]);
        
    printf("\n");
    
    for(int i=0; i<g-1; i++)
        msg[n+i] = rem[i];
}

void reciever(){
    printf("Recieved Message\n");
    for(int i=0; i<n+g-1; i++){
        printf("%d", *(msg+i));
    }
    
    msg[n-1+2] = 1;
    printf("Recieved Message\n");
    for(int i=0; i<n+g-1; i++){
        printf("%d", *(msg+i));
    }
    crc();
    
    for(int i=0; i<g-1; i++)
        printf("%d",rem[i]);
}

void main(){
    sender();
    reciever();
}
