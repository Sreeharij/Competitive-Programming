vector<int> Solution::prevSmaller(vector<int> &A) {
    int length = A.size();
    vector<int> answer(length,-1);
    stack<int> stk;
    for(int i=0;i<length;i++){
        while(!stk.empty() && stk.top() >= A[i]){
            stk.pop();
        }
        if(!stk.empty()){
            answer[i] = stk.top();
        }
        stk.push(A[i]);
    }
    return answer;
}
