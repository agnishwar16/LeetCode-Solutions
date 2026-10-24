class Solution {
public:
    int convert(string date){
        int days[] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};

        int day=stoi(date.substr(3,2));
        int month=stoi(date.substr(0,2));
        int total=day;
        for(int i=0;i<month-1;i++){
            total+=days[i];
        }
        return total;



    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        int astart= convert(arriveAlice);
        int aleave= convert(leaveAlice);
        int bstart=convert(arriveBob);
        int bleave=convert(leaveBob);

        int start=max(astart,bstart);
        int end = min(aleave,bleave);

        if(start>end){
            return 0;
        }
        return end-start+1;

    }
};