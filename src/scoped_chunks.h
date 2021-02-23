#pragma once

#include <cstdint>
#include <vector>

namespace gc {
    class ScopedChunks {
    public:
        ScopedChunks() = default;
        ScopedChunks(const ScopedChunks&) = delete;
        ScopedChunks(ScopedChunks&&) = delete;
        ScopedChunks& operator=(const ScopedChunks&) = delete;
        ScopedChunks& operator=(ScopedChunks&&) = delete;
        ~ScopedChunks();

        template <typename T, typename ...Args> 
        [[nodiscard]]
        T* new_item(Args&&...);

        [[nodiscard]]
        void* allocate_bytes(std::size_t);

        std::size_t count_allocations() const;

        void free(void**);

    private:
        std::vector<void*> allocations;
    };

    using scoped_chunks_t = ScopedChunks;
}
