#include <iostream>
#include <vector>
#include <cassert>

class FixedPoolAllocator {
    size_t blockSize;
    size_t totalBlocks;
    std::vector<char> pool;
    std::vector<void*> freeList;

public:
    FixedPoolAllocator(size_t bSize, size_t count) : blockSize(bSize), totalBlocks(count), pool(bSize * count) {
        for (size_t i = 0; i < count; ++i) {
            freeList.push_back(pool.data() + (i * bSize));
        }
    }

    void* allocate() {
        if (freeList.empty()) return nullptr;
        void* ptr = freeList.back();
        freeList.pop_back();
        return ptr;
    }

    void deallocate(void* ptr) {
        freeList.push_back(ptr);
    }

    size_t available() const { return freeList.size(); }
};

int main() {
    FixedPoolAllocator alloc(64, 10);
    assert(alloc.available() == 10);
    void* p = alloc.allocate();
    assert(p != nullptr);
    assert(alloc.available() == 9);
    alloc.deallocate(p);
    assert(alloc.available() == 10);
    std::cout << "Pool allocator verified." << std::endl;
    return 0;
}

// Updated: 2019-04-02 - feat(memory): fixed-block memory pool allocator in C++
