
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
  // TODO: add timer paramter to rdp_send function (global variable in cli.c)
  // then:
  // t.start()      
  //
  // // the timer either stops because we go over the max time,
  // // or because the rdp_recv_callback tells it to
  //
  // while(!t.stop) {     // spooky side effects
  //    if (t.timer > max_time) {
  //        timeout = 0;
  //        t.stop = 1;
  //    }
  // } 
  //
  // if (timeout) {
  //    resend the same packet
  // } // else do nothing, move on to the next packet
  //

  /* send to the packet using remote ip and port stored in the pcb */
  return udp_sendto(pcb, p, pcb->remote_ip, pcb->remote_port);
}


#if RDP_DEBUG
void rdp_debug_print(struct udp_hdr *udphdr);
#else
#define rdp_debug_print(udphdr)
#endif
