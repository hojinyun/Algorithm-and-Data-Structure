#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> q1, q2;
    long long q1_sum=0, q2_sum=0;
    int answer = 0, idx1=0, idx2=0, max_idx=queue1.size()+queue2.size();
    //큐 합 계산 및 큐 형태로 자료 저장
    for(int i = 0; i < queue1.size(); i++){
        q1_sum+=queue1[i];
        q1.push(queue1[i]);
    }
    for(int i = 0; i < queue2.size(); i++){
        q2_sum+=queue2[i];
        q2.push(queue2[i]);
    }
    //두 큐에 있는 모든 원소 개수를 넘었을 경우 불가능으로 탈출
    while(idx1<max_idx&&idx2<max_idx){
        //합이 같은 경우
        if(q1_sum==q2_sum) return answer;
        answer++;
        //첫번째 큐가 작은 경우 첫번째 큐에 두번째 큐 값을 더함
        if(q1_sum < q2_sum){
            q1_sum+=q2.front();
            q2_sum-=q2.front();
            q1.push(q2.front());
            q2.pop();
            idx2++;
        }
        //두번째 큐가 작은 경우 두번째 큐에 첫번째 큐 값을 더함
        else{
            q2_sum+=q1.front();
            q1_sum-=q1.front();
            q2.push(q1.front());
            q1.pop();
            idx1++;
        }
    }
    return -1;
    
}