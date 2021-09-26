#pragma once

#define GEN_OTHER_TYPE(T)             \
	typedef const T* const T##_sp;    \
	typedef T* const T##_p;           \
	typedef T* T##_usp;               \
    typedef volatile T  v##T;         
	

typedef unsigned char         u8;
GEN_OTHER_TYPE(u8);

typedef unsigned short        u16;
GEN_OTHER_TYPE(u16);

typedef unsigned long         u32;
GEN_OTHER_TYPE(u32);

typedef unsigned long long    u64; 
GEN_OTHER_TYPE(u64);
