################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libs/ws2812b/ws2812b.c \
../libs/ws2812b/ws2812b_matrix.c \
../libs/ws2812b/ws2812b_matrix_symbols.c 

OBJS += \
./libs/ws2812b/ws2812b.o \
./libs/ws2812b/ws2812b_matrix.o \
./libs/ws2812b/ws2812b_matrix_symbols.o 

C_DEPS += \
./libs/ws2812b/ws2812b.d \
./libs/ws2812b/ws2812b_matrix.d \
./libs/ws2812b/ws2812b_matrix_symbols.d 


# Each subdirectory must supply rules for building sources it contributes
libs/ws2812b/%.o libs/ws2812b/%.su libs/ws2812b/%.cyclo: ../libs/ws2812b/%.c libs/ws2812b/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/Debug" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs/2dspace" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs/game" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs/game_renderer" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs/joystick" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs/snake" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs/ws2812b" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-libs-2f-ws2812b

clean-libs-2f-ws2812b:
	-$(RM) ./libs/ws2812b/ws2812b.cyclo ./libs/ws2812b/ws2812b.d ./libs/ws2812b/ws2812b.o ./libs/ws2812b/ws2812b.su ./libs/ws2812b/ws2812b_matrix.cyclo ./libs/ws2812b/ws2812b_matrix.d ./libs/ws2812b/ws2812b_matrix.o ./libs/ws2812b/ws2812b_matrix.su ./libs/ws2812b/ws2812b_matrix_symbols.cyclo ./libs/ws2812b/ws2812b_matrix_symbols.d ./libs/ws2812b/ws2812b_matrix_symbols.o ./libs/ws2812b/ws2812b_matrix_symbols.su

.PHONY: clean-libs-2f-ws2812b

