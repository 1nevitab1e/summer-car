################################################################################
# MRS Version: {"version":"1.8.5","date":"2023/05/22"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/wch307/CHV307_Library-master/Example/libraries/zf_common/zf_common_clock.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_common/zf_common_debug.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_common/zf_common_fifo.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_common/zf_common_font.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_common/zf_common_function.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_common/zf_common_interrupt.c 

OBJS += \
./zf_common/zf_common_clock.o \
./zf_common/zf_common_debug.o \
./zf_common/zf_common_fifo.o \
./zf_common/zf_common_font.o \
./zf_common/zf_common_function.o \
./zf_common/zf_common_interrupt.o 

C_DEPS += \
./zf_common/zf_common_clock.d \
./zf_common/zf_common_debug.d \
./zf_common/zf_common_fifo.d \
./zf_common/zf_common_font.d \
./zf_common/zf_common_function.d \
./zf_common/zf_common_interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
zf_common/zf_common_clock.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_common/zf_common_clock.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_debug.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_common/zf_common_debug.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_fifo.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_common/zf_common_fifo.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_font.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_common/zf_common_font.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_function.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_common/zf_common_function.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_interrupt.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_common/zf_common_interrupt.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

