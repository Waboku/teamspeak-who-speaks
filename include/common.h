#ifndef __COMMON_H__
#define __COMMON_H__

/* Configuration file generated by CMake */
#include "config.h"

#ifdef UNIT_TESTING

#ifdef UNIT_TESTING_MEM
extern void* _test_malloc(const size_t size, const char* file, const int line);
extern void* _test_calloc(const size_t number_of_elements, const size_t size, const char* file, const int line);
extern void _test_free(void* const ptr, const char* file, const int line);

#define malloc(size) _test_malloc(size, __FILE__, __LINE__)
#define calloc(num, size) _test_calloc(num, size, __FILE__, __LINE__)
#define free(ptr) _test_free(ptr, __FILE__, __LINE__)
#endif /* UNIT_TESTING_MEM */

#endif /* UNIT_TESTING */

#endif /* __COMMON_H__ */
