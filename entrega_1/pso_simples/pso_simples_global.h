#ifndef PSO_SIMPLES_GLOBAL_H
#define PSO_SIMPLES_GLOBAL_H

#ifdef WINDOWS
    #ifdef PSO_SIMPLES_LIBRARY
        #define PSO_SIMPLESSHARED_EXPORT __declspec(dllexport)
    #else
        #define PSO_SIMPLESSHARED_EXPORT __declspec(dllimport)
    #endif
    #define DEPRECATED(func) __declspec(deprecated) func
#elif LINUX
    #define PSO_SIMPLESSHARED_EXPORT
     #define DEPRECATED(func) func __attribute__ ((deprecated))
#endif

#endif // PSO_SIMPLES_GLOBAL_H
