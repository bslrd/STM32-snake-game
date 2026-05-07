################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libs/game_renderer/game_renderer.c 

OBJS += \
./libs/game_renderer/game_renderer.o 

C_DEPS += \
./libs/game_renderer/game_renderer.d 


# Each subdirectory must supply rules for building sources it contributes
libs/game_renderer/%.o libs/game_renderer/%.su libs/game_renderer/%.cyclo: ../libs/game_renderer/%.c libs/game_renderer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/Debug" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs/2dspace" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs/game" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs/game_renderer" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs/joystick" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs/snake" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs/ws2812b" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-libs-2f-game_renderer

clean-libs-2f-game_renderer:
	-$(RM) ./libs/game_renderer/game_renderer.cyclo ./libs/game_renderer/game_renderer.d ./libs/game_renderer/game_renderer.o ./libs/game_renderer/game_renderer.su

.PHONY: clean-libs-2f-game_renderer

