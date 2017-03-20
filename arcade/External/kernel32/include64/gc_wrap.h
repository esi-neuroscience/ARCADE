#ifndef GC_WRAP_H
#define GC_WRAP_H

#include <windows.h>
#include <gc.h>
#undef GC_API
#define GC_API __declspec(dllimport)

GC_API void* GC_wrapped_malloc(size_t);
GC_API void GC_wrapped_free(void*);
GC_API size_t GC_wrapped_get_heap_size(void);
GC_API void *GC_wrapped_malloc_atomic(size_t);

/* debug versions of allocation and free functions
	debug calls into GC maybe this would be quite useful to have
	during development of wedit */

GC_API void* GC_wrapped_debug_malloc(size_t, GC_EXTRA_PARAMS);
GC_API void GC_wrapped_debug_free(void*);
GC_API void * GC_wrapped_debug_malloc_atomic(size_t size_in_bytes, GC_EXTRA_PARAMS);

/* not yet wrapped frido */
#if 0
GC_API void *GC_wrapped_debug_malloc(size_t size_in_bytes, GC_EXTRA_PARAMS);
GC_API char * GC_wrapped_debug_strdup(const char *str, GC_EXTRA_PARAMS);
GC_API void * GC_wrapped_debug_malloc_uncollectable
	(size_t size_in_bytes, GC_EXTRA_PARAMS);
GC_API void * GC_wrapped_debug_malloc_stubborn
	(size_t size_in_bytes, GC_EXTRA_PARAMS);
GC_API void * GC_wrapped_debug_malloc_ignore_off_page
	(size_t size_in_bytes, GC_EXTRA_PARAMS);
GC_API void * GC_wrapped_debug_malloc_atomic_ignore_off_page
	(size_t size_in_bytes, GC_EXTRA_PARAMS);
GC_API void GC_wrapped_debug_free (void * object_addr);
GC_API void * GC_wrapped_debug_realloc
	(void * old_object, size_t new_size_in_bytes, GC_EXTRA_PARAMS);
GC_API void GC_wrapped_debug_change_stubborn(void *);
GC_API void GC_wrapped_debug_end_stubborn_change(void *);
#endif

#endif
