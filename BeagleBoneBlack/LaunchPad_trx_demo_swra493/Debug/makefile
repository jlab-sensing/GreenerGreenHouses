################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4

ORDERED_OBJS += \
"./LaunchPad_trx_demo.obj" \
"./LaunchPad_trx_main.obj" \
"./uart_drv/circ_buf.obj" \
"./uart_drv/ee_printf.obj" \
"./uart_drv/uart_drv.obj" \
"./radio_drv/hal_spi_rf.obj" \
"./radio_drv/cc1190_drv/cc1190_drv.obj" \
"./radio_drv/cc112x_drv/cc112x_drv.obj" \
"./radio_drv/cc112x_drv/cc112x_utils.obj" \
"./radio_drv/cc1101_drv/cc1101_drv.obj" \
"./radio_drv/cc1101_drv/cc1101_utils.obj" \
"./hal_mcu/hal_f2_timerA0.obj" \
"./hal_mcu/hal_f2_timerB0.obj" \
"./hal_mcu/hal_f5_timerB0.obj" \
"./hal_mcu/hal_mcu.obj" \
"../lnk_msp430f5529.cmd" \
$(GEN_CMDS__FLAG) \
-l"libc.a" \
-l"libmath.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include uart_drv/subdir_vars.mk
-include radio_drv/subdir_vars.mk
-include radio_drv/cc1190_drv/subdir_vars.mk
-include radio_drv/cc112x_drv/subdir_vars.mk
-include radio_drv/cc1101_drv/subdir_vars.mk
-include hal_mcu/subdir_vars.mk
-include subdir_rules.mk
-include uart_drv/subdir_rules.mk
-include radio_drv/subdir_rules.mk
-include radio_drv/cc1190_drv/subdir_rules.mk
-include radio_drv/cc112x_drv/subdir_rules.mk
-include radio_drv/cc1101_drv/subdir_rules.mk
-include hal_mcu/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
LaunchPad_trx_demo.out \

EXE_OUTPUTS__QUOTED += \
"LaunchPad_trx_demo.out" \

BIN_OUTPUTS += \
LaunchPad_trx_demo.hex \

BIN_OUTPUTS__QUOTED += \
"LaunchPad_trx_demo.hex" \


# All Target
all: LaunchPad_trx_demo.out secondary-outputs

# Tool invocations
LaunchPad_trx_demo.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP430 Linker'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/bin/cl430" -vmspx --abi=eabi --data_model=restricted -O2 --opt_for_speed=0 --use_hw_mpy=F5 --advice:power="all" -g --define=__MSP430F5529__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal -z -m"LaunchPad_trx_demo.map" --heap_size=40 --stack_size=120 --cinit_hold_wdt=on -i"C:/ti/ccsv6/ccs_base/msp430/include" -i"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/lib" -i"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/include" -i"C:/ti/ccsv6/ccs_base/msp430/lib/5xx_6xx_FRxx" --reread_libs --warn_sections --diag_wrap=off --display_error_number --xml_link_info="LaunchPad_trx_demo_linkInfo.xml" --use_hw_mpy=F5 --rom_model -o "LaunchPad_trx_demo.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

LaunchPad_trx_demo.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: MSP430 Hex Utility'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/bin/hex430" --memwidth=8 --romwidth=8 --intel -o "LaunchPad_trx_demo.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "LaunchPad_trx_demo.pp" "LaunchPad_trx_main.pp" "uart_drv\circ_buf.pp" "uart_drv\ee_printf.pp" "uart_drv\uart_drv.pp" "radio_drv\hal_spi_rf.pp" "radio_drv\cc1190_drv\cc1190_drv.pp" "radio_drv\cc112x_drv\cc112x_drv.pp" "radio_drv\cc112x_drv\cc112x_utils.pp" "radio_drv\cc1101_drv\cc1101_drv.pp" "radio_drv\cc1101_drv\cc1101_utils.pp" "hal_mcu\hal_f2_timerA0.pp" "hal_mcu\hal_f2_timerB0.pp" "hal_mcu\hal_f5_timerB0.pp" "hal_mcu\hal_mcu.pp" 
	-$(RM) "LaunchPad_trx_demo.obj" "LaunchPad_trx_main.obj" "uart_drv\circ_buf.obj" "uart_drv\ee_printf.obj" "uart_drv\uart_drv.obj" "radio_drv\hal_spi_rf.obj" "radio_drv\cc1190_drv\cc1190_drv.obj" "radio_drv\cc112x_drv\cc112x_drv.obj" "radio_drv\cc112x_drv\cc112x_utils.obj" "radio_drv\cc1101_drv\cc1101_drv.obj" "radio_drv\cc1101_drv\cc1101_utils.obj" "hal_mcu\hal_f2_timerA0.obj" "hal_mcu\hal_f2_timerB0.obj" "hal_mcu\hal_f5_timerB0.obj" "hal_mcu\hal_mcu.obj" 
	-@echo 'Finished clean'
	-@echo ' '

secondary-outputs: $(BIN_OUTPUTS)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

