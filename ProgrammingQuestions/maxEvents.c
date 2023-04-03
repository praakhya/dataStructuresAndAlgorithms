int  maxEvents(int* eventPtrs,int eventSize,int* eventsColSize)
{
  return eventSize;
}
int main(){
    int events[1000][2];
    int* eventPtrs[1000];
    int eventSize = 0;
    int eventsColSize = 2;
    int count = 0;

    scanf("%d",&eventSize);
    while(count <eventSize && scanf("%d %d", &events[count][0],&events[count][1]) == 2){
        eventPtrs[count] = events[count];
        count++;
    }

    int maxAttended = maxEvents(eventPtrs,eventSize,&eventsColSize);
    printf("%d",maxAttended);
    return 0;

}