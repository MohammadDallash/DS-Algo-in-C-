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
