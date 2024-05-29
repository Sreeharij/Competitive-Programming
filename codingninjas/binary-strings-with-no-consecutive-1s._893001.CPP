void get_string(vector<string>& answer,string& temp_string,bool last_entered,int n){
    if(n == 0){
        answer.push_back(temp_string);
        return;
    }
    temp_string.push_back('0');
    get_string(answer,temp_string,false,n-1);
    temp_string.pop_back();
    if(!last_entered){
        temp_string.push_back('1');
        get_string(answer,temp_string,true,n-1);
        temp_string.pop_back();
    }
}

vector<string> generateString(int N){
    vector<string> answer;
    string temp_string = "";
    get_string(answer,temp_string,false,N);
    return answer;
}