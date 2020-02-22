#include <vector>
#include <algorithm>


void delete_zeroes(std::vector<int>& numbers) {
    std::vector<int> num(numbers.size());
    remove_copy(numbers.begin(), numbers.end(), num.begin(), 0);
    numbers = num;
    int k = count_if(numbers.begin(), numbers.end(), [](int i) {return i != 0;});
    numbers.resize(k);
}
