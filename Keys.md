1. Sorted array -> binary search
2. String with limited characters -> hashMaps, e.g., one day has up to 1440 minutes
3. Word ladder -> bfs is faster than dfs, because it can cut off earlier
4. Binary search -> use Segment tree or binary index tree
5. find prefix + suffix -> find mid instead, like max subarray
6. Do not use array.size() - k < target => unsigned int vs singed int; (int)nums.size() - 2 to avoid overflow
7. Reverse thinking -> rule out those do not fit if you need to find all that fit -> 130. Surrounded Regions
8. Whether a graph is a tree -> number of edges = number of nodes - 1
9. BFS -> mark visited when adding neighbors. Otherwise, a cell can be pushed to the queue multiple times
10. (i & 0x1) == 1
11. Use `pair` or `array<int, 2>` whenever possible, it has better performance than `vector`
12. Consider count the number of different characters for string problems, e.g., https://leetcode.com/problems/number-of-matching-subsequences/
13. When reordering, consider count of digits, e.g., https://leetcode.com/problems/reordered-power-of-2/
14. Group things, consider sliding window, e.g., https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/
15. Check `iter != a.begin()` before using `prev(iter)`; Check `iter != a.end()` before `*iter`
16. If the number range is small, consider counting the number, e.g., https://leetcode.com/problems/minimum-absolute-difference-queries/
17. When dp, try to use a single `pre` instead of traversing all the elements before, e.g., https://leetcode.com/problems/maximum-number-of-points-with-cost/
18. Be careful about duplicates for arrays, e.g., https://leetcode.com/problems/heaters/
19. Record used numbers in each recursion instead of checking the final result, e.g., https://leetcode.com/problems/increasing-subsequences/
20. Use square to limit the search range, e.g., https://leetcode.com/problems/construct-the-rectangle/submissions/
21. When using `long`, make sure it's everywhere, e.g., https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/
22. Try linked list instead of `std::map` for sorting, e.g., https://leetcode.com/problems/all-oone-data-structure/
23. Use `(str + str).find(str, 1) != string::npos` to Check repeated substring, e.g., https://leetcode.com/problems/encode-string-with-shortest-length/
24. Set `right = nums.size()` to avoid final `left` checking when binary search, e.g., https://leetcode.com/problems/search-insert-position/
25. Try thinking reversely like `maxSum = total - minSum`, e.g., https://leetcode.com/problems/maximum-sum-circular-subarray/
26. Be careful about the corner case that the new value is the same as the old value, e.g., https://leetcode.com/problems/flood-fill/
27. Use negative value to mark cells in a board, e.g., https://leetcode.com/problems/candy-crush/
28. Use `vector` instead of `unordered_set` whenever possible for faster runtime, e.g., https://leetcode.com/problems/minimum-operations-to-convert-number/