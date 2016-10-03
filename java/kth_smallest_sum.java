/*
// Given two integer arrays sorted in ascending order and an integer k.
// Define sum = a + b, where a is an element from the first array and b
// is an element from the second one.
// Find the kth smallest sum out of all possible sums.
// Example:
// Given[1,7,11] and [2,4,6].
// For k = 3, return 7.
// For k = 4, return 9.
// For k = 8, return 15.
// Challenge:
// Do it in either of the following time complexity:
// 1. O(k log min(n,m,k)). Where n is the size of a, and m is the size of b.
// 2. O((m+n)log maxValue). Where maxValue is the max number in A and B.
*/

// Heap Priority Queue Sorted Matrix


public class Solution{
    //Point class includes x, y and val = a[x] + b[y]
    public class Point{
        int x, y, val;
        public Point(int x, int y, int val){
            this.x = x;
            this.y = y;
            this.val = val;
        }

    }

    public int kthSmallestSum(int[] A, int [] B, int k){
        if(A == null || B == null || A.length == 0 || B.length == 0 || k < 0){
            return -1;
        }
        PriorityQueue<Point> q = new PriorityQueue<Point>(2, new Comparator<Point>(){
            public int compare(Point p1, Point p2){
                return p1.val - p2.val;
            }
        });
        HashSet<String> set = new HashSet<String>();
        Point min = new Point(0,0, A[0] + B[0]);
        q.offer(min);
        set.add(min.x + "," + min.y);

        int n = A.length;
        int m = B.length;

        for(int i = 0; i < k - 1; ++i){
            min = q.poll();
            if(min.x + 1 < n){
                Point newP = new Point(min.x+1, min.y, A[min.x+1]+B[min.y]);
                if(!set.contains(newP.x + "," + newP.y)){
                    set.add(newP.x + "," + newP.y);
                    queue.offer(newP);
                }
            }
            if(min.y + 1 < m){
                Point newP = new Point(min.x, min.y, A[min.x] + B[min.y+1]);
                if(!set.contains(newP.x + "," + newP.y)){
                    set.add(newP.x + "," + newP.y);
                    queue.offer(newP);
                }
            }
        }
        min = queue.poll();
        return min.val;
    }

}
