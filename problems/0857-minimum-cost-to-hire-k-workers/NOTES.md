문제에 제시된 아래 문장의 의미 파악이 중요  
_In the group, each worker's pay must be directly proportional to their quality. This means if a worker’s quality is double that of another worker in the group, then they must be paid twice as much as the other worker._  
> 그룹에 포함된 노동자들은 각자 자기의 quality에 대해 모두 같은 비율의 wage를 받음.  
> w[i]/w[j] == q[i]/q[j]

w[i]/w[j] == q[i]/q[j]에서  
w[i]/q[i] == w[j]/q[j]로 유도 가능.  
(w/q의 식으로 유도한 까닭은 위 식을 만족하도록 하기 위해 q가 아닌 w를 조정해야 하므로 w가 분자.)  

위 식을 만족하는 각 그룹의 총 급여 합은 아래의 식으로 구할 수 있음  
그룹의 총 quality 합 * 그 그룹의 w/q 비율 = 총 급여 합  

위 식이 최소가 되려면 quality도 될 수 있는한 작아야 하고, w/q 또한 작아야 함.

### 풀이
priority_queue를 사용하여 최소값을 구한다.
w/q에 대한 pq와 quality에 대한 pq가 필요
w/q에서 우선 w/q를 작은 순서로 정렬하고, 여기서 k개 만큼 pop하여 총합을 구하는 구조.
quality에 대한 pq안에 k개 만큼 삽입하고 총합 구하고 -> quality가 가장 큰 것 하나 pop하고 다시 w/q에서 하나 보충하여 총합 구하는 것을 반복.
반복하여 도출된 값들 중 최소값이 정답.
