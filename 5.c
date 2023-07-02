#include<stdio.h>

void main(){
    
    int n, leak;
    int flag = 1, sec = 0;
    int incoming[100], remaining[100], sended[100];
    
    printf("Bucket capactity : "); scanf("%d", &n);
    printf("Leak : "); scanf("%d", &leak);
    
    int rem = n;
    
    while(flag){
        printf("Incoming packet at second %d : ", sec+1);
        scanf("%d", &incoming[sec]);
        
        if((incoming[sec] > n) || (incoming[sec] > rem)){
            printf("Bucket Overflow\n");
            return;
        }
        
        rem -= incoming[sec];
        printf("1. %d sec --> %d in bucket.\n",sec+1,n-rem); //test
        if((n-rem) > leak){
            sended[sec] = leak;
            if((rem + leak) < n)
                rem += leak;
            else
                rem = leak;
        }
        else if((n-rem) <= leak){
            sended[sec] = n-rem;
            rem = n;
        }
        else{
            printf("Error");
            return;
        }
        printf("2. %d sec --> %d in bucket.\n",sec+1,n-rem); //test
        remaining[sec] = rem;
        
        sec += 1;
        
        printf("Any more packets? {0:no, 1:yes} : ");
        scanf("%d", &flag);
    }
    
    while(rem < n){
        
        incoming[sec] = 0;
        
        if((n-rem) > leak){
            sended[sec] = leak;
            rem = ((rem+leak) > n)? (rem+leak) : n;
        }
        else if((n-rem) <= leak){
            sended[sec] = n-rem;
            rem = n;
        }
        remaining[sec] = rem;
        
        sec += 1;
    }
    
    printf("Second\tInc\tOut\tRem\n");
    for(int i=0; i<sec; i++)
        printf("%d\t%d\t%d\t%d\n", (i+1), incoming[i], sended[i], remaining[i]);
}
