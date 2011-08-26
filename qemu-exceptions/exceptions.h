
typedef void (*exception_handler_t)(void);

typedef enum
{
	EXC_RESET = 0,
	EXC_UNDEF = 1,
	EXC_SWI = 2,
	EXC_PABORT = 3,
	EXC_DABORT = 4,
	EXC_IRQ = 6,
	EXC_FIQ = 7,
} exception_t;

void set_exception(exception_t exc, exception_handler_t handler);
