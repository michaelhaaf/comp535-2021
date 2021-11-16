#ifndef __RDP_H_
#define __RDP_H_

#include <stdint.h>
#include "ip.h"
#include "err.h"
#include "pbuf.h"
#include "udp.h"


#ifdef __cplusplus
extern "C" {
#endif
	

/* The following functions is the application layer interface to the
   RDP code. */
err_t            rdp_send       (struct udp_pcb *pcb, struct pbuf *p);

#if RDP_DEBUG
void rdp_debug_print(struct udp_hdr *udphdr);
#else
#define rdp_debug_print(udphdr)
#endif

#ifdef __cplusplus
}
#endif

#endif // ifndef __RDP_H_

