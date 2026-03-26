#pragma once

#if defined _WIN32 || defined __CYGWIN__
#  define PIDTuningController_DLLIMPORT __declspec(dllimport)
#  define PIDTuningController_DLLEXPORT __declspec(dllexport)
#  define PIDTuningController_DLLLOCAL
#else
// On Linux, for GCC >= 4, tag symbols using GCC extension.
#  if __GNUC__ >= 4
#    define PIDTuningController_DLLIMPORT __attribute__((visibility("default")))
#    define PIDTuningController_DLLEXPORT __attribute__((visibility("default")))
#    define PIDTuningController_DLLLOCAL __attribute__((visibility("hidden")))
#  else
// Otherwise (GCC < 4 or another compiler is used), export everything.
#    define PIDTuningController_DLLIMPORT
#    define PIDTuningController_DLLEXPORT
#    define PIDTuningController_DLLLOCAL
#  endif // __GNUC__ >= 4
#endif // defined _WIN32 || defined __CYGWIN__

#ifdef PIDTuningController_STATIC
// If one is using the library statically, get rid of
// extra information.
#  define PIDTuningController_DLLAPI
#  define PIDTuningController_LOCAL
#else
// Depending on whether one is building or using the
// library define DLLAPI to import or export.
#  ifdef PIDTuningController_EXPORTS
#    define PIDTuningController_DLLAPI PIDTuningController_DLLEXPORT
#  else
#    define PIDTuningController_DLLAPI PIDTuningController_DLLIMPORT
#  endif // PIDTuningController_EXPORTS
#  define PIDTuningController_LOCAL PIDTuningController_DLLLOCAL
#endif // PIDTuningController_STATIC
