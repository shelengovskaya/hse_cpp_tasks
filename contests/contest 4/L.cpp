template <typename InIter, typename OutIter, typename Predicate, typename Action>
OutIter transform_if(InIter first, InIter last, OutIter out, Predicate condition, Action f) {
    while (first != last) {
        if (condition(*first)) {
            *out++ = f(*first);
        }
        first++;
    }
    return out;
}
