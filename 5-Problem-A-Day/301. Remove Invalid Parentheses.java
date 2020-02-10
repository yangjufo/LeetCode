class Solution {
    private Set<String> validExpressions = new HashSet<String>();
    private int minimumRemoved;

    private void reset() {
        this.validExpressions.clear();
        this.minimumRemoved = Integer.MAX_VALUE;
    }

    private void recurse(String s, int index, int leftCount, int rightCount,
            StringBuilder expression, int removedCount) {
        if (index == s.length()) {
            if (leftCount == rightCount) {
                if (removedCount <= this.minimumRemoved) {
                    String possibleAnswer = expression.toString();
                    if (removedCount < this.minimumRemoved) {
                        this.validExpressions.clear();
                        this.minimumRemoved = removedCount;
                    }
                    this.validExpressions.add(possibleAnswer);
                }
            }
        } else {
            char currentCharacter = s.charAt(index);
            int length = expression.length();
            if (currentCharacter != '(' && currentCharacter != ')') {
                expression.append(currentCharacter);
                this.recurse(s, index + 1, leftCount, rightCount, expression, removedCount);
                expression.deleteCharAt(length);
            } else {
                this.recurse(s, index + 1, leftCount, rightCount, expression, removedCount + 1);
                expression.append(currentCharacter);

                if (currentCharacter == '(') {
                    this.recurse(s, index + 1, leftCount + 1, rightCount, expression, removedCount);
                } else if (leftCount > rightCount) {
                    this.recurse(s, index + 1, leftCount, rightCount + 1, expression, removedCount);
                }
                expression.deleteCharAt(length);
            }
        }
    }

    public List<String> removeInvalidParentheses(String s) {
        this.reset();
        this.recurse(s, 0, 0, 0, new StringBuilder(), 0);
        return new ArrayList(this.validExpressions);
    }
}
