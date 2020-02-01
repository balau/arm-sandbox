/*
 * Copyright 2020 Francesco Balducci
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
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

