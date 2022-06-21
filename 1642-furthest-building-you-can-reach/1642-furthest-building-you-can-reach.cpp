class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
       //my first idea!!we ca place ladder in all positions and cheak how much can we go with ladder and brick!!
      //then i saw a glimplse at discussion where riority queue is written with bold latter!!...so lets not waste time in my more complexit idea and start pq!  
       priority_queue<int,vector<int> ,greater<int>> pq;
        int n=heights.size();
        int sum=0,i=0;
      for( i=1;i<n;i++){
          if(heights[i]-heights[i-1]>0)sum=heights[i]-heights[i-1];
          else continue;
          pq.push(sum);
          if(pq.size()>ladders){
              bricks-=pq.top();
              pq.pop();
          }
          if(bricks<0)return i-1;
      }
        return i-1;
   }

};