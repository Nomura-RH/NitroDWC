#ifndef DWC_REPORT_H_
#define DWC_REPORT_H_

#include <nitro.h>

#ifdef  __cplusplus
extern "C" {
#endif

enum {
    DWC_REPORTFLAG_INFO        = 0x00000001,
    DWC_REPORTFLAG_ERROR       = 0x00000002,
    DWC_REPORTFLAG_DEBUG       = 0x00000004,
    DWC_REPORTFLAG_WARNING     = 0x00000008,
    DWC_REPORTFLAG_ACHECK      = 0x00000010,
    DWC_REPORTFLAG_LOGIN       = 0x00000020,
    DWC_REPORTFLAG_MATCH_NN    = 0x00000040,
    DWC_REPORTFLAG_MATCH_GT2   = 0x00000080,
    DWC_REPORTFLAG_TRANSPORT   = 0x00000100,
    DWC_REPORTFLAG_QR2_REQ     = 0x00000200,
    DWC_REPORTFLAG_SB_UPDATE   = 0x00000400,
    DWC_REPORTFLAG_SEND_INFO   = 0x00008000,
    DWC_REPORTFLAG_RECV_INFO   = 0x00010000,
    DWC_REPORTFLAG_UPDATE_SV   = 0x00020000,
    DWC_REPORTFLAG_CONNECTINET = 0x00040000,
    DWC_REPORTFLAG_AUTH        = 0x01000000,
    DWC_REPORTFLAG_AC          = 0x02000000,
    DWC_REPORTFLAG_BM          = 0x04000000,
    DWC_REPORTFLAG_UTIL        = 0x08000000,
    DWC_REPORTFLAG_GAMESPY     = 0x80000000,
    DWC_REPORTFLAG_ALL         = 0xffffffff
};

#ifndef SDK_FINALROM
    void DWC_SetReportLevel(u32 level);
    void DWC_Printf(u32 level, const char * fmt, ...);
#else
    #define    DWC_SetReportLevel(level)    ((void)0)
    #define    DWC_Printf(level, ...)       ((void)0)
#endif

#ifdef  __cplusplus
}
#endif

#endif
