#pragma once


typedef void (*TaskFun)(void);

void task_create(TaskFun task);