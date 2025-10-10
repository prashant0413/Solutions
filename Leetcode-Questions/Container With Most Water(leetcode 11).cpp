class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int MaxArea = 0;
        while (left < right)
        {
            int area = ((height[left] < height[right]) ? height[left] : height[right]) * (right - left);
            MaxArea = (area > MaxArea) ? area : MaxArea;
            (height[left] < height[right]) ? left++ : right--;
        }
        return MaxArea;
    }
};
