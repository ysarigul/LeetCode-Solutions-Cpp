class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        
        for( int& i: row) //so we can change the valeu and range based for loop
            i/=2;
        
        unsigned int len =0;
        
        for( auto it = row.begin(); it!= row.end(); it+=2)
            if(*it !=*(it+1))//dereference to get value
            {
                auto toswap=find(it+2, row.end(), *it);
                iter_swap(it+1, toswap);
                ++len;
                
                
            }
        return len;
        
    }
};