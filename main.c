#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
    Chunk chunk;
    initVm();
    initChunk(&chunk);
    disassembleChunk(&chunk, "test chunk");

    freeVm();
    interpret(&chunk);
    freeChunk(&chunk);
    return 0;
}
