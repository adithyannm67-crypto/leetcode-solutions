class Solution:
    def median1(self,nums1: list[int], k1: int) -> float:
        print(nums1)
        if(len(nums1)==1):
            return nums1[0]
        if len(nums1)==0:
            return 0
        if len(nums1) % 2 == 0:
            med1 = (nums1[k1 - 1] + nums1[k1]) / 2
        else:
            med1 = nums1[k1]

        return med1

    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        len1 = len(nums1)
        len2 = len(nums2)
        med1 = med2 = 0

        # k1 = int(len1 / 2)
        # k2 = int(len2 / 2)

        # med1 = self.median1(nums1, k1)
        # med2 = self.median1(nums2, k2)

        # return median([med1,med2],2)

        i=j=0

        merged=[]

        while i<len1 and j<len2:
            
            if nums1[i]<=nums2[j]:
                merged.append(nums1[i])
                i=i+1

            elif nums1[i]>nums2[j]:
                merged.append(nums2[j])
                j=j+1
         
        while i<len1 :
            merged.append(nums1[i])
            i=i+1
        while j<len2:
            merged.append(nums2[j])
            j=j+1

        print(len1+len2," ",len(merged))
        return self.median1(merged,len(merged)//2)


