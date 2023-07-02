################################################################################
# MRS Version: {"version":"1.8.5","date":"2023/05/22"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_adc.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_bkp.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_can.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_crc.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_dac.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_dbgmcu.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_dma.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_dvp.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_eth.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_exti.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_flash.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_fsmc.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_gpio.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_i2c.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_iwdg.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_opa.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_pwr.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_rcc.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_rng.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_rtc.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_sdio.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_spi.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_tim.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_usart.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_usbotg_device.c \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_wwdg.c 

OBJS += \
./sdk/Peripheral/ch32v30x_adc.o \
./sdk/Peripheral/ch32v30x_bkp.o \
./sdk/Peripheral/ch32v30x_can.o \
./sdk/Peripheral/ch32v30x_crc.o \
./sdk/Peripheral/ch32v30x_dac.o \
./sdk/Peripheral/ch32v30x_dbgmcu.o \
./sdk/Peripheral/ch32v30x_dma.o \
./sdk/Peripheral/ch32v30x_dvp.o \
./sdk/Peripheral/ch32v30x_eth.o \
./sdk/Peripheral/ch32v30x_exti.o \
./sdk/Peripheral/ch32v30x_flash.o \
./sdk/Peripheral/ch32v30x_fsmc.o \
./sdk/Peripheral/ch32v30x_gpio.o \
./sdk/Peripheral/ch32v30x_i2c.o \
./sdk/Peripheral/ch32v30x_iwdg.o \
./sdk/Peripheral/ch32v30x_opa.o \
./sdk/Peripheral/ch32v30x_pwr.o \
./sdk/Peripheral/ch32v30x_rcc.o \
./sdk/Peripheral/ch32v30x_rng.o \
./sdk/Peripheral/ch32v30x_rtc.o \
./sdk/Peripheral/ch32v30x_sdio.o \
./sdk/Peripheral/ch32v30x_spi.o \
./sdk/Peripheral/ch32v30x_tim.o \
./sdk/Peripheral/ch32v30x_usart.o \
./sdk/Peripheral/ch32v30x_usbotg_device.o \
./sdk/Peripheral/ch32v30x_wwdg.o 

C_DEPS += \
./sdk/Peripheral/ch32v30x_adc.d \
./sdk/Peripheral/ch32v30x_bkp.d \
./sdk/Peripheral/ch32v30x_can.d \
./sdk/Peripheral/ch32v30x_crc.d \
./sdk/Peripheral/ch32v30x_dac.d \
./sdk/Peripheral/ch32v30x_dbgmcu.d \
./sdk/Peripheral/ch32v30x_dma.d \
./sdk/Peripheral/ch32v30x_dvp.d \
./sdk/Peripheral/ch32v30x_eth.d \
./sdk/Peripheral/ch32v30x_exti.d \
./sdk/Peripheral/ch32v30x_flash.d \
./sdk/Peripheral/ch32v30x_fsmc.d \
./sdk/Peripheral/ch32v30x_gpio.d \
./sdk/Peripheral/ch32v30x_i2c.d \
./sdk/Peripheral/ch32v30x_iwdg.d \
./sdk/Peripheral/ch32v30x_opa.d \
./sdk/Peripheral/ch32v30x_pwr.d \
./sdk/Peripheral/ch32v30x_rcc.d \
./sdk/Peripheral/ch32v30x_rng.d \
./sdk/Peripheral/ch32v30x_rtc.d \
./sdk/Peripheral/ch32v30x_sdio.d \
./sdk/Peripheral/ch32v30x_spi.d \
./sdk/Peripheral/ch32v30x_tim.d \
./sdk/Peripheral/ch32v30x_usart.d \
./sdk/Peripheral/ch32v30x_usbotg_device.d \
./sdk/Peripheral/ch32v30x_wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
sdk/Peripheral/ch32v30x_adc.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_adc.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_bkp.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_bkp.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_can.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_can.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_crc.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_crc.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_dac.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_dac.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_dbgmcu.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_dbgmcu.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_dma.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_dma.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_dvp.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_dvp.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_eth.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_eth.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_exti.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_exti.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_flash.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_flash.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_fsmc.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_fsmc.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_gpio.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_gpio.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_i2c.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_i2c.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_iwdg.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_iwdg.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_opa.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_opa.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_pwr.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_pwr.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_rcc.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_rcc.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_rng.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_rng.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_rtc.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_rtc.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_sdio.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_sdio.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_spi.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_spi.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_tim.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_tim.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_usart.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_usart.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_usbotg_device.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_usbotg_device.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
sdk/Peripheral/ch32v30x_wwdg.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Peripheral/ch32v30x_wwdg.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

