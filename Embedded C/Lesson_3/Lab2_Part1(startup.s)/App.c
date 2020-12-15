 #include <stdint.h>
typedef volatile unsigned int vuint32_t;
// register address
#define RCC_BASE	0x40021000
#define GPIOA_BASE	0x40010800
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE +0x18)
#define GPIOA_CRH   *(volatile uint32_t *)(GPIOA_BASE +0x04)
#define GPIOA_ODR   *(volatile uint32_t *)(GPIOA_BASE +0x0C)
typedef union {
	vuint32_t	all_fields;
	struct{
		vuint32_t	reversed:13;
		vuint32_t 	pin13:1;
	}pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR= (volatile R_ODR_t*)(GPIOA_BASE+ 0x0C);
unsigned char g_var[3]={1,2,3};
unsigned char const const_var[3]={1,2,3};
unsigned char bss_var[3]; 
int main(void)
{
	RCC_APB2ENR |= (1<<2);
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;

	while(1){
		//		GPIOA_ODR |= 1<<13; //set bit 13
		R_ODR->pin.pin13 = 1;
		for(int i=0; i < 50000 ;  i++);
		//		GPIOA_ODR &= ~(1<<13);	//clear bit 13
		R_ODR->pin.pin13=0;
		for(int i=0;i<50000;i++);
	}

	return 0;
}