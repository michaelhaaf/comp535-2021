
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


err_t
rdp_send(struct udp_pcb *pcb, struct pbuf *p)
{
  /* send to the packet using remote ip and port stored in the pcb */
  return udp_sendto(pcb, p, pcb->remote_ip, pcb->remote_port);
}


#if RDP_DEBUG
void rdp_debug_print(struct udp_hdr *udphdr);
#else
#define rdp_debug_print(udphdr)
#endif
