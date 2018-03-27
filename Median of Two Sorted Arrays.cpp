class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int count = 0;        
        int last, now;
        int total_length = nums1.size() + nums2.size();
        vector<int>::iterator ite1 = nums1.begin();
        vector<int>::iterator ite2 = nums2.begin();
        last = ite1 == nums1.end() ? 0 : *ite1;
        now = ite2 == nums2.end() ? 0 : *ite2;
        while(ite1 != nums1.end() || ite2 != nums2.end()){                        
            if (count == total_length / 2){
                break;
            }       
            if (ite1 == nums1.end()){
                last = *ite2;
                ite2++;
                now = *ite2;
            }
            else if (ite2 == nums2.end()){
                last = *ite1;
                ite1++;
                now = *ite1;
            }                            
            else{
                last = *ite1 < *ite2 ? *(ite1++) : *(ite2++);                     
                if (ite1 == nums1. end())
                    now = *ite2;
                else if (ite2 == nums2.end())
                    now = *ite1;
                else
                    now = *ite1 < *ite2 ? *ite1 : *ite2;                        
            }
            count++;                                 
        }        
        if (count == 0)
            return ite1 == nums1.end() ? *ite2 * 1.0 : *ite1 * 1.0;
        else{
            if (total_length % 2 == 0)
                return (last + now) * 1.0 / 2;
            else
                return now * 1.0;
        }        
    }
};