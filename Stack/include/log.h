//=============================================================================
#ifndef LOG_H
#define LOG_H

#ifndef NDEBUG // you can define it with -DNDEBUG 
#define log(...) printf(__VA_ARGS__)
#else
#define log(...) ((void) 0)
#endif

#endif // LOG_H