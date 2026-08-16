class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int count_1 = 0;
        int count_2 = 0;

        for(int i = 0; i < arr.size(); i++) {
            count_1 = 0;

            for(int j = 0; j < arr.size(); j++) {
                if(arr[i] == arr[j]) {
                    count_1++;
                }
            }

            // Check whether this occurrence count
            // is same as occurrence count of another number
            for(int k = 0; k < i; k++) {
                count_2 = 0;

                for(int l = 0; l < arr.size(); l++) {
                    if(arr[k] == arr[l]) {
                        count_2++;
                    }
                }

                if(arr[i] != arr[k] && count_1 == count_2) {
                    return false;
                }
            }
        }

        return true;
    }
};