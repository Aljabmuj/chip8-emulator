#include <SDL.h>
#include <stdio.h>
#include <string.h>

//initialize the chip-8 font as a global variable

uint8_t fontsize = {
    0xF0, 0x90, 0x90, 0x90, 0xF0, //0
    0x20, 0x60, 0x20, 0x20, 0x70, //1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, //2 
    0xF0, 0x10, 0xF0, 0x10, 0xF0, //3
    0x90, 0x90, 0xF0, 0x10, 0x10, //4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, //5 
    0xF0, 0x80, 0xF0, 0x90, 0xF0, //6
    0xF0, 0x10, 0x20, 0x40, 0x40, //7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, //8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, //9 
    0xF0, 0x90, 0xF0, 0x90, 0x90, //A 
    0xE0, 0x90, 0xE0, 0x90, 0xE0, //B 
    0xF0, 0x80, 0x80, 0x80, 0xF0, //C
    0xE0, 0x90, 0x90, 0x90, 0xE0, //D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, //E
    0xF0, 0x80, 0xF0, 0x80, 0x80, //F
};

typedef struct{ 
    uint8_t mem[4096]; //set up 4096 bytes of RAM 
    uint8_t reg[16]; //16 8-bit registers 

    //create stack and stack pointer 
    uint16_t stack[16]; 
    uint8_t stack_p; 

    uint16_t index; //index register
    uint16_t pc;    //program counter 

    uint8_t delay_timer; //use for handling audio output
    uint8_t sound_timer; 
    

    uint8_t keypad[16]; //set up keypad for user input 
    uint32_t video[64*32]; //set up video output of 64 x 32 for SDL 2 graphcis buffer 
    
    uint16_t opcode; //current opcode 

} Chip_8; 

//clear memory function
int clear_mem(Chip_8 *chip8){ 

    memset(chip8, 0, sizeof(Chip_8));

    //set the pc to start at 0x200
    chip8->pc = 0x200;

}

void chip8_init(Chip_8 *chip8){ 


    memset(chip8, 0, sizeof(Chip_8));

    //set the pc to start at 0x200
    chip8->pc = 0x200;

    for(int i = 0; i < 80; i++){ 
        chip8->mem[0x50+i] = fontsize[i]; 
    }

}

//load up roms using fopen and fclose 
int rom_load(){

}

//create three loops: Fetch, Decode, and Execute

int fetch(){ 


}

int decode(){ 

}

int execute(){ 

}
