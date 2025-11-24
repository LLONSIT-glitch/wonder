#include <ultra64.h>
#include "macro.h"
#include "structs.h"
#include "memory.h"
#include "controller.h"
#include "pfs.h"
#include "segment.h"
#include "math.h"
#include "sys_matrix.h"
#include "temp_heap.h"
#include "functions.h"
#include "variables.h"

// Why this is not Ultratypes?
typedef u32 uintptr_t;
typedef void (*FuncPtr)(void *) ;

// TODO: Move this to another file!
#define PFS_SUCCESS 0
