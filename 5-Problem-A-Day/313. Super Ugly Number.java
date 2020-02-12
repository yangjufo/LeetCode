class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        int[] ugly = new int[n];
        int[] idx = new int[primes.length];
        int[] val = new int[primes.length];
        Arrays.fill(val, 1);

        int next = 1;
        for (int i = 0; i < n; i++) {
            ugly[i] = next;

            next = Integer.MAX_VALUE;
            for (int j = 0; j < primes.length; j++) {
                if (val[j] == ugly[i]) {
                    val[j] = ugly[idx[j]] * primes[j];
                    idx[j] += 1;
                }
                next = Math.min(val[j], next);
            }
        }

        return ugly[n - 1];
    }
}
