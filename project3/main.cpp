#include "Vector.h"
#include <iostream>
#include <cassert>

int main() {
    // 基本功能测试
    Vector<int> vec1;
    assert(vec1.empty());
    assert(vec1.size() == 0);

    Vector<int> vec2(5);
    assert(!vec2.empty());
    assert(vec2.size() == 5);

    Vector<int> vec3(3, 10);
    assert(vec3.size() == 3);
    assert(vec3[0] == 10);
    assert(vec3[1] == 10);
    assert(vec3[2] == 10);

    Vector<int> vec4 = {1, 2, 3};
    assert(vec4.size() == 3);
    assert(vec4[0] == 1);
    assert(vec4[1] == 2);
    assert(vec4[2] == 3);

    Vector<int> vec5 = vec4;
    assert(vec4 == vec5);

    Vector<int> vec6(std::move(vec4));
    assert(vec4.empty());  // vec4应为空
    assert(vec6.size() == 3);  // vec6应保留内容

    vec4 = vec5;
    assert(vec4 == vec5);

    vec4 = std::move(vec6);
    assert(vec6.empty());  // vec6应为空
    assert(vec4.size() == 3);  // vec4应保留内容

    vec4[0] = 42;
    assert(vec4[0] == 42);

    assert(vec4.at(0) == 42);
    assert(vec4.front() == 42);
    assert(vec4.back() == 3);

    int* data_ptr = vec4.data();
    assert(data_ptr != nullptr);

    assert(!vec4.empty());

    assert(vec4.size() == 3);

    vec4.reserve(10);
    assert(vec4.size() == 3);  // 大小不变
    assert(vec4.capacity() >= 10);  // 容量增加

    vec3.clear();
    assert(vec3.empty());

    vec4.insert(1, 8);
    assert(vec4[1] == 8);
    assert(vec4.size() == 4);

    vec4.erase(2);
    assert(vec4.size() == 3);
    assert(vec4[2] == 3);

    vec4.resize(5);
    assert(vec4.size() == 5);
    assert(vec4[3] == 0);  // 默认构造的新元素

    Vector<int> vec7 = {7, 8, 9};
    vec4.swap(vec7);
    assert(vec4 != vec7);

    // 可靠性测试
    try {
        int x = vec4.at(10);  // 试图访问越界元素
    } catch (const std::out_of_range& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    // 其他测试
    Vector<int> vec8 = {1, 2, 3};
    Vector<int> vec9 = {1, 2, 4};
    assert(vec8 < vec9);
    assert(vec8 <= vec9);
    assert(vec8 != vec9);
    assert(vec9 > vec8);
    assert(vec9 >= vec8);

    Vector<int> vec10 = {1, 2, 3};
    Vector<int> vec11 = {2, 3, 4};
    Vector<int> sum = vec10 + vec11;
    Vector<int> diff = vec11 - vec10;
    Vector<int> product = vec10 * 2;
    int dot_product = vec10 * vec11;
    assert(sum == Vector<int>({3, 5, 7}));
    assert(diff == Vector<int>({1, 1, 1}));
    assert(product == Vector<int>({2, 4, 6}));
    assert(dot_product == 20);

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
