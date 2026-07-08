class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
        return findMedianSortedArrays(nums2,nums1);

        int m=nums1.size();
        int n=nums2.size();
        int left=0;
        int right=m;
        while(left<=right){
            int i=left+(right-left)/2;
            int j=(m+n+1)/2-i;
            int Aleft;
            if(i==0){
                Aleft=INT_MIN;
            }else{
                Aleft=nums1[i-1];
            }
            int Aright;
            if(i==m){
                Aright=INT_MAX;
            }else{
                Aright=nums1[i];
            }
            int Bleft;
            if(j==0){
               Bleft=INT_MIN;
            }else{
                Bleft=nums2[j-1];
            }
            int Bright;
            if(j==n){
                Bright=INT_MAX;
            }else{
                Bright=nums2[j];
            }
            if(Aleft<=Bright && Bleft<=Aright){
                if((m+n)%2)
                return max(Aleft,Bleft);

                return(max(Aleft,Bleft)+min(Aright,Bright))/2.0;
            }else if(Aleft>Bright){
                right=i-1;
            }else{
                left=i+1;
            }
        }
        return 0;
    }
};
