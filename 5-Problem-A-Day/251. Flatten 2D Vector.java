class Vector2D {

    int i, j;
    int[][] v;
    public Vector2D(int[][] v) {
        this.v = v;
        i = 0;
        j = 0;
    }
    
    public int next() {
        hasNext();
        return v[i][j++];
    }
    
    public boolean hasNext() {
        while (i != v.length && j == v[i].length) {
            j = 0;
            i++;
        }
        return i != v.length;
    }
}

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D obj = new Vector2D(v);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */