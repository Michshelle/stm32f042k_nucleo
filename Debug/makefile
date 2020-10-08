################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
RNG.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
RNG.list \

OBJCOPY_BIN += \
RNG.bin \


# All Target
all: RNG.elf secondary-outputs

# Tool invocations
RNG.elf: $(OBJS) $(USER_OBJS) /Users/shengyisong/STM32CubeIDE/workspace_1.4.0/RNG/STM32F042K6TX_FLASH.ld
	arm-none-eabi-gcc -o "RNG.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"/Users/shengyisong/STM32CubeIDE/workspace_1.4.0/RNG/STM32F042K6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="RNG.map" -Wl,--gc-sections -static -L/Users/shengyisong/Documents/stm32_docs/STM32CubeExpansion_Crypto_V3.1.0/Fw_Crypto/STM32F0/Middlewares/ST/STM32_Cryptographic/Lib --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

RNG.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "RNG.list"
	@echo 'Finished building: $@'
	@echo ' '

RNG.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "RNG.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
