#ifndef _AVAILABLE_H_
#define _AVAILABLE_H_

#include "stringutil.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GSI_UNICODE
    #define GSIStartAvailableCheck   GSIStartAvailableCheckA
#else
    #define GSIStartAvailableCheck   GSIStartAvailableCheckW
#endif

extern char GSIACHostname[64];

typedef enum {
    GSIACWaiting,
    GSIACAvailable,
    GSIACUnavailable,
    GSIACTemporarilyUnavailable
} GSIACResult;

void GSIStartAvailableCheck(const gsi_char *gamename);
GSIACResult GSIAvailableCheckThink(void);
void GSICancelAvailableCheck(void);

extern GSIACResult __GSIACResult;
extern char __GSIACGamename[64];

#ifdef __cplusplus
}
#endif

#endif
