#ifndef _GL4ES_LOGS_H_
#define _GL4ES_LOGS_H_
//----------------------------------------------------------------------------
#include <stdio.h>
#include "init.h"
#include "attributes.h"
//----------------------------------------------------------------------------
void LogPrintf_NoPrefix(const char *fmt,...);
void LogPrintf(const char *fmt, ...) __attribute__((visibility("default")));
EXPORT void LogPrintf(const char *fmt,...);
//----------------------------------------------------------------------------
#ifdef GL4ES_SILENCE_MESSAGES
	#define SHUT_LOGD(...)
	#define SHUT_LOGD_NOPREFIX(...)
	#define SHUT_LOGE(...)
#else
	#define SHUT_LOGD(...) if(!globals4es.nobanner) LogPrintf(__VA_ARGS__)
	#define SHUT_LOGD_NOPREFIX(...) if(!globals4es.nobanner) LogPrintf_NoPrefix(__VA_ARGS__)
	#define SHUT_LOGE(...) if(!globals4es.nobanner) LogPrintf(stderr,__VA_ARGS__)
#endif
//----------------------------------------------------------------------------
#define LOGD(...) LogPrintf(__VA_ARGS__)
#define LOGE(...) LogPrintf(stderr,__VA_ARGS__)
//----------------------------------------------------------------------------
#endif // _GL4ES_LOGS_H_
