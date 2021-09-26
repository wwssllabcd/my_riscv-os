#include "head.h"

#define MAX_TASK (10)
#define STACK_SIZE (1024)

typedef void (*TaskFun)(void);

Context m_ctx_os;
Context m_ctx_tasks[MAX_TASK];
u8 m_task_stack[MAX_TASK][STACK_SIZE];
u32 m_taskPtr = 0;

void task_create(TaskFun task){

  u32 i = m_taskPtr;
  m_taskPtr++;

  m_ctx_tasks[i].ra = (reg_t)task;
  m_ctx_tasks[i].sp = (reg_t)&m_task_stack[i][STACK_SIZE - 1];
}
