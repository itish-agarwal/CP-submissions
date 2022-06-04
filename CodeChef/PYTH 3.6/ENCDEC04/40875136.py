
def sumOfLastDig(n, m) :  
  
    sum = 0;
    k = n // m; 
      
    # Array to store the last digit 
    # of elements in a cycle 
    arr = [0] * 10;  
  
    # Storing and adding last  
    # digit of cycle  
    for i in range(10) : 
        arr[i] = m * (i + 1) % 10;  
        sum += arr[i];  
  
    # Number of elements  
    # present in last cycle  
    rem = k % 10;  
  
    # Sum of k/10 cycle  
    ans = (k // 10) * sum;  
  
    # Adding value of digits  
    # of last cycle
    for i in range(rem) : 
        ans += arr[i];  
  
    return ans;  
  
# Driver Code  
if __name__ == "__main__" :  
  
    t = int(input());

    for x in range (t):
        inp = list(map(int,input().split()));n=inp[0];m=inp[1];print(sumOfLastDig(n, m));
    
    
    
    