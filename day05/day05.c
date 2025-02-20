#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Instruction:
// ABCDE
// 01234
// 01002
// 34 - two-digit opcode,      02 == opcode 2
//  2 - mode of 1st parameter,  0 == position mode
//  1 - mode of 2nd parameter,  1 == immediate mode
//  0 - mode of 3rd parameter,  0 == position mode,
//                                   omitted due to being a leading zero
// 0 1 or 2 = left-to-right position after 2 digit opcode
// p i or r = position, immediate or relative mode
// r or w = read or write

typedef struct Intcode {
    int input;
    int output;
    int pointer;
    int memory[5];
} anIntcode;

typedef int *Instruction;

int const offsetA = 3;
int const offsetB = 2;
int const offsetC = 1;

anIntcode makeIntcode(void);
Instruction pad5(int op, int *instruction);
int opcode(anIntcode *intcode);

int main(void) {
    anIntcode intcode = makeIntcode();
    int *instruction = malloc(5 * sizeof(int));
    if (instruction == NULL) {
        perror("Failed to allocate memory");
        exit(1);
    }

    int ic_return = 1;
    while (ic_return == 1) {
        ic_return = opcode(&intcode);
    }

    printf("Part A answer = %d. Correct = 2890696\n", intcode.memory[0]);
    printf("Part A answer = %d. Correct = 2890696\n", intcode.input);
    printf("Part A answer = %d. Correct = 2890696\n", intcode.output);
    printf("\n");

    instruction = pad5(6789, instruction);

    for (int i = 0; i < 5; i++) {
        printf("%d ", instruction[i]);
    }

    printf("\n");
    printf("%p\n", instruction);

    instruction = pad5(541, instruction);

    for (int i = 0; i < 5; i++) {
        printf("%d ", instruction[i]);
    }
    printf("\n");
    printf("%p\n", instruction);

    instruction = pad5(8, instruction);

    for (int i = 0; i < 5; i++) {
        printf("%d ", instruction[i]);
    }
    printf("\n");
    printf("%p\n", instruction);

    free(instruction);

    return 0;
}

// int zeroParam(const Instruction instruction) {
//     int choice;
//     switch (instruction[0]) {
//         case 0:// 0-p-w
//             choice = 12;
//         default:
//             choice = 42;
//     }
//     return choice;
// }

// func (icP *IntCode) aParam(instruction Instruction) int {
//     var choice int
//     switch instruction['a'] {
//         case 0: // a-p-w
//             choice = icP.Memory[icP.Pointer+offsetA]
//         case 2: // a-r-w
//             choice = icP.Memory[icP.Pointer+offsetA] + icP.RelativeBase
//         }
//     return choice
// }


