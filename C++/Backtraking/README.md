# Backtracking : 해를 찾는 도중에 해가 아니면 되돌아가서 다시 해를 찾는 기법
    -> 최적화 (Optimizaiont) 문제와 결정 (Decision) 문제를 해결할 수 있음

(결정 문제 : 문제의 조건을 만족하는 해가 존재하는지의 여부를 'Y 또는 N로 답하는 문제)

- 상태 공간 트리 
  - 해를 찾기 위한 선택의 과정을 트리로 표현
  - 트리의 내부 노드는 최종 상태로 가는 중간 상태를 나타냄
  - 트리의 단말 노드는 하나의 후보해에 대한 최종 상태가 됨
  - 상태 공간 트리를 탐색하는 것은 모든 후보해들을 탐색 하는 것
  - 트리를 깊이 우선 탐색하는 방법이 백트래킹 알고리즘의 기본

- Backtracking vs DFS
  - 백트래킹은은 가지치기라는 작업을 통해 불필요한 경로를 조기에 차단하는 반면 dfs는 모든 경로를 추척함.
  - 즉 dfs는 수가 너무 많은 경우 처리가 불가능한 반면 백트래킹은 가지치기로 인해 경우의 수가 줄어들게 되어
    처리가 가능 (But 최악의 경우 여전히 지수 함수 시간)



- 8-Queens 문제
  - 퀸 8개를 8 XX 8 크기의 체스판 안에 서로를 공격할 수 없도록 배치하는 모든 경우를 구하는 문제
  - 44억개의 해들 중에서 92개를 최대한 효율적으로 찾아내야 함.
  - dfs 사용 시 해가 될 가능성이 전혀 없는 노드들도 검색해야 하므로 비효율
  - 어떤 노드의 유망성 점검 후 유망 (Promising)하지 않다고 결정되면 해당 노드의 부모로 되돌아가(Backtracking) 다음 자식 노드로 감
 
  ※ 유망성 (Promising) : 어떤 노드를 방문했을 때 해당 노드를 포함한 경로의 해답 여부
