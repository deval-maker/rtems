/*
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 *
 *  $Id$
 */

#include <bsp.h>
#include <bsp/bootcard.h>
#include <stdint.h>

extern void *_RamBase;
extern void *_RamSize;
extern void *end;

extern char __alt_heap_start[];

/*
 *  This method returns the base address and size of the area which
 *  is to be allocated between the RTEMS Workspace and the C Program
 *  Heap.
 */
void bsp_get_work_area(
  void   **work_area_start,
  size_t  *work_area_size,
  void   **heap_start,
  size_t  *heap_size
)
{
  uintptr_t size;

  size = (uintptr_t)&RAM_BASE + (uintptr_t)&RAM_BYTES
         - (uintptr_t)&__alt_heap_start;

  *work_area_start = (void *)__alt_heap_start;
  *work_area_size  = size;
  *heap_start      = BSP_BOOTCARD_HEAP_USES_WORK_AREA;
  *heap_size       = BSP_BOOTCARD_HEAP_SIZE_DEFAULT;
}

