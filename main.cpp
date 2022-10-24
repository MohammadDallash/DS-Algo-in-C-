void bubble_sort (vector <int> &v)
{
    int n = v.size();
    int s;
    
    for(int j = n-1; j>0; j--)
    {
        s=0;
        for(int i = 0; i<j; i++)
        {
            if (v[i] > v[i+1])
            {
                swap(v[i] , v[i+1]);
                s++;
            }
        }
        if (s==0) return;
    }
        
}

void quick_sort(vector<int> &v, int start, int end)
{
    if(start>=end) return;
    swap(v[random(start, end)],v[end]);

    int pivet  = end, p1 =start, p2 = end-1;

    while (p2>p1)
    {
        if (v[p1] <= v[pivet])p1++;
        if (v[p2] > v[pivet])p2++;
        if (v[p1] > v[pivet] && v[p2] <= v[pivet]) swap(v[p1++],v[p2--]);
    }
    if (v[p1]>v[pivet] && p1<pivet) swap(v[p1],v[pivet]);
    else p1++;

    quick_sort(v, start, p1-1); quick_sort(v, p1, end);
}



void merge_sort(vector<int> &v, int start, int end)
{
    if(start==end) return;

    int mid = (start+end)/2;
    merge_sort(v,  start,  mid);  merge_sort(v,  mid+1,  end);

    vector<int> temp(end-start+1,0);
    int p1=start, p2 = mid+1,i=0;

    fori(end-start+1)
    {
        if ((p2==end+1 || v[p1]<= v[p2] ) && p1!=mid+1)  temp[i] = v[p1++];
        else temp[i] = v[p2++];
    }

    for(int i = start; i<= end;i++ ) v[i] = temp[i-start];
}