anIntcode makeIntcode(void) {
    // const int memoryContents[678] = {3, 225, 1, 225, 6, 6, 1100, 1, 238, 225, 104, 0, 1102, 79, 14, 225, 1101, 17, 42, 225, 2, 74, 69, 224, 1001, 224, -5733, 224, 4, 224, 1002, 223, 8, 223, 101, 4, 224, 224, 1, 223, 224, 223, 1002, 191, 83, 224, 1001, 224, -2407, 224, 4, 224, 102, 8, 223, 223, 101, 2, 224, 224, 1, 223, 224, 223, 1101, 18, 64, 225, 1102, 63, 22, 225, 1101, 31, 91, 225, 1001, 65, 26, 224, 101, -44, 224, 224, 4, 224, 102, 8, 223, 223, 101, 3, 224, 224, 1, 224, 223, 223, 101, 78, 13, 224, 101, -157, 224, 224, 4, 224, 1002, 223, 8, 223, 1001, 224, 3, 224, 1, 224, 223, 223, 102, 87, 187, 224, 101, -4698, 224, 224, 4, 224, 102, 8, 223, 223, 1001, 224, 4, 224, 1, 223, 224, 223, 1102, 79, 85, 224, 101, -6715, 224, 224, 4, 224, 1002, 223, 8, 223, 1001, 224, 2, 224, 1, 224, 223, 223, 1101, 43, 46, 224, 101, -89, 224, 224, 4, 224, 1002, 223, 8, 223, 101, 1, 224, 224, 1, 223, 224, 223, 1101, 54, 12, 225, 1102, 29, 54, 225, 1, 17, 217, 224, 101, -37, 224, 224, 4, 224, 102, 8, 223, 223, 1001, 224, 3, 224, 1, 223, 224, 223, 1102, 20, 53, 225, 4, 223, 99, 0, 0, 0, 677, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1105, 0, 99999, 1105, 227, 247, 1105, 1, 99999, 1005, 227, 99999, 1005, 0, 256, 1105, 1, 99999, 1106, 227, 99999, 1106, 0, 265, 1105, 1, 99999, 1006, 0, 99999, 1006, 227, 274, 1105, 1, 99999, 1105, 1, 280, 1105, 1, 99999, 1, 225, 225, 225, 1101, 294, 0, 0, 105, 1, 0, 1105, 1, 99999, 1106, 0, 300, 1105, 1, 99999, 1, 225, 225, 225, 1101, 314, 0, 0, 106, 0, 0, 1105, 1, 99999, 107, 226, 226, 224, 1002, 223, 2, 223, 1006, 224, 329, 101, 1, 223, 223, 1108, 677, 226, 224, 1002, 223, 2, 223, 1006, 224, 344, 101, 1, 223, 223, 7, 677, 226, 224, 102, 2, 223, 223, 1006, 224, 359, 101, 1, 223, 223, 108, 226, 226, 224, 1002, 223, 2, 223, 1005, 224, 374, 101, 1, 223, 223, 8, 226, 677, 224, 1002, 223, 2, 223, 1006, 224, 389, 101, 1, 223, 223, 1108, 226, 226, 224, 102, 2, 223, 223, 1006, 224, 404, 101, 1, 223, 223, 1007, 677, 677, 224, 1002, 223, 2, 223, 1006, 224, 419, 101, 1, 223, 223, 8, 677, 677, 224, 1002, 223, 2, 223, 1005, 224, 434, 1001, 223, 1, 223, 1008, 226, 226, 224, 102, 2, 223, 223, 1005, 224, 449, 1001, 223, 1, 223, 1008, 226, 677, 224, 102, 2, 223, 223, 1006, 224, 464, 101, 1, 223, 223, 1107, 677, 677, 224, 102, 2, 223, 223, 1006, 224, 479, 101, 1, 223, 223, 107, 677, 677, 224, 1002, 223, 2, 223, 1005, 224, 494, 1001, 223, 1, 223, 1107, 226, 677, 224, 1002, 223, 2, 223, 1005, 224, 509, 101, 1, 223, 223, 1108, 226, 677, 224, 102, 2, 223, 223, 1006, 224, 524, 101, 1, 223, 223, 7, 226, 226, 224, 1002, 223, 2, 223, 1005, 224, 539, 101, 1, 223, 223, 108, 677, 677, 224, 1002, 223, 2, 223, 1005, 224, 554, 101, 1, 223, 223, 8, 677, 226, 224, 1002, 223, 2, 223, 1005, 224, 569, 1001, 223, 1, 223, 1008, 677, 677, 224, 102, 2, 223, 223, 1006, 224, 584, 101, 1, 223, 223, 107, 226, 677, 224, 102, 2, 223, 223, 1005, 224, 599, 1001, 223, 1, 223, 7, 226, 677, 224, 102, 2, 223, 223, 1005, 224, 614, 101, 1, 223, 223, 1007, 226, 226, 224, 1002, 223, 2, 223, 1005, 224, 629, 101, 1, 223, 223, 1107, 677, 226, 224, 1002, 223, 2, 223, 1006, 224, 644, 101, 1, 223, 223, 108, 226, 677, 224, 102, 2, 223, 223, 1006, 224, 659, 101, 1, 223, 223, 1007, 677, 226, 224, 102, 2, 223, 223, 1006, 224, 674, 101, 1, 223, 223, 4, 223, 99, 226};
    const int memoryContents[5] = {3, 0, 4, 0, 99};
    // const int memoryContents[5] = {1002, 4, 3, 4, 33};
    anIntcode intcode;
    intcode.input = 42;
    intcode.output = 0;
    intcode.pointer = 0;
    memcpy(intcode.memory, memoryContents, sizeof(memoryContents));
    return intcode;
}

Instruction pad5(int op, int *instruction) {
    char buffer[6];
    snprintf(buffer, 6, "%05d", op);
    for (int i = 0; i < 5; i++) {
        instruction[i] = buffer[i] - '0';
    }
    return instruction;
}

int opcode(anIntcode *intcode) {
    switch (intcode->memory[intcode->pointer]) {
        case 1:
            intcode->memory[intcode->pointer + offsetA] =
                    intcode->memory[intcode->memory[intcode->pointer + offsetC]] +
                    intcode->memory[intcode->memory[intcode->pointer + offsetB]];
            intcode->pointer += 4;
            return 1;
        case 2:
            intcode->memory[intcode->pointer + offsetA] =
                    intcode->memory[intcode->memory[intcode->pointer + offsetC]] *
                    intcode->memory[intcode->memory[intcode->pointer + offsetB]];
            intcode->pointer += 4;
            return 1;
        case 3:
            intcode->memory[intcode->memory[intcode->pointer + offsetC]] = intcode->input;
            intcode->pointer += 2;
        case 4:
            intcode->output = intcode->memory[intcode->memory[intcode->pointer + offsetC]];
            intcode->pointer += 2;
        default:
            return 0;
    }
}
