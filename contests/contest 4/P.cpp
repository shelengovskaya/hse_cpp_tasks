#include <algorithm>
#include <vector>


template <typename T>
void process(const std::vector<T>& data) {
    int k = count_if(data.begin(), data.end(), [](const T& x){return x > 0;});
    std::vector<T> filtered(k);
    auto filtered_last = std::copy_if(
            data.begin(),
            data.end(),
            filtered.begin(),
            [](const T& x){return x > 0;});
    print_results(filtered.begin(), filtered_last);
}
