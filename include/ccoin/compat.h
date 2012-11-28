#ifndef __LIBCCOIN_COMPAT_H__
#define __LIBCCOIN_COMPAT_H__

/* NOTE: this file requires, but does not include, picocoin-config.h */

/* TODO: this stuff probably should be hidden, not exported
 * alongside all the other API headers
 */

#include <unistd.h>
#include <glib.h>

#if GLIB_VERSION_CUR_STABLE < G_ENCODE_VERSION (2, 30)
static inline GPtrArray *
g_ptr_array_new_full (guint          reserved_size,
                      GDestroyNotify element_free_func)
{
  GPtrArray *array;

  array = g_ptr_array_sized_new (reserved_size);
  g_ptr_array_set_free_func (array, element_free_func);
  return array;
}
#endif

#ifndef HAVE_FDATASYNC
static inline int fdatasync(int fd)
{
	return fsync(fd);
}
#endif

#endif /* __LIBCCOIN_COMPAT_H__ */