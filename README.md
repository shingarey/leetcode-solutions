# Leetcode-solutions
solutions to the leetcode programming problems. With theory notes.

## Hash table

[1. Two Sum](https://leetcode.com/problems/two-sum/) (easy) - [solution](solutions/1_two_sum/)

[3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) (medium) - [solution](solutions/3_longest_substring/)

## Linked lists

[2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) (medium) - [solution](solutions/2_add_two_numbers/)

## Trees

A tree is actually a type of graph, but not all graphs are trees. Simply put, a tree is a connected graph without cycles.

### Binary tree vs. binary search tree

A binary tree is a tree in which each node has up to two children. A node is called a "leaf" node if it has no children. A binary search tree is a binary tree in which every node fits a specific ordering property: all left descendents <= n < all right descendents. This must be true for each node n.

### tree traversal

* Breadth-First Traversal
* Depth-First Traversal
* Threaded Trees - Stackless Depth-First Traversal

#### Breadth-First Traversal

Implementation of this kind of traversal is straightforward when a queue is used. Consider a top-down, left-to-right, breadth-first traversal. After a node is visited, its children, if any, are placed at the end of the queue, and the node at the beginning of the queue is visited. Considering that for a node on level n, its children are on level n + 1, by placing these children at the end of the queue, they are visited after all nodes from level n are visited. Thus, the restriction that all nodes on level n must be visited before visiting any nodes on level n + 1 is met.

#### Depth-First Traversal

There are three tasks of interest in this type of traversal:

V—visiting a node
L—traversing the left subtree
R—traversing the right subtree

The three tasks can themselves be ordered in 3! = 6 ways, so there are six possible ordered depth-first traversals:
VLR VRL
LVR RVL
LRV RLV

it can be reduced to three traversals where the move is always from left to right and attention is focused on the first column. The three traversals are given these standard names:
VLR—preorder tree traversal
LVR—inorder tree traversal
LRV—postorder tree traversal

Short and elegant functions can be implemented directly from the symbolic descriptions of these three traversal. These functions may seem too simplistic, but their real power lies in recursion, in fact, double recursion. The real job is done by the system on the run-time stack. This simplifies coding but lays a heavy burden upon the system.

##### In-Order Traversal

In-order traversal means to "visit" (often, print) the left branch, then the current node, and finally, the right branch. When performed on a binary search tree, it visits the nodes in ascending order (hence the name "in-order").

```cpp
inOrderTraversal(node.left);
visit(node);
inOrderTraversal(node.right);
```

##### Pre-Order Traversal

Pre-order traversal visits the current node before its child nodes (hence the name "pre-order"). In a pre-order traversal, the root is always the first node visited.

```cpp
visit(node);
preOrderTraversal(node.left);
preOrderTraversal(node.right);
```

##### Post-Order Traversal

Post-order traversal visits the current node after its child nodes (hence the name "post-order"). In a post-order traversal, the root is always the last node visited.

```cpp
postOrderTraversal(node.left);
postOrderTraversal(node.right);
visit(node);
```

### Binary Heaps (Min-Heaps)

A min-heap is a complete binary tree (that is, totally filled other than the rightmost elements on the last level) where each node is smaller than its children. The root, therefore, is the minimum element in the tree. We have two key operations on a min-heap: ```insert``` and ```extract_min```.

#### Insert

When we insert into a min-heap, we always start by inserting the element at the bottom. We insert at the rightmost spot so as to maintain the complete tree property. Then, we "fix"the tree by swapping the new element with its parent, until we find an appropriate spot for
the element. We essentially bubble up the minimum element.

This takes O( log n) time, where n is the number of nodes in the heap.

#### Extract Minimum Element

Finding the minimum element of a min-heap is easy: it's always at the top. To remove the element, we first remove the minimum element and swap it with the last element on the heap (the bottemmost, rightmost element). Then, we bubble down this element, swapping it with one of the children until the min-heap property is restored. There's no inherent ordering between the left and right element, but you'll need to take the smaller one in order to maintain the min-heap ordering.

This algorithm will take 0( log n) time.

### Programming assignments

[104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) (easy)  - [solution](solutions/104_maximum-depth-of-binary-tree)

[226. Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) (easy)  - [solution](solutions/226_invert_binary_tree)

## Graphs

A graph is simply a collection of nodes with edges between (some of) them.

Graphs can be either directed or undirected. While directed edges are like a one-way street, undirected edges are like a two-way street.

* The graph might consist of multiple isolated subgraphs. If there is a path between every pair of vertices, it is called a "connected graph:'
* The graph can also have cycles (or not). An "acyclic graph" is one without cycles.

In terms of programming, there are two common ways to represent a graph.

### Adjacency List

This is the most common way to represent a graph. Every vertex (or node) stores a list of adjacent vertices. In an undirected graph, an edge like (a, b) would be stored twice: once in a's adjacent vertices and once in b's adjacent vertices.

A simple class definition for a graph node could look essentially the same as a tree node.

```cpp
class Graph {
    public Node[] nodes;
}

class Node {
    public string Name;
    public Node[] children;
}
```

You don't necessarily need any additional classes to represent a graph. An array (or a hash table) of lists (arrays, arraylists, linked lists, etc.) can store the adjacency list. This is a bit more compact, but it isn't quite as clean. We tend to use node classes unless there's a compelling reason not to.

### Adjacency Matrices

An adjacency matrix is an NxN boolean matrix (where N is the number of nodes), where a true value at matrix[ i] [j] indicates an edge from node i to node j. In an undirected graph, an adjacency matrix will be symmetric. In a directed graph, it will not (necessarily) be.

The same graph algorithms that are used on adjacency lists (breadth-first search, etc.) can be performed with adjacency matrices, but they may be somewhat less efficient. In the adjacency list representation, you can easily iterate through the neighbors of a node. In the adjacency matrix representation, you will need to iterate through all the nodes to identify a node's neighbors

### Graph Search

The two most common ways to search a graph are depth-first search and breadth-first search.

In depth-first search (DFS), we start at the root (or another arbitrarily selected node) and explore each branch completely before moving on to the next branch. That is, we go deep first (hence the name depth first search) before we go wide.

In breadth-first search (BFS), we start at the root (or another arbitrarily selected node) and explore each neighbor before going on to any of their children. That is, we go wide (hence breadth-first search) before we go deep.

Breadth-first search and depth-first search tend to be used in different scenarios. DFS is often preferred if we want to visit every node in the graph. Both will work just fine, but depth-first search is a bit simpler.

#### Depth-First Search (DFS)

Note that pre-order and other forms of tree traversal are a form of DFS. The key difference is that when implementing this algorithm for a graph, we must check if the node has been visited. If we don't, we risk getting stuck in an infinite loop.

```cpp
void search(Node root) {
    if (root== null) return;
    visit(root);
    root.visited= true;
    for each (Node n in root.adjacent) {
        if (n.visited == false) {
            search(n); 
        }
    }
 }
 ```

#### Breadth-First Search (BFS)

The main tripping point is the (false) assumption that BFS is recursive. It's not. Instead, it uses a queue.

In BFS, node a visits each of a's neighbors before visiting any of their neighbors. You can think of this as searching level by level out from a. An iterative solution involving a queue usually works best.

```cpp
void search(Node root) {
    Queue queue = new Queue();
    root.marked= true;
    queue.enqueue(root); // Add to the end of queue
    while (!queue.isEmpty()) {
        Node r= queue.dequeue(); // Remove from the front of the queue
        visit(r);
        foreach (Node n in r.adjacent) {
            if (n.marked== false) {
                n.marked= true;
                queue.enqueue(n);
            }
        }
    }
}
 ```

#### Bidirectional Search

Bidirectional search is used to find the shortest path between a source and destination node. It operates by essentially running two simultaneous breadth-first searches, one from each node. When their searches collide, we have found a path.
