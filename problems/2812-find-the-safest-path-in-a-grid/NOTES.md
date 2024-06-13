BFS + binary search 로 풀어야 시간 제한에 걸리지 않음

우선 grid의 각 cell에 thief로부터의 거리를 저장해둔다.
-> thief의 위치를 구하고 각 cell에서 해당 thief로부터의 거리를 모두 구한 뒤 그 최소값을 구해 저장하는 방법은 시간이 너무 오래 걸림
따라서 BFS를 사용하여 grid에 거리를 저장해둔다.

거리 저장하는 BFS 전략
-> 각 thief에서부터 인접한 cell들의 거리를 갱신해주는 방식.
thief 상하좌우 인접 cell은 거리 1, 해당 cell들에 인접한 cell은 해당 cell의 값 + 1, ...(반복)

가능한 최대 safeness를 구하는 전략
-> 시작점보다 큰 safeness는 불가능. 따라서 시작점 ~ 0 까지 수에 대해 해당 수를 safeness로 갖는 경로가 존재하는지 확인. 존재한다면 해당 수가 정답.
-> 이때 시작점에서 0까지 하나씩 순서대로 확인하는 naive한 전략은 시간 초과에 걸림. 이때 binary search를 사용해야함.

참고
https://www.youtube.com/watch?v=ZqEX8Eab3ZA​
