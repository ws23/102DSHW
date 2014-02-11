int sumUp(int *A , int *B , int *C, int lenA, int lenB){
    int len, i;
    len = lenA>lenB?lenA:lenB;
    for(i=0;i<len;i++)
        C[i] = A[i] + B[i];
    return len;
}

int toFib(int *s, int len){
    int i;

    for(i=0;i<len;i++){
        while(s[i]>=1&&s[i+1]>=1){
            s[i+2]++;
            s[i]--;
            s[i+1]--;
        }
        if(s[i]==2){
            s[i+1]++;
            s[i] = 0;
            s[i-2]++;
        }
    }
    while(s[len]!=0)
        len++;
    return len;
}
