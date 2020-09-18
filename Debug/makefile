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
blinky_n_talky.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
blinky_n_talky.list \

OBJCOPY_BIN += \
blinky_n_talky.bin \


# All Target
all: blinky_n_talky.elf secondary-outputs

# Tool invocations
blinky_n_talky.elf: $(OBJS) $(USER_OBJS) /Users/shengyisong/STM32CubeIDE/workspace_1.4.0/blinky_n_talky/STM32F042K6TX_FLASH.ld
	arm-none-eabi-gcc -o "blinky_n_talky.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"/Users/shengyisong/STM32CubeIDE/workspace_1.4.0/blinky_n_talky/STM32F042K6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="blinky_n_talky.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

blinky_n_talky.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "blinky_n_talky.list"
	@echo 'Finished building: $@'
	@echo ' '

blinky_n_talky.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "blinky_n_talky.bin"
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
