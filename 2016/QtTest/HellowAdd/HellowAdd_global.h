#ifndef HELLOWADD_GLOBAL_H
#define HELLOWADD_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HELLOWADD_LIBRARY)
#  define HELLOWADDSHARED_EXPORT Q_DECL_EXPORT
#else
#  define HELLOWADDSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // HELLOWADD_GLOBAL_H
