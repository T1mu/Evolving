#ifndef BLLPROJECT_GLOBAL_H
#define BLLPROJECT_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef BLLPROJECT_LIB
# define BLLPROJECT_EXPORT Q_DECL_EXPORT
#else
# define BLLPROJECT_EXPORT Q_DECL_IMPORT
#endif

#endif // BLLPROJECT_GLOBAL_H
