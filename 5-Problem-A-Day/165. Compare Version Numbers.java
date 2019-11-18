class Solution {
    public int compareVersion(String version1, String version2) {
        int i = 0, j = 0, v1 = 0, v2 = 0;
        while (i < version1.length() && j < version2.length()) {
            char c1 = version1.charAt(i), c2 = version2.charAt(j);
            if (c1 == '.' && c2 == '.') {
                if (v1 > v2)
                    return 1;
                else if (v1 < v2)
                    return -1;
                v1 = v2 = 0;
                i++;
                j++;
            }
            if (c1 != '.') {
                v1 = v1 * 10 + Character.getNumericValue(c1);
                i++;
            }
            if (c2 != '.') {
                v2 = v2 * 10 + Character.getNumericValue(c2);
                j++;
            }
        }
        while (i < version1.length()) {
            char c1 = version1.charAt(i);
            if (c1 == '.') {
                if (v1 > v2)
                    return 1;
                if (v1 < v2)
                    return -1;
                v1 = v2 = 0;
            } else
                v1 = v1 * 10 + Character.getNumericValue(c1);
            i++;
        }
        while (j < version2.length()) {
            char c2 = version2.charAt(j);
            if (c2 == '.') {
                if (v1 > v2)
                    return 1;
                if (v1 < v2)
                    return -1;
                v1 = v2 = 0;
            } else
                v2 = v2 * 10 + Character.getNumericValue(c2);
            j++;
        }
        if (v1 > v2)
            return 1;
        if (v1 < v2)
            return -1;
        return 0;
    }
}
