################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libs/game/src/game.c 

OBJS += \
./libs/game/src/game.o 

C_DEPS += \
./libs/game/src/game.d 


# Each subdirectory must supply rules for building sources it contributes
libs/game/src/%.o libs/game/src/%.su libs/game/src/%.cyclo: ../libs/game/src/%.c libs/game/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"/Users/dominik/Desktop/STM/WORKSPACE/LED_MATRIX/libs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-libs-2f-game-2f-src

clean-libs-2f-game-2f-src:
	-$(RM) ./libs/game/src/game.cyclo ./libs/game/src/game.d ./libs/game/src/game.o ./libs/game/src/game.su

.PHONY: clean-libs-2f-game-2f-src

