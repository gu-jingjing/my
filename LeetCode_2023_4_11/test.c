#define _CRT_SECURE_NO_WARNINGS 1

//27. 移除元素
int removeElement(int* nums, int numsSize, int val)
{
    int i = 0;
    int j = 0;
    int count = 0;

    while (i < numsSize && nums[i] != val)
    {
        i++;
        j++;
    }

    while (j < numsSize)
    {
        //j指向下一个不为val的位置，以期将其赋值给i的位置
        while (j < numsSize && nums[j] == val)
        {
            j++;
            count++;
        }
        while (j < numsSize && nums[j] != val)
        {
            nums[i] = nums[j];
            i++;
            j++;
        }
    }
    numsSize -= count;
    return numsSize;
}

//88. 合并两个有序数组
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int tmp[200] = { 0 };

    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            tmp[k] = nums1[i];
            k++;
            i++;
        }
        else
        {
            tmp[k] = nums2[j];
            k++;
            j++;
        }
    }
    while (i < m)
    {
        tmp[k] = nums1[i];
        k++;
        i++;
    }
    while (j < n)
    {
        tmp[k] = nums2[j];
        k++;
        j++;
    }

    for (i = 0; i < m + n; i++)
    {
        nums1[i] = tmp[i];
    }
}