
#define K300_ICC_NVS_WRITE       0x0
#define K310_ICC_NVS_WRITE       0x0
#define K311_ICC_NVS_WRITE       0x0
#define K315_ICC_NVS_WRITE       0x0
#define K350_ICC_NVS_WRITE       0x0
#define K355_ICC_NVS_WRITE       0x0
#define K370_ICC_NVS_WRITE       0x0
#define K400_ICC_NVS_WRITE       0x0
#define K401_ICC_NVS_WRITE       0x0
#define K405_ICC_NVS_WRITE       0x0
#define K406_ICC_NVS_WRITE       0x0
#define K407_ICC_NVS_WRITE       0x0
#define K450_ICC_NVS_WRITE       0x0
#define K455_ICC_NVS_WRITE       0x0
#define K470_ICC_NVS_WRITE       0x0
#define K471_ICC_NVS_WRITE       0x0
#define K472_ICC_NVS_WRITE       0x0
#define K473_ICC_NVS_WRITE       0x0
#define K474_ICC_NVS_WRITE       0x0
#define K500_ICC_NVS_WRITE       0x0
#define K501_ICC_NVS_WRITE       0x0
#define K503_ICC_NVS_WRITE       0x0
#define K505_ICC_NVS_WRITE       0x00395670
#define K507_ICC_NVS_WRITE       0x0
#define K550_ICC_NVS_WRITE       0x0
#define K553_ICC_NVS_WRITE       0x0
#define K555_ICC_NVS_WRITE       0x0
#define K556_ICC_NVS_WRITE       0x0
#define K600_ICC_NVS_WRITE       0x0
#define K602_ICC_NVS_WRITE       0x0
#define K620_ICC_NVS_WRITE       0x0
#define K650_ICC_NVS_WRITE       0x0
#define K651_ICC_NVS_WRITE       0x0
#define K670_ICC_NVS_WRITE       0x00464290
#define K671_ICC_NVS_WRITE       0x00464290
#define K672_ICC_NVS_WRITE       0x00464290
#define K700_ICC_NVS_WRITE       0x003488E0
#define K701_ICC_NVS_WRITE       0x003488E0
#define K702_ICC_NVS_WRITE       0x003488E0
#define K750_ICC_NVS_WRITE       0x0
#define K751_ICC_NVS_WRITE       0x0
#define K755_ICC_NVS_WRITE       0x0
#define K800_ICC_NVS_WRITE       0x0
#define K801_ICC_NVS_WRITE       0x0
#define K803_ICC_NVS_WRITE       0x0

#define enable_permanent_uart_macro(x)                                      \
  kernel_base = &((uint8_t *)__readmsr(0xC0000082))[-K##x##_XFAST_SYSCALL]; \
  icc_nvs_write = (void *)(kernel_base + K##x##_ICC_NVS_WRITE);

struct kpayload_uart_info {
  uint16_t fw_version;
};