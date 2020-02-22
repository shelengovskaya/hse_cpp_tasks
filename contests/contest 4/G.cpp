template <typename It, typename Pred>
bool any_of(It first, It last, Pred f) {
    for (It it = first; it != last; it++) {
        if (f(*it)) {
            return true;
        }
    }
    return false;
}
