template <typename InIter, typename OutIter>
OutIter reverse_copy(InIter first, InIter last, OutIter out) {
    while (first != last) {
        *(out++) = *(--last);
    }
    return out;
}
