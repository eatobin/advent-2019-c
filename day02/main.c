#include <stdio.h>
#include <stdlib.h>

#include "file_fns.h"

struct Memory {
    int *contents;
    int length;
};

struct Intcode {
    int pointer;
    struct Memory memory;
};

int opcode(struct Intcode *intcode);
void updated_memory(struct Intcode *intcode, int noun, int verb);
int noun_verb(void);

int main(void) {
    struct Memory memory;
    struct Intcode intcode;

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

    return 0;
}

int opcode(struct Intcode *intcode) {
    int action;
    int address1;
    int address2;
    int address3;

    action = intcode->memory.contents[intcode->pointer];
    address1 = intcode->memory.contents[intcode->pointer + 1];
    address2 = intcode->memory.contents[intcode->pointer + 2];
    address3 = intcode->memory.contents[intcode->pointer + 3];

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
    }
    return 0;
}

void updated_memory(struct Intcode *intcode, int noun, int verb) {
    intcode->memory.contents[1] = noun;
    intcode->memory.contents[2] = verb;
}

int noun_verb(void) {
    int noun;
    int verb;
    struct Memory memory;
    struct Intcode intcode;
    int ic_return;
    int candidate;

    for (noun = 0; noun < 100; noun++) {
        for (verb = 0; verb < 100; verb++) {
            memory = return_memory("day02.csv");
            intcode.pointer = 0;
            intcode.memory = memory;
            updated_memory(&intcode, noun, verb);

            ic_return = 1;
            while (ic_return == 1) {
                ic_return = opcode(&intcode);
            }

            candidate = intcode.memory.contents[0];
            if (candidate == 19690720) {
                goto end;
            }
        }
    }
end:
    return (100 * noun) + verb;
}
