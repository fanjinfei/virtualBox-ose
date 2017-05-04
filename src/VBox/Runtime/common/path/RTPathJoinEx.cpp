/* $Id: RTPathJoinEx.cpp 62477 2016-07-22 18:27:37Z vboxsync $ */
/** @file
 * IPRT - RTPathJoinEx.
 */

/*
 * Copyright (C) 2010-2016 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 *
 * The contents of this file may alternatively be used under the terms
 * of the Common Development and Distribution License Version 1.0
 * (CDDL) only, as it comes in the "COPYING.CDDL" file of the
 * VirtualBox OSE distribution, in which case the provisions of the
 * CDDL are applicable instead of those of the GPL.
 *
 * You may elect to license modified versions of this file under the
 * terms and conditions of either the GPL or the CDDL or both.
 */


/*********************************************************************************************************************************
*   Header Files                                                                                                                 *
*********************************************************************************************************************************/
#include "internal/iprt.h"
#include <iprt/path.h>
#include <iprt/assert.h>
#include <iprt/err.h>
#include <iprt/string.h>




RTDECL(int) RTPathJoinEx(char *pszPathDst, size_t cbPathDst,
                         const char *pszPathSrc, size_t cchPathSrcMax,
                         const char *pszAppend, size_t cchAppendMax)
{
    AssertPtr(pszPathDst);
    AssertPtr(pszPathSrc);
    AssertPtr(pszAppend);

    /*
     * The easy way: Copy the path into the buffer and call RTPathAppend.
     */
    size_t cchPathSrc = RTStrNLen(pszPathSrc, cchPathSrcMax);
    if (cchPathSrc >= cbPathDst)
        return VERR_BUFFER_OVERFLOW;
    memcpy(pszPathDst, pszPathSrc, cchPathSrc);
    pszPathDst[cchPathSrc] = '\0';

    return RTPathAppendEx(pszPathDst, cbPathDst, pszAppend, cchAppendMax);
}
