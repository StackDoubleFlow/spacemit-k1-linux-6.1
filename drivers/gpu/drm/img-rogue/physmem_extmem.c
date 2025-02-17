/*************************************************************************/ /*!
@File           physmem_extmem.c
@Title          Physmem - External Memory Import Support
@Copyright      Copyright (c) Imagination Technologies Ltd. All Rights Reserved
@Description    Common entry point for Importing Externally allocated Memory
@License        Dual MIT/GPLv2

The contents of this file are subject to the MIT license as set out below.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

Alternatively, the contents of this file may be used under the terms of
the GNU General Public License Version 2 ("GPL") in which case the provisions
of GPL are applicable instead of those above.

If you wish to allow use of your version of this file only under the terms of
GPL, and not to allow others to use your version of this file under the terms
of the MIT license, indicate your decision by deleting the provisions above
and replace them with the notice and other provisions required by GPL as set
out in the file called "GPL-COPYING" included in this distribution. If you do
not delete the provisions above, a recipient may use your version of this file
under the terms of either the MIT license or GPL.

This License is also included in this distribution in the file called
"MIT-COPYING".

EXCEPT AS OTHERWISE STATED IN A NEGOTIATED AGREEMENT: (A) THE SOFTWARE IS
PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
PURPOSE AND NONINFRINGEMENT; AND (B) IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/ /**************************************************************************/
#include "img_types.h"
#include "pvrsrv_error.h"
#include "pvrsrv_memallocflags.h"
#include "pvrsrv.h"
#include "physmem_extmem.h"

#if 0
#if defined(LMA)
#pragma message "WARNING! You are compiling SUPPORT_WRAP_EXTMEM on a platform with LMA. " \
	"Make sure the memory you wrap is actually accessible by the GPU!"
#endif
#endif

PVRSRV_ERROR
PhysmemWrapExtMem(CONNECTION_DATA * psConnection,
                  PVRSRV_DEVICE_NODE *psDevNode,
                  IMG_DEVMEM_SIZE_T uiSize,
                  IMG_UINT64 pvCpuVAddr,
                  PVRSRV_MEMALLOCFLAGS_T uiFlags,
                  PMR **ppsPMRPtr)
{
	return PhysmemWrapExtMemOS(psConnection,
	                           psDevNode,
	                           uiSize,
	                           (IMG_CPU_VIRTADDR)(uintptr_t)pvCpuVAddr,
	                           uiFlags,
	                           ppsPMRPtr);

}
