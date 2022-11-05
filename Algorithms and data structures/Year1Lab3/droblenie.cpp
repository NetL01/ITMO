int start = Max_Value_In_Array;
int end = Max_Number;

while(start <= end)
int mid = (start + end)/2;
int subSum = 0;
int numberOfSubArray = 1;
for(int i = 0; i < n; i++){
if(subSum + data[i] > mid){
subSum = data[i];
numberOfSubArray++;
}else{
subSum += data[i];
}
}
if(numberOfSubArray <= k)
end = mid - 1;
else
start = mid + 1;