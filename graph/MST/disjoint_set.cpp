class DisjointSet {
    vector<int> rank,parent,size1;
public:
    DisjointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size1.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size1[i]=1;
        }
    }
  //to find the ultimate parent 
    int findpar(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=findpar(parent[node]);
    }
  //to find the if nodes are belong to same component 
    bool find(int u, int v) {
        return findpar(u)==findpar(v);
    }
  // to get a connection y rank
    void unionByRank(int u, int v) {
        int upu=findpar(u);
        int upv=findpar(v);
        if(upu==upv){
            return;
        }
        if(rank[upu]<rank[upv])
        {
            parent[upu]=upv;
        }
        else if(rank[upv]<rank[upu])
        {
            parent[upv]=upu;
        }
        else{
            parent[upv]=upu;
            rank[upu]++;
        }
    }
  // to get a connection by size
    void unionBySize(int u, int v) {
        int upu=findpar(u);
        int upv=findpar(v);
        if(upu==upv){
            return;
        }
        if(size1[upu]<size1[upv])
        {
            parent[upu]=upv;
            size1[upv]+=size1[upu];
        }
        else
        {
            parent[upv]=upu;
            size1[upu]+=size1[upv];
        }
    }
};


overview:

Great questions — these are exactly what interviewers probe after the basic DSU implementation. Let's go one by one.

Q1.) Why does path compression not require updating the rank values?

Rank does **not** mean exact current height after all operations. It means an **upper bound** on height.

Initial rule:
- Every node starts with `rank = 0`
- When you merge roots `ru` and `rv`:
  - if `rank[ru] < rank[rv]`: `parent[ru] = rv`
  - if `rank[ru] > rank[rv]`: `parent[rv] = ru`
  - if equal: attach one under other and `rank[newRoot]++`

This guarantees tree height <= `rank[root]`.

Path compression does this in `find(x)`:

```
if parent[x] != x:
  parent[x] = find(parent[x])
```

It makes the tree flatter, so true height becomes *smaller* than rank. That's fine because:

1. We only ever compare ranks to decide which tree goes under which. An overestimate is still safe — it never breaks correctness.
2. Fixing ranks exactly would be expensive. After compressing node `x` to root, you'd have to update ranks of all nodes on the path, and the rank of the root might actually need to *decrease*. That would cost O(n) and destroy the benefit.
3. The proof of `O(alpha(n))` — inverse Ackermann, almost constant — already assumes rank is an upper bound, not exact height.

Think of rank as "merge history", not "live height".

Q2.) What is the difference between union by rank and union by size?

Both solve the same problem: avoid making a tall chain by attaching the smaller tree under the larger one. They just define "smaller" differently.

**Union by Rank:**
- Maintains `rank[]`, roughly height estimate.
- Attach lower-rank root under higher-rank root.
- If ranks equal, pick one as new root and increment its rank by 1.

**Union by Size:**
- Maintains `size[]`, number of nodes in component. Initially `size[i] = 1`.
- Attach smaller-size root under larger-size root.
- Update: `size[newRoot] += size[smallRoot]`.

Differences in practice:

- `size[root]` gives you useful information — actual component size. `rank[root]` after path compression is not meaningful except for union decisions.
- Rank needs only small values (max ~ log n), size can go up to n.
- Both + path compression give the same amortized complexity: `O(alpha(n))`.
- You only need one of them in a problem. Many people prefer union by size because it's more intuitive and directly answers "how big is my component?"

Your problem asks you to implement both, but in real code you would use either one.

Q3.) What happens to the complexity if path compression is removed?

Without path compression you still have union by rank / size, so trees stay balanced.

- **With both:** `find` and `union` are `O(alpha(n))` amortized — effectively O(1).
- **With only union by rank/size:** tree height is bounded by `O(log n)`. So every `find` walks at most log n parents. Total for m operations: `O(m log n)`.
- **With neither:** worst case is a chain `0 -> 1 -> 2 -> ... -> n-1`, and `find` becomes `O(n)`.

So removing path compression degrades from almost-constant to logarithmic. For `n = 1e4` that's still okay, but for `1e6` nodes and many queries the difference is huge. Path compression is what makes repeated `find(0,1)` after the first union O(1).

Q4.) How would you track the number of connected components?

Add a variable `components`:

```
DisjointSet(n):
  parent[i] = i
  components = n
```

In `union(u,v)`:

```
ru = findUltimateParent(u)
rv = findUltimateParent(v)
if ru == rv: return // already connected, do nothing
// merge them by rank/size
components -= 1
```

Key points:
- Initialize to `n` because every node is its own component.
- Decrement **only** when two different roots merge.
- `find` never changes the count.
- `components == 1` means whole graph is connected.

This is used in problems like Number of Provinces, Number of Islands II, Kruskal's early stop.

Q5.) Can this DSU be extended to support component sizes or detecting redundant edges?

Yes, both are standard extensions.

**a) Component sizes:**
You already have it if you implemented union by size. `size[find(x)]` is the size of x's component. You can add a method:

```
getSize(x): return size[find(x)]
```

This answers "how many nodes connected to x?" in almost O(1).

**b) Detecting redundant edges / cycles:**
This is the core of Kruskal's MST and Redundant Connection problems.

When processing edge `(u,v)`:

```
if find(u) == find(v):
  // redundant edge — u and v already connected, this edge forms a cycle
else:
  union(u,v)
```

Example: `n=3`, edges `[0-1], [1-2], [0-2]`. First two unions succeed. Third edge finds `0` and `2` already have same root, so `[0-2]` is redundant.

Same idea detects cycles in an undirected graph without DFS.

If you want to practice next, try thinking how you would use `components` + redundant edge check to implement Kruskal's algorithm — that connects all 5 concepts together.

