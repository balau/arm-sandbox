#include <stdint.h>
#include "exceptions.h"

void relocate_exceptions()
{
	extern uint32_t __load_start_vect;
	extern uint32_t __copy_start_vect;
	extern uint32_t __load_stop_vect;
	
	uint32_t *pLoad = &__load_start_vect;
	uint32_t *pCopy = &__copy_start_vect;
	uint32_t * const pLoadEnd = &__load_stop_vect;
	
	while(pLoad < pLoadEnd)
	{
		*pCopy++ = *pLoad++;
	}
}

void set_exception(exception_t exc, exception_handler_t handler)
{
	extern uint32_t __load_start_vect;
	extern uint32_t vect_addr;
	exception_handler_t *vectors = (((uint32_t)(&vect_addr)) - ((uint32_t)(&__load_start_vect))) + ((uint32_t)(&__copy_start_vect));
	if(exc >= EXC_RESET && exc <= EXC_FIQ)
	{
		vectors[exc] = handler;
	}
}

