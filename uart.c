#include <stdarg.h>
#include "head.h"


typedef struct {
    u32 array;
}DebugArray;
GEN_OTHER_TYPE(DebugArray);

typedef struct {
    u8 thr;
    u8 :8;
    u8 :8;
    u8 :8;
    u8 :8;
    u8 lsr;
}Uart;
GEN_OTHER_TYPE(Uart);

Uart_p m_uart = (Uart_p)(UART_BASE);

void uart_putc(char ch) {
    
#define UART_LSR_EMPTY_MASK (BIT_06)   // LSR Bit 6: Transmitter empty; both the THR and LSR are empty

    WAIT_1_DONE(m_uart->lsr & UART_LSR_EMPTY_MASK);
    m_uart->thr = ch;
}

void uart_put_s(char *s) {
	while (*s) {
        uart_putc(*s++);
    }
}

char* i2a(u32 val, u8 base, char* ps)
{
	u32 m = val % base;
	u32 q = val / base;
	//遞回，這樣可以從最高位開始顯示
	if (q) {
		ps = i2a(q, base, ps);
	}

	//大於 10的就一律顯示 A~f，小於10的顯示 0~F
	(*ps) = (m < 10) ? (m + '0') : (m - 10 + 'A');
    ps++;
	return ps;
}

int vsprintf(char *buf, const char *fmt, va_list args)
{
    char* p = buf;

    u32 num;
    for (; *fmt; fmt++){
        if(*fmt != '%'){
            *p++ = *fmt;
            continue;
        }
		// skip '%'
        fmt++;

        switch (*fmt) {
        case 'l':
            fmt++;
            num = va_arg(args, u32);
            p = i2a(num, 16, p);
        case 'x':
        case 'X':
            num = va_arg(args, u32);
            p = i2a(num, 16, p);
            continue;
        default:
            break;
        }
        fmt++;
    }

    *p++ = 0;

    return 0;
}

int printk(const char *fmt, ...)
{
	int i;
	char buf[512];
    mem_set(buf, 0xFF, 512);

    va_list vl;
    va_start(vl, fmt);
    vsprintf(buf, fmt, vl);
    va_end(vl);

    uart_put_s(buf);

	return i;
}
