#define _CRT_SECURE_NO_WARNINGS 1

//26. ɾ�����������е��ظ���
int removeDuplicates(int* nums, int numsSize)
{
    int i = 1;
    int j = 1;

    if (numsSize == 1)
    {
        return 1;
    }

    while (i < numsSize && nums[i - 1] != nums[i])
    {
        i++;
        j++;
    }

    while (j < numsSize)
    {
        while (j < numsSize && nums[j - 1] == nums[j])
        {
            j++;
        }

        if (j < numsSize)
        {
            //��ֵ
            nums[i] = nums[j];
            i++;
            j++;
        }


    }
    return i;
}