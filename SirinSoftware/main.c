#include<pcap.h>
#include<stdio.h>
#include<stdlib.h> // for exit()
#include<string.h> //for memset

#include<sys/socket.h>
#include<arpa/inet.h> // for inet_ntoa()
#include<net/ethernet.h>
#include<netinet/tcp.h>   //Provides declarations for tcp header
#include<netinet/ip.h>    //Provides declarations for ip header

int     count = 0;

void    process_count(unsigned char *args, const struct pcap_pkthdr *header, const unsigned char *buffer)
{
    struct iphdr *iph = (struct iphdr*)(buffer + sizeof(struct ether_header));
    printf("IP address: %s\n", inet_ntoa(iph->saddr) )
    count++;
}

int main() {
    char    errbuf[100];
    pcap_t  *handle;
    handle = pcap_open_live("wlan1", 65536, 1, 0, errbuf);
    if (handle == NULL)
    {
        printf("%s\n", errbuf);
        exit(1);
    }
    pcap_loop(handle, 5, process_count, NULL);
    printf("packets count = %d\n", count);
    return 0;
}