#include "ps4.h"
#include "uart_helper.h"

uint64_t (*icc_nvs_write)(uint32_t block, uint32_t offset, uint32_t size, uint8_t* value) = 0;
void *kernel_base_;

int payload_permanent_uart(struct thread* td, struct kpayload_firmware_args* args)
{
	UNUSED(td);
	void *kernel_base;
	
	uint16_t fw_version = args->kpayload_firmware_info->fw_version;

	// NOTE: This is a C preprocessor macro
	build_kpayload(fw_version, enable_permanent_uart_macro);
	
	kernel_base_ = kernel_base;
	
	if ((uint64_t)icc_nvs_write != (uint64_t)kernel_base_)
	{
		uint8_t value = 1;
		icc_nvs_write(4, 0x31F, 1, &value);
	}
	
	return 0;
}

int enable_permanent_uart() {
  struct kpayload_firmware_info kpayload_firmware_info;
  kpayload_firmware_info.fw_version = get_firmware();
  kexec(&payload_permanent_uart, &kpayload_firmware_info);
  return 0;
}

int _main(struct thread *td) {
	UNUSED(td);

	initKernel();
	initLibc();

	jailbreak();

	initSysUtil();
	
	enable_permanent_uart();
	
	if ((uint64_t)icc_nvs_write != (uint64_t)kernel_base_)
	{
		printf_notification("Permanent UART installed. Reboot to finish setup.");
	}
	else
	{
		printf_notification("Current Firmware is not supported. Make an issue on github with your kernel dump");
	}

	return 0;
}
