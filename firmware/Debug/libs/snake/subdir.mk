################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libs/snake/snake.c 

OBJS += \
./libs/snake/snake.o 

C_DEPS += \
./libs/snake/snake.d 


# Each subdirectory must supply rules for building sources it contributes
libs/snake/%.o libs/snake/%.su libs/snake/%.cyclo: ../libs/snake/%.c libs/snake/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/firmware/libs" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/firmware/Debug" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/firmware/libs/2dspace" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/firmware/libs/game" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/firmware/libs/game_renderer" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/firmware/libs/joystick" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/firmware/libs/snake" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/firmware/libs/ws2812b" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-libs-2f-snake

clean-libs-2f-snake:
	-$(RM) ./libs/snake/snake.cyclo ./libs/snake/snake.d ./libs/snake/snake.o ./libs/snake/snake.su

.PHONY: clean-libs-2f-snake

