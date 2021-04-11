// Problem Link - https://www.codechef.com/NOV18B/problems/HMAPPY1    Name - Appy Loves One
#include <bits/stdc++.h>
using namespace std;

int max0(int a, int b, int c)
{
    return max(max(a, b), c);
}

void appy1(vector<int> arr, int k, string query)
{

    int max1 = 0, max2 = 0, max_join, flag4 = 0, flag = 0, flag1 = 0, flag2 = 0, index, flag_zero = 0, flag_one = 0,
        end_right = -1, end_left = -1, second_max_b = -1, second_max_e = -1;

    int sib = -1, sie = -1, temps = -1;

    if (arr[0] == 1 && arr[arr.size() - 1] == 1)
    {
        flag = 1;
        for (int i = 0; arr[i] != 0 && i < arr.size(); i++)
            end_left = i;
        for (int i = arr.size() - 1; arr[i] != 0 && i >= 0; i--)
            end_right = i;
    }
    int count = 1, arr_size = arr.size();
    if (end_left == arr_size - 1)
        flag_one = 1;

    // end_right = arr_size - end_right-1;
    if (arr[0])
        flag_zero = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            flag_zero = 1;
            index = i;
        }
        if (arr[i] == 1 && arr[i - 1] == 1)
        {
            if (count == 1)
                temps = i;
            count++;
            if (i == arr_size - 1)
            {
                if (max1 < count)
                {
                    sib = temps - 1;
                    sie = i;
                    max1 = count;
                }
            }
            flag1 = 1;
        }
        else
        {
            if (max1 < count)
            {
                sib = temps - 1;
                sie = i - 1;
                max1 = count;
            }
            count = 1;
        }
    }

    if (flag1 == 0 && flag_zero)
    {
        sib = sie = index;
    }
    flag1 = 0;
    count = 1;
    temps = -1;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == 1 && arr[i - 1] == 1)
        {
            if (count == 1)
                temps = i;
            count++;
            if (i == arr_size - 1)
            {
                if (max2 < count && (temps - 1) != sib)
                {
                    second_max_b = temps - 1;
                    second_max_e = i;
                    max2 = count;
                }
            }
            flag1 = 1;
        }
        else
        {
            if (max2 < count && (temps - 1) != sib)
            {
                second_max_b = temps - 1;
                second_max_e = i - 1;
                max2 = count;
                flag2 = 1;
            }
            count = 1;
        }
    }

    if (second_max_b < 0)
        flag4 = 1;
    if (flag4 == 1 || (flag1 == 0 && flag_zero))
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (i >= sib && i <= sie)
                continue;
            if (arr[i] == 1)
            {
                max2 = 1;
                break;
            }
            else
                max2 = 0;
        }
    }
    max_join = end_right + end_left;
    count = 0;
    int chk1, chk2, max_len = max1;
    if (flag == 1)
    {
        for (int i = 0; i < query.size(); i++)
        {
            if (query[i] == '!')
            {

                end_left = (end_left + 1) % arr_size;
                end_right = (end_right + 1) % arr_size;
                sie = (sie + 1) % arr_size;
                sib = (sib + 1) % arr_size;
                second_max_b = (second_max_b + 1) % arr_size;
                second_max_e = (second_max_e + 1) % arr_size;
                if (end_right > end_left)
                    max_join = max(end_left + 1, arr_size - end_right);
                else
                    max_join = end_left - end_right + 1;
                // cout<<max_join<<" "<<end_right<<" "<<end_left<<endl;

                if (sie < sib)
                    chk1 = max(sie + 1, arr_size - sib);
                else
                    chk1 = sie - sib + 1;

                if (second_max_e < second_max_b)
                    chk2 = max(second_max_e + 1, arr_size - second_max_b);
                else
                    chk2 = second_max_e - second_max_b + 1;

                if (flag4 == 1)
                    chk2 = max2;
                if (flag1)
                    max_len = max0(chk1, chk2, max_join);
                else
                    max_len = max_join;
            }
            else
            {
                if (flag_one)
                {
                    cout << arr_size << endl;
                    continue;
                }
                if (max_len < k)
                    cout << max_len << endl;
                else
                    cout << k << endl;
            }
        }
    }
    else
    {
        for (int i = 0; i < query.size(); i++)
        {

            if (query[i] == '!')
            {

                sie = (sie + 1) % arr_size;
                sib = (sib + 1) % arr_size;
                second_max_b = (second_max_b + 1) % arr_size;
                second_max_e = (second_max_e + 1) % arr_size;
                if (sie < sib)
                    chk1 = max(sie + 1, arr_size - sib);
                else
                    chk1 = sie - sib + 1;

                if (second_max_e < second_max_b)
                    chk2 = max(second_max_e + 1, arr_size - second_max_b);
                else
                    chk2 = second_max_e - second_max_b + 1;

                if (flag4 == 1)
                    chk2 = 0;

                max_len = max(chk1, chk2);
            }
            else
            {
                if (flag_zero == 0)
                {
                    cout << "0" << endl;
                    continue;
                }
                if (max_len < k)
                    cout << max_len << endl;
                else
                    cout << k << endl;
            }
        }
    }
}

