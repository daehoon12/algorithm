# Greedy Alrorithm : 최적화 문제를 해결하는 알고리즘
(최적화 문제란? 최적(Optimal)값을 구하는 문제로 하나의 문제에 여러 해가 있을 수 있다.)

검증 없이 바로 구현 ----> Greedy Alrorithm

- 구현
여러 경우 중 하나 선택 시, 그 순간 최적이라고 생각되는 것을 선택해 나가는 방식으로
최종적인 해답에 도달

(※ 단 한번 선택된 것은 번복하지 않는다)

-> Greedy Alrorithm 은 단순하며 제한적인 문제들에 적용된다
 선택이 그 순간에는 최적이나, 선택을 계속 수집해 해답을 만들었으므로 그것이
최적(Optimal)하다는 보장은 없다.

# Graph에서의 Greedy Algorithm
 1. 최소 신장 트리 (Minimum Spanning Tree)
    -> Spanning Tree를 구성하는 edge의 cost의 합이 최소인 Spanning Tree
    -> Prim Algorithm과 Kruskal Algorithm으로 MST를 찾을 수 있다.

 2. Prim Algorithm
   -> 한 node에 연결된 edge 중 최소 cost인 edge를 선택하면서 MST를 구현하는 방식 (Node 선택 방식)
     ※ 시간 복잡도 
       Heap 이용 시 : O(ElogV)
       배열 이용 시 : O(V^2)
 3. Kruskal Algorithm
    -> 최소 cost인 edge를 하나식 선택하면서 MST를 구현하는 방식,
    -> edge의 cost를 오름차순 방식으로 정렬하고 Union-Find 알고리즘을 통해 구현한다.

     ※ 시간 복잡도 
       1) Union - Find 알고리즘 미사용 :  O(ElogE) + O(V^2)
             -> Quick Sort를 이용해 edge를 Cost의 오름차순으로 정리 : O(ElogE)
             -> edge를 더하는 것과 cycle을 체크하는 것 :  O(V^2)
             -> 그래프가 완전 그래프일 시 : O(ElogE) > O(V^2)
             -> 그래프가 sparse 일 시 : O(ElogE) < O(n^V)

       2) Union -Find 알고리즘 사용 : edge를 더하고 cycle을 체크하는 것이 O(logn)으로 바뀌면서
          퀵 소트의 시간 복잡도를 따르게 됨. 즉, O(mlogm)
          
 ※ Prim과 Kruskal 둘 다 Cycle이 생기면 안된다.      
