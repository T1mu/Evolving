#ifndef TUBE_GLOBAL_H
#define TUBE_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef TUBE_LIB
# define TUBE_EXPORT Q_DECL_EXPORT
#else
# define TUBE_EXPORT Q_DECL_IMPORT
#endif

#endif // TUBE_GLOBAL_H
