public class SegmentTree {

    static int[] tree;

    // Build Segment Tree
    static void build(int node, int start, int end, int[] arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = start + (end - start) / 2;

        build(2 * node + 1, start, mid, arr);      // Left child
        build(2 * node + 2, mid + 1, end, arr);    // Right child

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

                                                             // Traverse (Print) Segment Tree
    static void traverse(int node, int start, int end) {
        if (start == end) {
            System.out.println("Node: " + node +
                               " Range: [" + start + "," + end + "]" +
                               " Value: " + tree[node]);
            return;
        }

        int mid = start + (end - start) / 2;

        System.out.println("Node: " + node +
                           " Range: [" + start + "," + end + "]" +
                           " Value: " + tree[node]);

        traverse(2 * node + 1, start, mid);
        traverse(2 * node + 2, mid + 1, end);
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 7, 9, 11};
        int n = arr.length;

        tree = new int[4 * n];

        build(0, 0, n - 1, arr);

        System.out.println("Segment Tree Traversal:");
        traverse(0, 0, n - 1);
    }
}