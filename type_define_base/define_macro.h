#pragma once

#define WAIT_1_DONE(COND)  while ((COND) == 0);

#define RAM_U8(ADDR)        (*((vu8*)(ADDR)))
#define RAM_U32(ADDR)       (*((vu32*)(ADDR)))
#define RAM_U64(ADDR)       (*((vu64*)(ADDR)))
