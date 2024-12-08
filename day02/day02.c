#include <stdio.h>
#include <stdlib.h>

#include "file_fns.h"

typedef struct Memory {
    int *contents;// dynamically allocated - need free
    int length;
} aMemory;

typedef struct Intcode {
    int pointer;
    aMemory memory;
} anIntcode;

int opcode(anIntcode *intcode);
void updated_memory(const anIntcode *intcode, int noun, int verb);
int noun_verb(void);

int main(void) {
    anIntcode intcode;

    intcode.pointer = 0;
    intcode.memory = return_memory("day02.csv");
    int ic_return = 1;

    updated_memory(&intcode, 12, 2);

    while (ic_return == 1) {
        ic_return = opcode(&intcode);
    }

    printf("Memory length: %d\n\n", intcode.memory.length);

    printf("Part A answer = %d\n", intcode.memory.contents[0]);// Part A answer = 2890696
    printf("Part B answer = %d\n", noun_verb());               // Part B answer = 8226

    free(intcode.memory.contents);
    intcode.memory.contents = NULL;

    return 0;
}

int opcode(struct Intcode *intcode) {

    const int action = intcode->memory.contents[intcode->pointer];
    const int address1 = intcode->memory.contents[intcode->pointer + 1];
    const int address2 = intcode->memory.contents[intcode->pointer + 2];
    const int address3 = intcode->memory.contents[intcode->pointer + 3];

    switch (action) {
        case 1:
            intcode->memory.contents[address3] =
                    intcode->memory.contents[address1] +
                    intcode->memory.contents[address2];
            intcode->pointer += 4;
            return 1;
        case 2:
            intcode->memory.contents[address3] =
                    intcode->memory.contents[address1] *
                    intcode->memory.contents[address2];
            intcode->pointer += 4;
            return 1;
        default:
            return 0;
    }
}

void updated_memory(const struct Intcode *intcode, const int noun, const int verb) {
    intcode->memory.contents[1] = noun;
    intcode->memory.contents[2] = verb;
}

int noun_verb(void) {
    struct Intcode intcode;

    for (int noun = 0; noun < 100; noun++) {
        for (int verb = 0; verb < 100; verb++) {
            const aMemory memory = return_memory("day02.csv");
            intcode.pointer = 0;
            intcode.memory = memory;
            updated_memory(&intcode, noun, verb);

            int ic_return = 1;
            while (ic_return == 1) {
                ic_return = opcode(&intcode);
            }

            const int candidate = intcode.memory.contents[0];
            if (candidate == 19690720) {
                return (100 * noun) + verb;
            }
        }
    }
    return -1;
}
