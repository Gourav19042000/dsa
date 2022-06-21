class Solution {
public:
    // int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    //    //my first idea!!we ca place ladder in all positions and cheak how much can we go with ladder and brick!!
    //   //then i saw a glimplse at discussion where riority queue is written with bold latter!!...so lets not waste time in my more complexit idea and start pq!  
    //    priority_queue<int,vector<int> ,greater<int>> pq;
    //     int count=1;
    //     int n=heights.size();
    //     for(int i=1;i<n;i++){
    //         if(heights[i]>heights[i-1]){
    //             pq.push(heights[i]-heights[i-1]);
    //         }
    //         else{
    //             count++;
    //         }
    //     }
    //     for(int i=0;i<n;i++)
    //     while(!pq.empty() && bricks>=0){
    //         int temp=pq.top();
    //         pq.pop();
    //         bricks-=temp;
    //         count++;
    //     }
    //     return count;
   // }
int furthestBuilding(vector<int>& H, int bricks, int ladders) {
	priority_queue<int,vector<int>,greater<int>> pq;
	int n = size(H), i = 0, jumpHeight = 0;
	for(; i < n - 1; i++) {
		jumpHeight = H[i + 1] - H[i];
		if(jumpHeight <= 0) continue;
		pq.push(jumpHeight); // notice the '-'
		if(size(pq) > ladders) 
			bricks -= pq.top(), pq.pop();
		if(bricks < 0) return i;
	}
	return i;
}

};