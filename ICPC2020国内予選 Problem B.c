#include <stdio.h>
#include <string.h>

int main(void)
{
    int m, n, p;
    int a, b;
    int o[1000];
    int i;
    
    while (1){

        scanf("%d%d%d", &m, &n, &p);
        if (m == 0 && n == 0 && p == 0){
            break;
        }
        
        memset(o, 0, sizeof(o));
        
        o[p] = 1;
        for (i = 0; i < n; i++){
            scanf("%d%d", &a, &b);
            o[a] |= o[b];
            o[b] |= o[a];
        }
        
        int ans = 0;
        for (i = 0; i <= m; i++){
            ans += o[i];
        }
        
        printf("Output for the Sample Input\n%d\n", ans);
    }
    
    return 0;
}
