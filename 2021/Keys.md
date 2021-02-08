1. Sorted array -> binary search
2. String with limited characters -> hashMaps, e.g., one day has up to 1440 minutes
3. Word ladder -> bfs is faster than dfs, because it can cut off earlier
4. Binary search -> use Segment tree or binary index tree
5. find prefix + suffix -> find mid instead, like max subarray
6. Do not use array.size() - k < target => unsigned int vs singed int; (int)nums.size() - 2 to avoid overflow
7. Reverse thinking -> rule out those do not fit if you need to find all that fit -> 130. Surrounded Regions
8. Whether a graph is a tree -> number of edges = number of nodes - 1