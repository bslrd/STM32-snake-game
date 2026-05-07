################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f303retx.s 

OBJS += \
./Core/Startup/startup_stm32f303retx.o 

S_DEPS += \
./Core/Startup/startup_stm32f303retx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/Debug" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs/2dspace" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs/game" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs/game_renderer" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs/joystick" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs/snake" -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs/ws2812b" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f303retx.d ./Core/Startup/startup_stm32f303retx.o

.PHONY: clean-Core-2f-Startup

