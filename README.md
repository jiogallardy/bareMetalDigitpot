# Documentation beginning for the challenge project for Jovany (Jio) Gallardy

## This project relies on an Arm Cortex M4 STM32F407 as the mcu selected

Please find the datasheet for the mcu here [Datasheet](https://www.st.com/resource/en/reference_manual/dm00031020-stm32f405-415-stm32f407-417-stm32f427-437-and-stm32f429-439-advanced-arm-based-32-bit-mcus-stmicroelectronics.pdf) 

## Additional assumptions
We are assuming that we are using the 10K Ohm model from the provided datasheet

## Additional Notes about power up and power down
The state of the taps is not stored between power up and down sessions so it starts out at the 128 tap point, additional code would be needed to handle this feature. 

### Testing, Ceedling
A basic testing environment has been setup. 
To run a simple unit test, simply run `docker compose run ceedling`, then `ceedling test:all`

Code has been clang formatted