################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libs/joystick/src/joystick.c 

OBJS += \
./libs/joystick/src/joystick.o 

C_DEPS += \
./libs/joystick/src/joystick.d 


# Each subdirectory must supply rules for building sources it contributes
libs/joystick/src/%.o libs/joystick/src/%.su libs/joystick/src/%.cyclo: ../libs/joystick/src/%.c libs/joystick/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-libs-2f-joystick-2f-src

clean-libs-2f-joystick-2f-src:
	-$(RM) ./libs/joystick/src/joystick.cyclo ./libs/joystick/src/joystick.d ./libs/joystick/src/joystick.o ./libs/joystick/src/joystick.su

.PHONY: clean-libs-2f-joystick-2f-src

