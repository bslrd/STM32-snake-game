################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libs/snake/src/snake.c 

OBJS += \
./libs/snake/src/snake.o 

C_DEPS += \
./libs/snake/src/snake.d 


# Each subdirectory must supply rules for building sources it contributes
libs/snake/src/%.o libs/snake/src/%.su libs/snake/src/%.cyclo: ../libs/snake/src/%.c libs/snake/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-libs-2f-snake-2f-src

clean-libs-2f-snake-2f-src:
	-$(RM) ./libs/snake/src/snake.cyclo ./libs/snake/src/snake.d ./libs/snake/src/snake.o ./libs/snake/src/snake.su

.PHONY: clean-libs-2f-snake-2f-src

