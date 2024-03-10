

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Tracer{
public:
	int minIndex;
	int maxIndex;
	Tracer(){
		minIndex = INT_MAX;
		maxIndex = -1;
	}
};

Tracer tracer[26];

//let's say text length = m

int solve(string text){

	for(int i=0; i<text.size(); i++){
		int now = text[i] - 'a';
		tracer[now].minIndex = min(tracer[now].minIndex, i);
		tracer[now].maxIndex = max(tracer[now].maxIndex, i);
	} //O(m)

	int maxDistance = -1;
	int starting, ending;

	for(int i=0; i<26; i++){
        //26 * O(m)
		if(tracer[i].minIndex != INT_MAX && tracer[i].maxIndex != -1 && tracer[i].minIndex != tracer[i].maxIndex){

            int curDistance = tracer[i].maxIndex - tracer[i].minIndex + 1;
            int curS = tracer[i].minIndex;
            int curE = tracer[i].maxIndex;

            for(int k=curS+1, l=curE+1; k<curE-1 && l<text.size(); k++, l++){
                if(text[k]==text[l]){
                    curDistance++;
                }
            }
            //asfasdflaskdjf;lksjdf;lkasjf;lkjsd;fkl

            //cout<<curDistance<<", "<<curS<<", "<<curE<<", "<<text[curS]<<endl;

            if(maxDistance < curDistance){
                maxDistance = curDistance;
                starting = curS;
                ending = curE;
            }

		}
	}

	//todo try to match prefix and suffix

	//total O(M) + 26*O(M) --> O(M) + O(M)

	cout<<starting<<", "<<ending<<endl;
    string U = "";
	 for(int k=starting, l=ending; k<ending-1 && l<text.size(); k++, l++){
        if(text[k]==text[l]){
           U+= text[k];
        }
    }

    cout<<"Calculated U: "<<U<<endl;

	return maxDistance;

}


int main()
{
	string text;
	text = "kiwibananaban";
	text = "bzaxzaxvvzaxzaxvbczeybzaxvvvvvvvvvvvvvvvvvzaxv";
	text = "assaaaaaaaaaaaaaaaaaaaaaaaaaaab";

	cout<<"MaxDistance: "<<solve(text)<<endl;


}
