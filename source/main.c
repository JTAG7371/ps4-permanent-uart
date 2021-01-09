#include "ps4.h"

int enable_permanent_uart(struct thread* td, void* unused)
{
	UNUSED(td);
	UNUSED(unused);
	
	void *kernel_base = &((uint8_t *)__readmsr(0xC0000082))[-0x1C0];
	uint64_t (*icc_nvs_write)(uint32_t block, uint32_t offset, uint32_t size, uint8_t* value) = (void *)(kernel_base + 0x464290);

	uint8_t value = 1;
	icc_nvs_write(4, 0x31F, 1, &value);
	
	return 0;
}


int _main(struct thread *td) {
	UNUSED(td);

	initKernel();
	initLibc();

	jailbreak();

	initSysUtil();

	kexec(&enable_permanent_uart, 0);

	printf_notification("Permanent UART installed. Reboot to finish setup.");

	return 0;
}
