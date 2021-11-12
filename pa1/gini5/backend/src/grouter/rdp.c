
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include "grouter.h"
#include "ip.h"
#include "udp.h"
#include "err.h"
#include "debug.h"
#include "memp.h"
#include "protocols.h"
#include "opt.h"


// i think it's actually the udp_recv_fn i care about here
void
rdp_recv(struct udp_pcb *pcb, udp_recv_fn recv, void *recv_arg)
{
  /* remember recv() callback and user data */
  pcb->recv = recv;
  pcb->recv_arg = recv_arg;
}


err_t
rdp_send(struct udp_pcb *pcb, struct pbuf *p)
{
  /* send to the packet using remote ip and port stored in the pcb */
  return udp_sendto(pcb, p, pcb->remote_ip, pcb->remote_port);
}


/*
 * callback function for RDP packets received
 */
void rdp_recv_callback(void *arg, struct udp_pcb *pcb, struct pbuf *p, uchar *addr, uint16_t port) {
    printf("%s", (char*)p->payload);
    uchar ipaddr_network_order[4];
    gHtonl(ipaddr_network_order, addr);
    udp_connect(arg, ipaddr_network_order, port);
}


#if RDP_DEBUG
void rdp_debug_print(struct udp_hdr *udphdr);
#else
#define rdp_debug_print(udphdr)
#endif
