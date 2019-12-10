public class ZigzagIterator {

    int idx1, idx2;
    List<Integer> v1, v2;
    boolean one;

    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        this.v1 = v1;
        this.v2 = v2;
        idx1 = idx2 = 0;
        one = true;
    }

    public int next() {
        int ans = 0;
        if (idx2 >= v2.size() || (idx1 < v1.size() && one)) {
            ans = v1.get(idx1);
            idx1++;
        } else if (idx1 >= v1.size() || (idx2 < v2.size() && !one)) {
            ans = v2.get(idx2);
            idx2++;
        }
        one = !one;
        return ans;
    }

    public boolean hasNext() {
        return idx1 < v1.size() || idx2 < v2.size();
    }
}

/**
 * Your ZigzagIterator object will be instantiated and called as such: ZigzagIterator i = new
 * ZigzagIterator(v1, v2); while (i.hasNext()) v[f()] = i.next();
 */
