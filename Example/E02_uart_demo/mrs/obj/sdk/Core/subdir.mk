################################################################################
# MRS Version: {"version":"1.8.5","date":"2023/05/22"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/wch307/CHV307_Library-master/Example/libraries/sdk/Core/core_riscv.c 

OBJS += \
./sdk/Core/core_riscv.o 

C_DEPS += \
./sdk/Core/core_riscv.d 


# Each subdirectory must supply rules for building sources it contributes
sdk/Core/core_riscv.o: E:/wch307/CHV307_Library-master/Example/libraries/sdk/Core/core_riscv.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

