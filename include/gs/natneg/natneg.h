#ifndef _NATNEG_H_
#define _NATNEG_H_

#include <nonport.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NATNEG_MAGIC_LEN 6
#define NN_MAGIC_0 0xFD
#define NN_MAGIC_1 0xFC
#define NN_MAGIC_2 0x1E
#define NN_MAGIC_3 0x66
#define NN_MAGIC_4 0x6A
#define NN_MAGIC_5 0xB2

extern unsigned char NNMagicData[];

typedef enum {
    ns_initsent,
    ns_initack,
    ns_connectping,
    ns_finished,
    ns_canceled
} NegotiateState;

typedef enum {
    nr_success,
    nr_deadbeatpartner,
    nr_inittimeout,
    nr_unknownerror
} NegotiateResult;

typedef enum {
    ne_noerror,
    ne_allocerror,
    ne_socketerror,
    ne_dnserror
} NegotiateError;

typedef void (*NegotiateProgressFunc)(
    NegotiateState state,
    void *userdata
);

typedef void (*NegotiateCompletedFunc)(
    NegotiateResult result,
    SOCKET gamesocket,
    struct sockaddr_in *remoteaddr,
    void *userdata
);

NegotiateError NNBeginNegotiation(
    int cookie,
    int clientindex,
    NegotiateProgressFunc progresscallback,
    NegotiateCompletedFunc completedcallback,
    void *userdata
);

NegotiateError NNBeginNegotiationWithSocket(
    SOCKET gamesocket,
    int cookie,
    int clientindex,
    NegotiateProgressFunc progresscallback,
    NegotiateCompletedFunc completedcallback,
    void *userdata
);

void NNThink(void);

void NNProcessData(
    char *data,
    int len,
    struct sockaddr_in *fromaddr
);

void NNCancel(int cookie);

void NNFreeNegotiateList(void);

extern char *Matchup2Hostname;
extern char *Matchup1Hostname;

#ifdef __cplusplus
}
#endif

#endif
