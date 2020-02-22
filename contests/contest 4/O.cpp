template <typename It, typename OutputIt>
OutputIt sideways_merge(It first1, It last1, It first2, It last2, OutputIt out) {
    first2--;
    last2--;
    while (first1 != last1 && first2 != last2) {
        if (*first1 < *last2) {
            *out++ = *first1++;
        } else {
            *out++ = *last2--;
        }
    }
    while (first1 != last1) {
        *out++ = *first1++;
    }
    while (first2 != last2) {
        *out++ = *last2--;
    }
    return out;
}
