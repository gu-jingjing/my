#define _CRT_SECURE_NO_WARNINGS 1

//����189. ��ת����
void rotate(int* nums, int numsSize, int k)
{
    k %= numsSize;

    if (k == 0)
    {
        return;
    }

    int tmp[k];

    for (int i = 0; i < k; i++)
    {
        tmp[i] = nums[numsSize - k + i];
    }

    int j = numsSize - 1;

    for (int i = numsSize - k - 1; i >= 0; i--)
    {
        nums[j] = nums[i];
        j--;
    }

    for (int i = 0; i < k; i++)
    {
        nums[i] = tmp[i];
    }
}

//���������� 17.04. ��ʧ������
int missingNumber(int* nums, int numsSize)
{
    int k = 0;
    for (int i = 0; i < numsSize; i++)
    {
        k ^= nums[i];
    }

    for (int i = 0; i <= numsSize; i++)
    {
        k ^= i;
    }

    return k;
}
