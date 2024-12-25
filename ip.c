#include <stdio.h>
#include <math.h>

void printip(unsigned int ip){
    printf("%u.%u.%u.%u", (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
}

int main(){
    unsigned int baseIP[4], ipInt = 0, hostcount, increment, maxHosts, mask;
    int prefix;

    printf("enter in CIDR format:\n ");
   scanf("%u.%u.%u.%u/%d", &baseIP[0], &baseIP[1], &baseIP[2], &baseIP[3], &prefix);
   ipInt = (baseIP[0] << 24) | (baseIP[1] << 16) | (baseIP[2] << 8) | (baseIP[3]);
   printf("enter no of hosts\n");
   scanf("%u", &hostcount);
   int reqbits = (int)ceil(log2(hostcount + 2));
   unsigned int newPf = 32 - reqbits;
   increment = pow(2, reqbits);
   maxHosts = increment - 2;
    unsigned int subnet_count = pow(2, newPf - prefix);
    for(unsigned int i = 0; i < subnet_count; i++){
        unsigned int startIp = ipInt + (i * increment);
        unsigned int endIp = startIp + increment;
        printip(startIp);
        printf(" - ");
        printip(endIp);
        printf("\n");
    }
}