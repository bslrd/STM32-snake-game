################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ws2812b/src/ws2812b.c \
../ws2812b/src/ws2812b_matrix.c \
../ws2812b/src/ws2812b_matrix_symbols.c 

OBJS += \
./ws2812b/src/ws2812b.o \
./ws2812b/src/ws2812b_matrix.o \
./ws2812b/src/ws2812b_matrix_symbols.o 

C_DEPS += \
./ws2812b/src/ws2812b.d \
./ws2812b/src/ws2812b_matrix.d \
./ws2812b/src/ws2812b_matrix_symbols.d 


# Each subdirectory must supply rules for building sources it contributes
ws2812b/src/%.o ws2812b/src/%.su ws2812b/src/%.cyclo: ../ws2812b/src/%.c ws2812b/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/Debug" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/2dspace" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/game" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/game_renderer" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/joystick" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/snake" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/ws2812b" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ws2812b-2f-src

clean-ws2812b-2f-src:
	-$(RM) ./ws2812b/src/ws2812b.cyclo ./ws2812b/src/ws2812b.d ./ws2812b/src/ws2812b.o ./ws2812b/src/ws2812b.su ./ws2812b/src/ws2812b_matrix.cyclo ./ws2812b/src/ws2812b_matrix.d ./ws2812b/src/ws2812b_matrix.o ./ws2812b/src/ws2812b_matrix.su ./ws2812b/src/ws2812b_matrix_symbols.cyclo ./ws2812b/src/ws2812b_matrix_symbols.d ./ws2812b/src/ws2812b_matrix_symbols.o ./ws2812b/src/ws2812b_matrix_symbols.su

.PHONY: clean-ws2812b-2f-src

