#include <iostream>
#include <algorithm>
using namespace std;

struct point
{
   int x, y;
   bool equals(point p)
   {
      return x == p.x && y == p.y;
   }
   point(int xx, int yy) : x(xx), y(yy) {}
};

struct line
{
   point p1, p2;
   line(point a, point b) : p1(a), p2(b) {}
   line(int a, int b, int c, int d) : p1(point(a,b)), p2(point(c,d)) {}
};

// To find orientation of ordered triplet (p1, p2, p3). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(point p1, point p2, point p3)
{
   int val = (p2.y - p1.y) * (p3.x - p2.x) -
      (p2.x - p1.x) * (p3.y - p2.y);

   if (val == 0) return 0;  // colinear 

   return (val > 0) ? 1 : 2; // clock or counterclock wise 
}

// Given three colinear points p, q, r, the function checks if 
// point q lies on line segment 'pr' 
bool onSegment(point p, point q, point r)
{
   if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
      q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
      return true;

   return false;
}

bool intersect(line l1, line l2) {
   point p1 = l1.p1, q1 = l1.p2, p2 = l2.p1, q2 = l2.p2;
   int o1 = orientation(p1, q1, p2);
   int o2 = orientation(p1, q1, q2);
   int o3 = orientation(p2, q2, p1);
   int o4 = orientation(p2, q2, q1);

   if (o1 != o2 && o3 != o4) return true; // general

   // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
   if (o1 == 0 && onSegment(p1, p2, q1)) return true;

   // p1, q1 and q2 are colinear and q2 lies on segment p1q1 
   if (o2 == 0 && onSegment(p1, q2, q1)) return true;

   // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
   if (o3 == 0 && onSegment(p2, p1, q2)) return true;

   // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
   if (o4 == 0 && onSegment(p2, q1, q2)) return true;

   return false;
}

bool isInside(point polygon[], int n, point p)
{
   // There must be at least 3 vertices in polygon[] 
   if (n < 3)  return false;

   // Create a point for line segment from p to infinite 
   point extreme = { INT_MAX, p.y };

   // Count intersections of the above line with sides of polygon 
   int count = 0, i = 0;
   do
   {
      int next = (i + 1) % n;

      // Check if the line segment from 'p' to 'extreme' intersects 
      // with the line segment from 'polygon[i]' to 'polygon[next]' 
      if (intersect(line(polygon[i], polygon[next]), line(p, extreme)))
      {
         // If the point 'p' is colinear with line segment 'i-next', 
         // then check if it lies on segment. If it lies, return true, 
         // otherwise false 
         if (orientation(polygon[i], p, polygon[next]) == 0)
            return onSegment(polygon[i], p, polygon[next]);

         count++;
      }
      i = next;
   } while (i != 0);

   // Return true if count is odd, false otherwise 
   return count & 1;  // Same as (count%2 == 1) 
}

vector<point> ch_jarvis(const vector<point>& input)
{
   int left = 0;
   for (int i = 1; i < input.size(); i++)
   {
      if (input[i].x < input[left].x) left = i;
      else if (input[i].x == input[left].x && input[i].y < input[left].y)
         left = i;
   }

   int cur = left;
   vector<point> ans;
   do
   {
      ans.push_back(input[cur]);
      int next = (cur + 1) % input.size();
      for (int i = 0; i < input.size(); i++)
      {
         int dir = orientation(input[cur], input[i], input[next]);
         if (dir == 2)
            next = i;
         else if (dir == 0)
         {
            if (input[cur].distance2(input[i]) > input[cur].distance2(input[next]))
               next = i;
         }
      }
      cur = next;
   } while (cur != left);
   return ans;
}

// calculate area
double area(const vector<point>& t) {
   double ddarea = 0.0;
   int j = t.size() - 1;
   for (int i = 0; i < t.size(); i++) {
      ddarea += (t[j].x + t[i].x) * (t[j].y - t[i].y);
      j = i;
   }
   return abs(ddarea);
}
int main()
{
    





    
}