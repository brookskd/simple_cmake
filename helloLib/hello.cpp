#include <iostream>

#define HELLO_DLL
#define HELLO_DLL_EXPORTS
#include "api.h"
#include "hello.h"

HELLO_API void hello()
{
  std::cout << "Hello!" << std::endl;
}
