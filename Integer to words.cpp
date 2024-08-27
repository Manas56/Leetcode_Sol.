//Input: num = 12345
//Output: "Twelve Thousand Three Hundred Forty Five"

class Solution {
public:
    map<int,string>belowTwenty={{0,"Zero"},{1,"One"},{2,"Two"},{3,"Three"},{4,"Four"},{5,"Five"},{6,"Six"},{7,"Seven"},{8,"Eight"},{9,"Nine"},{10,"Ten"},{11,"Eleven"},{12,"Twelve"},{13,"Thirteen"},{14,"Fourteen"},{15,"Fifteen"},{16,"Sixteen"},{17,"Seventeen"},{18,"Eighteen"},{19,"Nineteen"}};//map storing names of number that are fixed

    map<int,string>belowHundred={{2,"Twenty"},{3,"Thirty"},{4,"Forty"},{5,"Fifty"},{6,"Sixty"},{7,"Seventy"},{8,"Eighty"},{9,"Ninety"}};//this map is used to names of number at thousand place

    string solve(int num){
        if(num<20){
            return belowTwenty[num];
        }
        else if(num<100){ //ex:96
            return belowHundred[num/10]+(num%10!=0?" " + belowTwenty[num%10]:"");
        }
        else if(num<1000){//999
            return solve(num/100) + " Hundred"+(num%100!=0 ?" " + solve(num%100) :"");
        }
        else if(num<1000000){
            return solve(num/1000) + " Thousand"+((num%1000!=0) ?" " + solve(num%1000) :"");
        }
        else if(num<1000000000){
            return solve(num/1000000) + " Million"+((num%1000000!=0)? " " + solve(num%1000000) :"");
        }
        return solve(num/1000000000)+" Billion"+((num%1000000000!=0)?" "+solve(num%1000000000):"");
    }

    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        return solve(num);
    }
};
