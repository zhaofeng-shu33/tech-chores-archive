#ifndef HELLOWADD_H
#define HELLOWADD_H

#include "HellowAdd_global.h"

class HELLOWADDSHARED_EXPORT HellowAdd {
public:
    HellowAdd();
    int Add(int a,int b);
 };
HELLOWADDSHARED_EXPORT int Sub(int a,int b);
#endif // HELLOWADD_H
