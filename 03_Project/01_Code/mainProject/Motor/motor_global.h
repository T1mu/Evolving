#ifndef MOTOR_GLOBAL_H
#define MOTOR_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef MOTOR_LIB
# define MOTOR_EXPORT Q_DECL_EXPORT
#else
# define MOTOR_EXPORT Q_DECL_IMPORT
#endif

#endif // MOTOR_GLOBAL_H
