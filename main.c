#include<stdio.h>
#include<malloc.h>
#include<sys/ioctl.h>
#include<bits/ioctls.h>
#include<net/if.h>
#include<sys/socket.h>
#include <bits/sockaddr.h>
#include <netinet/in.h>

#define __USE_MISC	1

char number_to_char(int n){
    /*switch(n){
        case 0: return "0";
        case 1: return "1";
        case 2: return "2";
        case 3: return "3";
        case 4: return "4";
        case 5: return "5";
        case 6: return "6";
        case 7: return "7";
        case 8: return "8";
        case 9: return "9";
    }*/

    switch(n){
        case 0: return '0';
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8: return '8';
        case 9: return '9';
    }
}

char* generate_mac(){
    char* mac_address;
    mac_address = (char*)malloc(sizeof(char) * 16);
    mac_address[0] = number_to_char(1);
    mac_address[1] = number_to_char(3);
    mac_address[2] = ':';
    mac_address[3] = number_to_char(6);
    mac_address[4] = number_to_char(7);
    mac_address[5] = ':';
    mac_address[6] = number_to_char(7);
    mac_address[7] = 'e';
    mac_address[8] = ':';
    mac_address[9] = number_to_char(3);
    mac_address[10] = number_to_char(9);
    mac_address[11] = ':';
    mac_address[12] = 'd';
    mac_address[13] = number_to_char(7);
    mac_address[14] = ':';
    mac_address[15] = number_to_char(1);
    mac_address[16] = number_to_char(8);
    return mac_address;
}

void ch_mac(){
    struct ifreq ir{.ifr_name="wlo1", .ifr_hwaddr=(struct sockaddr){.sa_family=ARPHRD_ETHER, .sa_data=generate_mac()}};

    ioctl(4, SIOCSIFHWADDR, (struct ifreq){.ifr_name="wlo1", .ifr_hwaddr=(struct sockaddr){.sa_family=ARPHRD_ETHER, .sa_data=generate_mac()}});
}

int main(){
    printf("%s\n", generate_mac());
}