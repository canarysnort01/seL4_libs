/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

#include <autoconf.h>
#include <debug/debug.h>
#include <sel4/sel4.h>
#include <stdio.h>

void 
debug_cap_identify(seL4_CPtr cap)
{
#ifdef CONFIG_DEBUG_BUILD
    int type = seL4_DebugCapIdentify(cap);

    printf("Cap type number is %d\n", type);
#endif /* CONFIG_DEBUG_BUILD */
}