void appy(vector<int> arr, int k, string query)
{

    int n = arr.size(), j, temp_max_b = -1, left_index = -1, right_index = -1, first_max = 0, first_max_b = -1,
        first_max_e = -1, second_max = 0, second_max_b = -1, second_max_e = -1;

    if (arr[0] == 1 && arr[n - 1] == 1)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 1)
                left_index = i;
            else
                break;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] == 1)
                right_index = i;
            else
                break;
        }
    }

    int max_join = left_index + 1 + n - right_index;

    if (left_index < 0)
        max_join = 0;

    int count = 1;
    int i = 0;
    while (i < n)
    {

        if (arr[i] == 1)
        {
            temp_max_b = i;
            for (j = i + 1; j < n; j++)
            {
                if (arr[j] == 1)
                {
                    count++;
                }
                else
                    break;
            }
            if (first_max < count)
            {
                first_max = count;
                first_max_b = temp_max_b;
                first_max_e = j - 1;
            }
            count = 1;
            i = j;
        }
        i++;
    } // for finding the first maximum
    count = 1, i = 0;

    while (i < n)
    {

        if (arr[i] == 1)
        {
            temp_max_b = i;
            for (j = i + 1; j < n; j++)
            {
                if (arr[j] == 1)
                {
                    count++;
                }
                else
                    break;
            }
            if ((second_max < count) && (temp_max_b != first_max_b))
            { // initialise first and second max so that you can determine if they are 0
                second_max = count;
                second_max_b = temp_max_b;
                second_max_e = j - 1;
            }
            count = 1;
            i = j;
        }
        i++;
    }

    int chk1, chk2, chk3, max_len = first_max;

    for (i = 0; i < query.size(); i++)
    {

        if (query[i] == '!')
        {

            left_index = (left_index + 1) % n;
            right_index = (right_index + 1) % n;
            first_max_b = (first_max_b + 1) % n;
            first_max_e = (first_max_e + 1) % n;
            second_max_b = (second_max_b + 1) % n;
            second_max_e = (second_max_e + 1) % n;

            if (right_index <= left_index)
                chk1 = max_join;
            else
            {
                chk1 = max((left_index + 1), (max_join - (left_index + 1)));
            }

            if (first_max_e <= first_max_b)
                chk2 = max((first_max_e + 1), first_max - (first_max_e + 1));
            else
                chk2 = first_max;

            if (second_max_e <= second_max_b)
                chk3 = max((second_max_e + 1), second_max - (second_max_e + 1));
            else
                chk3 = second_max;

            max_len = max0(chk1, chk2, chk3);
        }
        else
        {
            if (max_len < k)
                cout << max_len << endl;
            else
                cout << k << endl;
        }
    }
}

int main()
{
    int n, q, k;
    string query;
    cin >> n >> q >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> query;

    if (arr[0] == 1)
        appy(arr, k, query);
    else
        appy1(arr, k, query);

    return 0;
}