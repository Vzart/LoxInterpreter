#include <stdio.h>
#include "common.h"
#include "vm.h"

VM vm;

void initVm() {

}

void freeVm() {

}

static InterpretResult run() {
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
#define READ_CONSTANT_LONG() (vm.chunk->constants.values[(READ_BYTE() | READ_BYTE() << 8 | READ_BYTE() << 16)])

    for (;;) {
        uint8_t instruction;
        switch (instruction = READ_BYTE()) {
            case OP_CONSTANT: {
                Value constant = READ_CONSTANT();
                printValue(constant);
                printf("\n");
                break;
            }
            case OP_CONSTANT_LONG : {
                Value constant = READ_CONSTANT_LONG();
                printValue(constant);
                printf("\n");
            }
            case OP_RETURN: {
                return INTERPRET_OK;
            }



        }
    }
#undef READ_BYTE
#undef READ_CONSTANT
#undef READ_CONSTANT_LONG
}

InterpretResult interpret(Chunk* chunk) {
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;
    return run();
}