#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(MOTORRELATED_LIB)
#  define MOTORRELATED_EXPORT Q_DECL_EXPORT
# else
#  define MOTORRELATED_EXPORT Q_DECL_IMPORT
# endif
#else
# define MOTORRELATED_EXPORT
#endif
