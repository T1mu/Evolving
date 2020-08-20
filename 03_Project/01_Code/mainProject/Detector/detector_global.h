#ifndef DETECTOR_GLOBAL_H
#define DETECTOR_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef DETECTOR_LIB
# define DETECTOR_EXPORT Q_DECL_EXPORT
#else
# define DETECTOR_EXPORT Q_DECL_IMPORT
#endif

#endif // DETECTOR_GLOBAL_H
