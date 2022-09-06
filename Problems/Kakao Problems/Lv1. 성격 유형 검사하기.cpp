#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    char MBTI[4][2]={{'R','T'}, {'C','F'}, {'J','M'}, {'A','N'}};
    map<char,int> score;
    //맵에 각 문자마다 점수 저장
    for(int i = 0; i < survey.size(); i++){
        if(choices[i]<4) score[survey[i][0]]+=4-choices[i];
        else score[survey[i][1]]+=choices[i]-4;
    }
    //맵에 저장된 값 비교 후 더 큰 값 answer 문자열에 저장
    for(int i = 0; i < 4; i++){
        if(score[MBTI[i][0]]>=score[MBTI[i][1]]) answer.push_back(MBTI[i][0]);
        else answer.push_back(MBTI[i][1]);
    }
    //정답 출력
    return answer;
}