#ifndef API_H
#define API_H

// Generic helper definitions for shared library support
#if defined _WIN32 || defined __CYGWIN__
  #define HELLO_HELPER_DLL_IMPORT __declspec(dllimport)
  #define HELLO_HELPER_DLL_EXPORT __declspec(dllexport)
  #define HELLO_HELPER_DLL_LOCAL
#else
  #if __GNUC__ >= 4
    #define HELLO_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
    #define HELLO_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
    #define HELLO_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
  #else
    #define HELLO_HELPER_DLL_IMPORT
    #define HELLO_HELPER_DLL_EXPORT
    #define HELLO_HELPER_DLL_LOCAL
  #endif
#endif

// Now we use the generic helper definitions above to define HELLO_API and HELLO_LOCAL.
// HELLO_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
// HELLO_LOCAL is used for non-api symbols.

#ifdef HELLO_DLL // defined if HELLO is compiled as a DLL
  #ifdef HELLO_DLL_EXPORTS // defined if we are building the HELLO DLL (instead of using it)
    #define HELLO_API HELLO_HELPER_DLL_EXPORT
  #else
    #define HELLO_API HELLO_HELPER_DLL_IMPORT
  #endif // HELLO_DLL_EXPORTS
  #define HELLO_LOCAL HELLO_HELPER_DLL_LOCAL
#else // HELLO_DLL is not defined: this means HELLO is a static lib.
  #define HELLO_API
  #define HELLO_LOCAL
#endif // HELLO_DLL

#endif
