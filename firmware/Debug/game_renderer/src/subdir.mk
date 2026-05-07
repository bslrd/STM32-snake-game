################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../game_renderer/src/game_renderer.c 

OBJS += \
./game_renderer/src/game_renderer.o 

C_DEPS += \
./game_renderer/src/game_renderer.d 


# Each subdirectory must supply rules for building sources it contributes
game_renderer/src/%.o game_renderer/src/%.su game_renderer/src/%.cyclo: ../game_renderer/src/%.c game_renderer/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/Debug" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/2dspace" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/game" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/game_renderer" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/joystick" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/snake" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/ws2812b" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-game_renderer-2f-src

clean-game_renderer-2f-src:
	-$(RM) ./game_renderer/src/game_renderer.cyclo ./game_renderer/src/game_renderer.d ./game_renderer/src/game_renderer.o ./game_renderer/src/game_renderer.su

.PHONY: clean-game_renderer-2f-src

