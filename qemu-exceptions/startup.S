.global Reset_Handler
.global Empty_Exception_Handler

Reset_Handler: 

 LDR r0, =0x101f1000
 LDR r1, =0x61
 STR r1, [r0]

 LDR sp, =stack_top
 LDR lr, =Reset_Handler_1
 LDR pc, =relocate_exceptions
Reset_Handler_1:
 
 LDR r0, =0x101f1000
 LDR r1, =0x62
 STR r1, [r0]
 
 LDR lr, =c_entry_return
 LDR pc, =c_entry
c_entry_return:
 SWI 0x01

Empty_Exception_Handler:
 LDR r0, =0x101f1000
 LDR r1, =0x65
 STR r1, [r0]
 B .
