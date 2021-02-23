#pragma once
#include "smem.h"

namespace smem {
    template <typename T, typename ...Args> 
    T* MemoryGuard::new_item(Args&&... args) {
        allocations.push_back(std::malloc(sizeof(T)));
        return new (allocations.back()) T(std::forward<Args>(args)...);
    }

    void* MemoryGuard::allocate_bytes(std::size_t nbytes=1) {
        allocations.push_back(std::malloc(nbytes));
        return static_cast<void*>(allocations.back());
    }

    std::size_t MemoryGuard::count_allocations() const {
        return allocations.size();
    }

    MemoryGuard::~MemoryGuard() {
        for (auto& allocation : allocations) {
            std::free(&allocation);
        }
    }

    void MemoryGuard::free(void** buffer_ptr) {
        if (*buffer_ptr != NULL) {
            std::free(*buffer_ptr);
            *buffer_ptr = NULL;
        }
    }

    MemoryGuard create_memory_guard() {
        return MemoryGuard();
    }
}
