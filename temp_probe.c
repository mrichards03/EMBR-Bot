#include <stdio.h>
#include <string.h>
#include "hardware/spi.h"

#define MISO 16
#define CS   17
#define SCLK 18
#define MOSI 19

#define SPI_PORT spi0

int32_t t_fine;
uint16_t dig_T1;
int16_t dig_T2, dig_T3;

int32_t compTemp(int32_t adc_T){
    int32_t var1, var2, T;
    var1 = ((((adc_T >> 3) - ((int32_t) dig_T1 << 1))) * ((int32_t) dig_T2)) >> 11;
    var2 = (((((adc_T >> 4) - ((int32_t) dig_T1)) * ((adc_T >> 4) - ((int32_t) dig_T1))) >> 12) * ((int32_t) dig_T3)) >> 14;

    t_fine = var1 + var2;
    T = (t_fine * 5 + 128) >> 8;
    return T;
}

void read_temp_comp(){
    uint8_t buffer[6], reg;

    reg = 0x88 | 0x80;
    gpio_put(CS, 0);
    spi_write_blocking(SPI_PORT, &reg, 1);
    spi_read_blocking(SPI_PORT, 0, buffer, 6);
    gpio_put(CS, 1);

    dig_T1 = buffer[0] | (buffer[1] << 8);
    dig_T2 = buffer[2] | (buffer[3] << 8);
    dig_T3 = buffer[4] | (buffer[5] << 8);
}

int main(){
    stdio_init_all(); // Initialise I/O for USB Serial

    spi_init(SPI_PORT, 500000); // Initialise spi0 at 500kHz
    
    //Initialise GPIO pins for SPI communication
    gpio_set_function(MISO, GPIO_FUNC_SPI);
    gpio_set_function(SCLK, GPIO_FUNC_SPI);
    gpio_set_function(MOSI, GPIO_FUNC_SPI);

    // Configure Chip Select
    gpio_init(CS); // Initialise CS Pin
    gpio_set_dir(CS, GPIO_OUT); // Set CS as output
    gpio_put(CS, 1); // Set CS High to indicate no currect SPI communication

    read_temp_comp(); // Read factory calibration/compensation values

    // Write Operation Example! Set oversampling and power on chip
    uint8_t data[2]; // Array to store data to be sent
    data[0] = 0xF4 & 0x7F; // Remove first bit to indicate write operation
    data[1] = 0x27; // Data to be sent
    gpio_put(CS, 0); // Indicate beginning of communication
    spi_write_blocking(SPI_PORT, data, 2); // Send data[]
    gpio_put(CS, 1); // Signal end of communication

    int32_t temperature, rawtemp;
    uint8_t reg, buffer[3];

    while(1){
        reg = 0xFA | 0X80;
        gpio_put(CS, 0);
        spi_write_blocking(SPI_PORT, &reg, 1);
        spi_read_blocking(SPI_PORT, 0, buffer, 3);
        gpio_put(CS, 1);

        rawtemp = ((uint32_t) buffer[0] << 12) | ((uint32_t) buffer[1] << 4) | ((uint32_t) buffer[2] >> 4);

        temperature = compTemp(rawtemp);

        printf("Temp = %.2fC \n", temperature / 100.00);

        sleep_ms(1000);
    }
}
