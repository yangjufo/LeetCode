class Solution {
    public boolean backspaceCompare(String S, String T) {
        int sInd = S.length(), tInd = T.length();       
        do {
            sInd = cleanSuffix(S, sInd - 1);
            tInd = cleanSuffix(T, tInd - 1);            
            if (sInd < 0 && tInd < 0)
                return true;
            if (sInd < 0 || tInd < 0 || S.charAt(sInd) != T.charAt(tInd))
                return false;                    
        } while (sInd > -1 && tInd > -1);        
        return sInd == tInd;
    }
    
    private int cleanSuffix(String str, int end) { 
        int count = 0;
        while (end > -1 && (str.charAt(end) == '#' || count > 0)) {
            if (str.charAt(end) == '#')
                count += 1;
            else
                count -= 1;
            end -= 1;
        }
        return end;
    }
}