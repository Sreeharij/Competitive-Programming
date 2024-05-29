class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> answer(2,0);
        double kelvin = celsius + 273.15;
        double fahrenheit = celsius * 1.80 + 32.00;
        answer[0] = kelvin;
        answer[1] = fahrenheit;
        return answer;
    }
};