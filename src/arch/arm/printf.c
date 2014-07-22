/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

#include <debug/debug.h>
#include <sel4/types.h>
#include <sel4/arch/functions.h>
#include <stdarg.h>
#include <stdio.h>

int
debug_safe_printf(const char *format, ...) {
    seL4_IPCBuffer shadow_buffer; /* XXX: Should we avoid allocating
                                   * this large struct on the stack?
                                   */

    /* Assume that the standard printf may clobber the IPC buffer, so save it
     * before.
     */
    shadow_buffer = *(seL4_GetIPCBuffer());

    /* Copied from printf: */
    int ret;
    va_list ap;

    va_start(ap, format);
    ret = vfprintf(stdout, format, ap);
    va_end(ap);

    /* Now restore the IPC buffer. */
    *(seL4_GetIPCBuffer()) = shadow_buffer;

    return ret;
}
