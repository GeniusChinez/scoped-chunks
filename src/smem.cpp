#pragma once
#include "smem.h"

namespace smem {
    template <typename T, typename ...Args> 
    T* Arena::new_item(Args&&... args) {
        allocations.push_back(std::malloc(sizeof(T)));
        return new (allocations.back()) T(std::forward<Args>(args)...);
    }

    void* Arena::allocate_bytes(std::size_t nbytes=1) {
        allocations.push_back(std::malloc(nbytes));
        return static_cast<void*>(allocations.back());
    }

    std::size_t Arena::count_allocations() const {
        return allocations.size();
    }

    Arena::~Arena() {
        for (auto location : allocations) {
            std::free(location);
        }
    }

    Arena create_arena() {
        return Arena();
    }
}