################################################################################
# MRS Version: {"version":"1.8.5","date":"2023/05/22"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_adc.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_delay.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_dvp.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_encoder.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_exti.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_flash.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_gpio.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_iic.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_pit.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_pwm.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_soft_iic.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_soft_spi.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_spi.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_timer.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_uart.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_usb_cdc.c 

OBJS += \
./zf_driver/zf_driver_adc.o \
./zf_driver/zf_driver_delay.o \
./zf_driver/zf_driver_dvp.o \
./zf_driver/zf_driver_encoder.o \
./zf_driver/zf_driver_exti.o \
./zf_driver/zf_driver_flash.o \
./zf_driver/zf_driver_gpio.o \
./zf_driver/zf_driver_iic.o \
./zf_driver/zf_driver_pit.o \
./zf_driver/zf_driver_pwm.o \
./zf_driver/zf_driver_soft_iic.o \
./zf_driver/zf_driver_soft_spi.o \
./zf_driver/zf_driver_spi.o \
./zf_driver/zf_driver_timer.o \
./zf_driver/zf_driver_uart.o \
./zf_driver/zf_driver_usb_cdc.o 

C_DEPS += \
./zf_driver/zf_driver_adc.d \
./zf_driver/zf_driver_delay.d \
./zf_driver/zf_driver_dvp.d \
./zf_driver/zf_driver_encoder.d \
./zf_driver/zf_driver_exti.d \
./zf_driver/zf_driver_flash.d \
./zf_driver/zf_driver_gpio.d \
./zf_driver/zf_driver_iic.d \
./zf_driver/zf_driver_pit.d \
./zf_driver/zf_driver_pwm.d \
./zf_driver/zf_driver_soft_iic.d \
./zf_driver/zf_driver_soft_spi.d \
./zf_driver/zf_driver_spi.d \
./zf_driver/zf_driver_timer.d \
./zf_driver/zf_driver_uart.d \
./zf_driver/zf_driver_usb_cdc.d 


# Each subdirectory must supply rules for building sources it contributes
zf_driver/zf_driver_adc.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_adc.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_delay.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_delay.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_dvp.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_dvp.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_encoder.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_encoder.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_exti.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_exti.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_flash.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_flash.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_gpio.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_gpio.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_iic.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_iic.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_pit.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_pit.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_pwm.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_pwm.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_soft_iic.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_soft_iic.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_soft_spi.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_soft_spi.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_spi.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_spi.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_timer.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_timer.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_uart.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_uart.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_usb_cdc.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_usb_cdc.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

