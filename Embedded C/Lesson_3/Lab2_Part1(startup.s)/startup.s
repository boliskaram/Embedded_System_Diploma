/* Bolis Karam */

.section .vectors

.word	0x20001000	/* stacp top */
.word 	_reset		/* Reset */
.word 	Vector_handler	/* NMI */
.word 	Vector_handler	/* Hard Fault*/
.word 	Vector_handler	/* MM Fault*/
.word 	Vector_handler	/* Bus Fault*/
.word 	Vector_handler	/* Usage Fault*/
	
	
.section .text

_reset:
	bl main
	b .

.thumb_func
Vector_handler:
	b _reset
	