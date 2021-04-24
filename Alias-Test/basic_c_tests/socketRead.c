#include "aliascheck.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>


typedef void  (*socketHandler_t)(int sid, int mask, int data);
typedef int   (*socketAccept_t)(int sid, char *ipaddr, int port, int listenSid);

typedef struct {
	unsigned char	*buf;				/* Holding buffer for data */
	unsigned char	*servp;				/* Pointer to start of data */
	unsigned char	*endp;				/* Pointer to end of data */
	unsigned char	*endbuf;			/* Pointer to end of buffer */
	int				buflen;				/* Length of ring queue */
	int				maxsize;			/* Maximum size */
	int				increment;			/* Growth increment */
} ringq_t;

typedef struct {
	char			host[64];				/* Host name */
	ringq_t			inBuf;					/* Input ring queue */
	ringq_t			outBuf;					/* Output ring queue */
	ringq_t			lineBuf;				/* Line ring queue */
	socketAccept_t	accept;					/* Accept handler */
	socketHandler_t	handler;				/* User I/O handler */
	int				handler_data;			/* User handler data */
	int				handlerMask;			/* Handler events of interest */
	int				sid;					/* Index into socket[] */
	int				port;					/* Port to listen on */
	int				flags;					/* Current state flags */
	int				sock;					/* Actual socket handle */
	int				fileHandle;				/* ID of the file handler */
	int				interestEvents;			/* Mask of events to watch for */
	int				currentEvents;			/* Mask of ready events (FD_xx) */
	int				selectEvents;			/* Events being selected */
	int				saveMask;				/* saved Mask for socketFlush */
	int				error;					/* Last error */
} socket_t;

socket_t *socketPtr(int sid) {
    char *host = "192.168.1.1";
    socket_t *ptr = (socket_t*)malloc(sizeof(socket_t));
    ptr->sid = 1;
    ptr->port = 80;
    strcpy(ptr->host, host);
    return ptr;
}

void ringqFlush(ringq_t *rq){
	rq->servp = rq->buf;
	rq->endp = rq->buf;
}

int	socketRead(int sid, char *buf, int bufsize){
	socket_t	*sp;
	ringq_t		*rq;
	int			len;

	sp = socketPtr(sid);
	rq = &sp->inBuf;
	ringqFlush(rq);

	MUSTALIAS((&sp->inBuf)->endp, rq->servp);
	/* len = recv(sp->sock, (char *) (&sp->inBuf)->endp, bufsize, 0); */
	// len = recv(sp->sock,(&sp->inBuf)->endp,bufsize,0);
	// memcpy(buf, rq->servp, len);
	return 0;
}

int main() {
    char buf[200];
    socketRead(0, buf, 100);
    return 0;
}




// void ringqFlush(ringq_t *rq){
// 	rq->servp = rq->buf;
// }

// void socketRead(int sid, int bufsize){
// 	char rbuf[200];
// 	int			len;
// 	socket_t	*sp;
// 	ringq_t		*rq;
	
// 	sp = socketPtr(sid);
// 	rq = sp->inBuf;
// 	ringqFlush(rq);
// 	len = recv(sp->sock, sp->inBuf->buf, bufsize, 0);
// 	memcpy(rbuf, rq->servp, len);
// }

// void main() {
//     foo(0, 100);
//     foo(1, 300);
// }
