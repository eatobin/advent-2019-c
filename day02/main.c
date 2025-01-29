#include <stdio.h>
#include <string.h>

const int memoryLength = 121;
const int memoryContents[memoryLength] = {1, 0, 0, 3, 1, 1, 2, 3, 1, 3, 4, 3, 1, 5, 0, 3, 2, 10, 1, 19, 2, 9, 19, 23, 2, 13, 23, 27, 1, 6, 27, 31, 2, 6, 31, 35, 2, 13, 35, 39, 1, 39, 10, 43, 2, 43, 13, 47, 1, 9, 47, 51, 1, 51, 13, 55, 1, 55, 13, 59, 2, 59, 13, 63, 1, 63, 6, 67, 2, 6, 67, 71, 1, 5, 71, 75, 2, 6, 75, 79, 1, 5, 79, 83, 2, 83, 6, 87, 1, 5, 87, 91, 1, 6, 91, 95, 2, 95, 6, 99, 1, 5, 99, 103, 1, 6, 103, 107, 1, 107, 2, 111, 1, 111, 5, 0, 99, 2, 14, 0, 0};

typedef struct Intcode {
    int pointer;
    int *contents;
} anIntcode;


int opcode(anIntcode *intcode);
void updated_memory(anIntcode *intcode, int noun, int verb);
int noun_verb(void);

int main(void) {
    anIntcode intcode = {
            .contents = memcpy(intcode.contents, memoryContents, sizeof(memoryContents)),
            .pointer = 0};

    int ic_return = 1;
    updated_memory(&intcode, 12, 2);

    while (ic_return == 1) {
        ic_return = opcode(&intcode);
    }

    printf("Part A answer = %d\n", intcode.contents[0]);// Part A answer = 2890696
    printf("Part B answer = %d\n", noun_verb());               // Part B answer = 8226


    return 0;
}

int opcode(anIntcode *intcode) {

    const int action = intcode->contents[intcode->pointer];
    const int address1 = intcode->contents[intcode->pointer + 1];
    const int address2 = intcode->contents[intcode->pointer + 2];
    const int address3 = intcode->contents[intcode->pointer + 3];

    switch (action) {
        case 1:
            intcode->contents[address3] =
                    intcode->contents[address1] +
                    intcode->contents[address2];
            intcode->pointer += 4;
            return 1;
        case 2:
            intcode->contents[address3] =
                    intcode->contents[address1] *
                    intcode->contents[address2];
            intcode->pointer += 4;
            return 1;
        default:
            return 0;
    }
}

void updated_memory(anIntcode *intcode, int noun, int verb) {
    intcode->contents[1] = noun;
    intcode->contents[2] = verb;
}

int noun_verb(void) {
    anIntcode intcode;

    for (int noun = 0; noun < 100; noun++) {
        for (int verb = 0; verb < 100; verb++) {
            anIntcode intcode = {
                    .contents = memcpy(intcode.contents, memoryContents, sizeof(memoryContents)),
                    .pointer = 0};
            updated_memory(&intcode, noun, verb);

            int ic_return = 1;
            while (ic_return == 1) {
                ic_return = opcode(&intcode);
            }

            const int candidate = intcode.contents[0];
            if (candidate == 19690720) {
                return (100 * noun) + verb;
            }
        }
    }
    return -1;
}
