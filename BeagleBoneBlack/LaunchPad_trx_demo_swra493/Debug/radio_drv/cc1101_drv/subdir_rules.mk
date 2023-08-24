################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
radio_drv/cc1101_drv/cc1101_drv.obj: ../radio_drv/cc1101_drv/cc1101_drv.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/bin/cl430" -vmspx --abi=eabi --data_model=restricted -O2 --opt_for_speed=0 --use_hw_mpy=F5 --include_path="C:/ti/ccsv6/ccs_base/msp430/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/include" --include_path="C:/Project/LaunchPad_trx_demo/hal_mcu" --include_path="C:/Project/LaunchPad_trx_demo/radio_drv" --include_path="C:/Project/LaunchPad_trx_demo/uart_drv" --include_path="C:/Project/LaunchPad_trx_demo/radio_drv/cc1101_drv" --include_path="C:/Project/LaunchPad_trx_demo/radio_drv/cc112x_drv" --include_path="C:/Project/LaunchPad_trx_demo/radio_drv/cc1190_drv" --advice:power="all" -g --define=__MSP430F5529__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="radio_drv/cc1101_drv/cc1101_drv.pp" --obj_directory="radio_drv/cc1101_drv" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

radio_drv/cc1101_drv/cc1101_utils.obj: ../radio_drv/cc1101_drv/cc1101_utils.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/bin/cl430" -vmspx --abi=eabi --data_model=restricted -O2 --opt_for_speed=0 --use_hw_mpy=F5 --include_path="C:/ti/ccsv6/ccs_base/msp430/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/include" --include_path="C:/Project/LaunchPad_trx_demo/hal_mcu" --include_path="C:/Project/LaunchPad_trx_demo/radio_drv" --include_path="C:/Project/LaunchPad_trx_demo/uart_drv" --include_path="C:/Project/LaunchPad_trx_demo/radio_drv/cc1101_drv" --include_path="C:/Project/LaunchPad_trx_demo/radio_drv/cc112x_drv" --include_path="C:/Project/LaunchPad_trx_demo/radio_drv/cc1190_drv" --advice:power="all" -g --define=__MSP430F5529__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="radio_drv/cc1101_drv/cc1101_utils.pp" --obj_directory="radio_drv/cc1101_drv" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


