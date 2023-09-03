//learn-in-depth
//eng salah ali
#include <stdint.h>


void RESET_HANDLER();
extern int main(void);
void DEFAULT_HANDLER(void)
{
	RESET_HANDLER();
}

void NMI_HANDLER(void) __attribute__((weak, alias("DEFAULT_HANDLER")));;
void H_FAULT_HANDLER(void)__attribute__((weak, alias("DEFAULT_HANDLER")));;


 static unsigned int Stack_top[256] ;
 
void (* const g_p_fn_vectors[])()  __attribute__((section(".vectors"))) = {
	(void(*)())((unsigned long)Stack_top+sizeof(Stack_top)),
	&NMI_HANDLER,
	&RESET_HANDLER,
	&H_FAULT_HANDLER
	
};
extern unsigned int _E_TEXT ;
extern unsigned int _S_DATA ;
extern unsigned int _E_DATA ;
extern unsigned int _S_BSS ;
extern unsigned int _E_BSS ;

void RESET_HANDLER(void)
{
	//copy data section from rom to ram
	unsigned int i;
	unsigned int DATA_SIZE = (unsigned char*)& _E_DATA - (unsigned char*)&_S_DATA ;
	unsigned char* p_src = (unsigned char*)&_E_TEXT;
	unsigned char* p_dis = (unsigned char*)&_S_DATA;
	for(i=0;i<DATA_SIZE;i++)
	{
		*((unsigned char*)p_dis++)=*((unsigned char*)p_src++) ;
	}
	//initialize bss section
	unsigned int BSS_SIZE = (unsigned char*)& _E_BSS - (unsigned char*)&_S_BSS ;
	 p_dis = (unsigned char*)&_S_BSS;
	for(i=0;i<BSS_SIZE;i++)
	{
		*((unsigned char*)p_dis++)=(unsigned char)0 ;
	}
	main();
}