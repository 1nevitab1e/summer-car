################################################################################
# MRS Version: {"version":"1.8.5","date":"2023/05/22"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_absolute_encoder.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_aht20.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_bluetooth_ch9141.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_camera.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_dl1a.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_dm1xa.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_gps_tau1201.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_icm20602.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_imu660ra.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_imu963ra.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_ips114.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_ips200.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_k24c02.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_key.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_mpu6050.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_mt9v03x_dvp.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_oled.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_scc8660_dvp.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_tft180.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_type.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_virtual_oscilloscope.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_w25q32.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_wifi_uart.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_wireless_ch573.c \
E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_wireless_uart.c 

OBJS += \
./zf_device/zf_device_absolute_encoder.o \
./zf_device/zf_device_aht20.o \
./zf_device/zf_device_bluetooth_ch9141.o \
./zf_device/zf_device_camera.o \
./zf_device/zf_device_dl1a.o \
./zf_device/zf_device_dm1xa.o \
./zf_device/zf_device_gps_tau1201.o \
./zf_device/zf_device_icm20602.o \
./zf_device/zf_device_imu660ra.o \
./zf_device/zf_device_imu963ra.o \
./zf_device/zf_device_ips114.o \
./zf_device/zf_device_ips200.o \
./zf_device/zf_device_k24c02.o \
./zf_device/zf_device_key.o \
./zf_device/zf_device_mpu6050.o \
./zf_device/zf_device_mt9v03x_dvp.o \
./zf_device/zf_device_oled.o \
./zf_device/zf_device_scc8660_dvp.o \
./zf_device/zf_device_tft180.o \
./zf_device/zf_device_type.o \
./zf_device/zf_device_virtual_oscilloscope.o \
./zf_device/zf_device_w25q32.o \
./zf_device/zf_device_wifi_uart.o \
./zf_device/zf_device_wireless_ch573.o \
./zf_device/zf_device_wireless_uart.o 

C_DEPS += \
./zf_device/zf_device_absolute_encoder.d \
./zf_device/zf_device_aht20.d \
./zf_device/zf_device_bluetooth_ch9141.d \
./zf_device/zf_device_camera.d \
./zf_device/zf_device_dl1a.d \
./zf_device/zf_device_dm1xa.d \
./zf_device/zf_device_gps_tau1201.d \
./zf_device/zf_device_icm20602.d \
./zf_device/zf_device_imu660ra.d \
./zf_device/zf_device_imu963ra.d \
./zf_device/zf_device_ips114.d \
./zf_device/zf_device_ips200.d \
./zf_device/zf_device_k24c02.d \
./zf_device/zf_device_key.d \
./zf_device/zf_device_mpu6050.d \
./zf_device/zf_device_mt9v03x_dvp.d \
./zf_device/zf_device_oled.d \
./zf_device/zf_device_scc8660_dvp.d \
./zf_device/zf_device_tft180.d \
./zf_device/zf_device_type.d \
./zf_device/zf_device_virtual_oscilloscope.d \
./zf_device/zf_device_w25q32.d \
./zf_device/zf_device_wifi_uart.d \
./zf_device/zf_device_wireless_ch573.d \
./zf_device/zf_device_wireless_uart.d 


# Each subdirectory must supply rules for building sources it contributes
zf_device/zf_device_absolute_encoder.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_absolute_encoder.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_aht20.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_aht20.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_bluetooth_ch9141.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_bluetooth_ch9141.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_camera.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_camera.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_dl1a.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_dl1a.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_dm1xa.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_dm1xa.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_gps_tau1201.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_gps_tau1201.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_icm20602.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_icm20602.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_imu660ra.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_imu660ra.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_imu963ra.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_imu963ra.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_ips114.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_ips114.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_ips200.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_ips200.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_k24c02.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_k24c02.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_key.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_key.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_mpu6050.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_mpu6050.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_mt9v03x_dvp.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_mt9v03x_dvp.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_oled.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_oled.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_scc8660_dvp.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_scc8660_dvp.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_tft180.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_tft180.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_type.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_type.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_virtual_oscilloscope.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_virtual_oscilloscope.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_w25q32.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_w25q32.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_wifi_uart.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_wifi_uart.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_wireless_ch573.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_wireless_ch573.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_device/zf_device_wireless_uart.o: E:/wch307/CHV307_Library-master/Example/libraries/zf_device/zf_device_wireless_uart.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\wch307\CHV307_Library-master\Example\Libraries\doc" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Core" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Ld" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"E:\wch307\CHV307_Library-master\Example\libraries\sdk\Startup" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\user\inc" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_common" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_device" -I"E:\wch307\CHV307_Library-master\Example\E02_uart_demo\code" -I"E:\wch307\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

