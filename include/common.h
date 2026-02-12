#include <ultra64.h>
#include "macro.h"
#include "memory.h"
#include "controller.h"
#include "cont_pak.h"
#include "segment.h"
#include "math.h"
#include "sys_matrix.h"
#include "temp_heap.h"
#include "obj.h"
#include "scheduler.h"
#include "debug.h"
#include "structs.h"
#include "functions.h"
#include "variables.h"
#include "thread.h"
#include "mtx_util.h"
#include "buffers.h"
#include "simple.h" // For the PRINTF macro

// Why this is not in Ultratypes?
typedef u32 uintptr_t;
typedef void (*FuncPtr)(void *) ;

#define FAKE_ACCESS(struct, ptr, index, member) ((struct*) ((char*) ptr + (index * sizeof(struct))))->member
