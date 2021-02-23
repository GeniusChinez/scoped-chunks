#include "smem.cpp"
#include <iostream>

int main() {
    auto arena = smem::create_arena();

    auto temp_a = arena.new_item<int>(3);
    auto temp_b = static_cast<int*>(arena.allocate_bytes(23));

    (void)temp_a;
    (void)temp_b;

    return 0;
}
